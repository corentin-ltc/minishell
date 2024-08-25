/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 23:35:58 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/25 19:25:48 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_istoken(int c)
{
	return (c == '\0'
		|| c == '<' || c == '>'
		|| c == '"' || c == '\''
		|| ft_isspace(c));
}

int	ft_isfile_limiter(int c)
{
	return (c == '\0'
		|| c == '<' || c == '>'
		|| ft_isspace(c));
}

char	*get_filename(char *str, t_parser parser)
{
	char		*name;
	size_t		i;
	size_t		j;

	name = calloc(ft_strlen(str), sizeof(char));
	if (!name)
		return (NULL);
	i = 0;
	j = 0;
	while (ft_isspace(str[i]))
		parse_str(&parser, str, &i);
	while (parser.quotes || !ft_isfile_limiter(str[i]))
	{
		if ((parser.quotes || !ft_istoken(str[i]))
			&& !(parser.d_quotes && str[i] == '"'
				|| parser.s_quotes && str[i] == '\''))
		{
			name[j] = str[i];
			j++;
		}
		parse_str(&parser, str, &i);
	}
	return (name);
}

size_t	count_quotes(char *str)
{
	t_parser	parser;
	size_t		count;
	size_t		i;

	parser = new_parser();
	count = 0;
	i = 0;
	while (update_parser(&parser, str[i]))
	{
		if (!parser.quotes && (str[i] == '\'' || str[i] == '"'))
			count++;
		else if (parser.d_quotes && str[i] == '"')
			count++;
		else if (parser.s_quotes && str[i] == '\'')
			count++;
		i++;
	}
	return (count);
}

bool	empty_pipes(char *str)
{
	t_parser	parser;
	size_t		start;
	size_t		i;

	i = 0;
	while (update_parser(&parser, str[i]))
	{
		while (str[i] && (parser.quotes || str[i] != '|'))
			parse_str(&parser, str, &i);
		if (str[i] == '\0')
			break ;
		if (str[i] == '|')
			i++;
		while (isspace(str[i]))
			parse_str(&parser, str, &i);
		if (str[i] == '|')
			return (true);
		i++;
	}
	return (false);
}

bool	triple_redirection(char *str)
{
	t_parser	parser;
	size_t		start;
	size_t		i;

	i = 0;
	while (update_parser(&parser, str[i]))
	{
		while (str[i] && (parser.quotes || (str[i] != '<' && str[i] != '>')))
			parse_str(&parser, str, &i);
		if (str[i] == '\0')
			break ;
		if (str[i] == str[i + 1])
			i += 2;
		else
			i += 1;
		while (isspace(str[i]))
			parse_str(&parser, str, &i);
		if (ft_isfile_limiter(str[i]))
			return (true);
		i++;
	}
	return (false);
}