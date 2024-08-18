/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:48:54 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/18 18:50:05 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/*functions*/
void	get_cmds(t_data *data);

void	get_vars(t_data *data, t_cmd *cmd);

t_cmd	*init_cmd(char *line);

int		get_varindex(char *line);

#endif