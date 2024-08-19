/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:30:21 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/19 22:37:28 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parser	new_parser(void)
{
	t_parser	parser;

	parser.d_quotes = false;
	parser.s_quotes = false;
	parser.infile = false;
	parser.set = NULL;
	return (parser);
}

void	*update_parser(t_parser *parser, char c)
{
	if (c == '"')
	{
		if (parser->d_quotes == true)
			parser->d_quotes = false;
		else if (parser->s_quotes == false)
			(parser->d_quotes = true);
	}
	else if (c == '\'')
	{
		if (parser->s_quotes == true)
			parser->s_quotes = false;
		else if (parser->d_quotes == false)
			parser->s_quotes = true;
	}
	if (!c)
		return (NULL);
	return (parser);
}

void	*parse_str(t_parser *parser, char *str, size_t	*i)
{
	if (str[*i] == '\0')
		return (NULL);
	// printf("-----------\n");
	// printf("parsed str : %s\n", &str[*i]);
	if (str[*i] == '<')
	{
		if (str[*i + 1] == '<')
		{
			parser->here_doc = true;
			parser->infile = false;
			*i += 1;
		}
		else
		{
			parser->infile = true;
			parser->here_doc = false;
		}
	}
	*i += 1;
	// 	if (parser->infile)
	// 	ft_putstr("infile : true\n");
	// else
	// 	ft_putstr("infile : false\n");
	// if (parser->here_doc)
	// 	ft_putstr("here_doc : true\n");
	// else
	// 	ft_putstr("here_doc : false\n");
	// printf("-----------\n");
	return (str);
}

void	show_parser(t_parser parser)
{
	if (parser.d_quotes)
		ft_putstr("double quotes : true\n");
	else
		ft_putstr("double quotes : false\n");
	if (parser.s_quotes)
		ft_putstr("simple quotes : true\n");
	else
		ft_putstr("simple quotes : false\n");
}
