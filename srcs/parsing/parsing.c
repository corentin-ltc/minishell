/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:11:32 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/18 20:54:14 by nbellila         ###   ########.fr       */
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

static char	*get_varname(t_data *data, char *line)
{
	char	*name;
	size_t	len;

	len = 0;
	while (ft_isalnum(line[len]))
		len++;
	name = ft_substr(line, 0, len);
	if (!name)
		exit_error("Name alloc failed", data);
	return (name);
}

static void	*get_newcmd(t_cmd *cmd, size_t index, char *value, char *name)
{
	char	*new;
	size_t	len;

	len = 0;
	while (ft_isalnum(name[len]))
		len++;
	new = calloc(ft_strlen(cmd->line) - len + ft_strlen(value), sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcat(new, cmd->line, index + 1);
	if (len)
		ft_strcat(new, value);
	else
		ft_strcat(new, "$");
	ft_strcat(new, &cmd->line[index + 1 + len]);
	free(cmd->line);
	cmd->line = new;
	return (new);
}

void	get_vars(t_data *data)
{
	size_t	i;
	char	*name;
	char	*value;
	int		index;

	i = 0;
	while (data->cmds[i])
	{
		index = get_varindex(data->cmds[i]->line);
		while (index >= 0)
		{
			name = get_varname(data, &data->cmds[i]->line[index + 1]);
			value = ft_getenv(name, data->env);
			if (!get_newcmd(data->cmds[i], index, value, name))
			{
				free(name);
				exit_error("An allocation failed", data);
			}
			free(name);
			index = get_varindex(data->cmds[i]->line);
		}
		i++;
	}
}
