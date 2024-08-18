/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:11:32 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/18 17:09:03 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_cmds(t_data *data)
{
	char	**cmds;
	size_t	i;

	cmds = ft_split(data->line, ("|"));
	ft_putarr(cmds);
	if (!cmds)
		exit_error("An allocation failed", data);
	data->cmds = ft_calloc(ft_countwords(data->line, "|") + 1, sizeof(t_cmd *));
	if (!data->cmds)
	{
		free(cmds);
		exit_error("An allocation failed", data);
	}
	i = 0;
	while (cmds[i])
	{
		data->cmds[i] = init_cmd(cmds[i]);
		i++;
	}
	free(cmds);
}

void	get_vars(t_data *data)
{
	char	*name;
	size_t	i;

	i = 0;
	while (data->cmds[i])
	{
		get_varname(data->cmds[i]->line);
		i++;
	}
}