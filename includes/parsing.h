/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:48:54 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/19 22:51:43 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/*split*/
size_t		ft_countwords_noquotes(char *s, char *set);
char		**ft_minisplit(char **dest, char *src, char *set, t_parser parser);
char		**ft_split_noquotes(char *s, char *set);
/*cmds*/
void		get_cmds(t_data *data);
/*vars*/
void		get_vars(t_data *data);
/*infiles*/
void		get_infiles(t_data *data);
/*parsers*/
t_parser	new_parser(void);
void		*update_parser(t_parser *parser, char c);
void		*parse_str(t_parser *parser, char *str, size_t	*i);
void		show_parser(t_parser parser);

#endif