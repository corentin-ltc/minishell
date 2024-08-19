/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:48:54 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/19 16:39:52 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/*split*/
size_t		ft_countwords_noquotes(char *s, char sep);

char		**ft_minisplit(char **dest, char *src, char sep, t_parser parser);

char		**ft_split_noquotes(char *s, char sep);
/*cmds*/
void		get_cmds(t_data *data);
/*vars*/
void		get_vars(t_data *data);
/*parsers*/
t_parser	new_parser(void);

void		*update_parser(t_parser *parser, char c);

void		show_parser(t_parser parser);

#endif