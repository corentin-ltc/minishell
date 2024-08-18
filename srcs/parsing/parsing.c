/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:11:32 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/18 19:38:16 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_cmds(t_data *data)
{
	char	**cmds;
	size_t	i;

	cmds = ft_split(data->line, ("|"));
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

void	get_vars(t_data *data, t_cmd *cmd)
{
	char	*name;
	char	*new;
	char	*value;
	int		index;
	size_t	len;

	//recupere l'index du dollar
	index = get_varindex(cmd->line);
	while (index >= 0)
	{
		//recupere la taille
		len = 0;
		while (ft_isalnum(cmd->line[index + 1 + len]))
			len++;
		//recupere la valeur
		name = ft_substr(cmd->line, index + 1, len);
		if (!name)
			exit(1);
		value = ft_getenv(name, data->env);
		new = calloc(ft_strlen(cmd->line) - len + ft_strlen(value), sizeof(char));
		if (!new)
			exit(1);
		ft_strlcat(new, cmd->line, index + 1);
		if (len)
			ft_strcat(new, value);
		else
			ft_strcat(new, "$");
		ft_strcat(new, &cmd->line[index + 1 + len ]);
		free(cmd->line);
		cmd->line = new;
		index = get_varindex(cmd->line);
	}
}