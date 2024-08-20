/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:01:24 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/19 18:57:06 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

/*functions*/
void	init_data(t_data *data, char **env);

void	show_data(t_data data);

void	minishell_loop(t_data *data);

void	set_signals(void);

#endif