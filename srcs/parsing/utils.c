/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 23:35:58 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/26 01:33:26 by nabil            ###   ########.fr       */
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

	name = calloc(ft_strlen(str) + 1, sizeof(char));
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
