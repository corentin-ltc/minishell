/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:48:54 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/18 19:36:41 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/*functions*/
t_parser	new_parser(void);

void		update_parser(t_parser *parser, char c);

void		show_parser(t_parser parser);

void		get_cmds(t_data *data);

void		get_vars(t_data *data, t_cmd *cmd);

t_cmd		*init_cmd(char *line);

int			get_varindex(char *line);

#endif