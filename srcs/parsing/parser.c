/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:30:21 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/18 19:43:30 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parser	new_parser(void)
{
	t_parser	parser;

	parser.d_quotes = false;
	parser.s_quotes = false;
	return (parser);
}

void	update_parser(t_parser *parser, char c)
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