/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:34:17 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/19 18:54:08 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_varindex(char *line)
{
	t_parser	parser;
	size_t		i;

	parser = new_parser();
	i = 0;
	while (line[i])
	{
		update_parser(&parser, line[i]);
		if (!parser.s_quotes && line[i] == '$' && ft_isalnum(line[i + 1]))
			return (i);
		i++;
	}
	return (-42);
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

static void	*get_newline(t_data *data, size_t index, char *value, char *name)
{
	char	*new;
	size_t	len;

	len = 0;
	while (ft_isalnum(name[len]))
		len++;
	new = calloc(ft_strlen(data->line) - len + ft_strlen(value), sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcat(new, data->line, index + 1);
	if (len)
		ft_strcat(new, value);
	else
		ft_strcat(new, "$");
	ft_strcat(new, &data->line[index + 1 + len]);
	free(data->line);
	data->line = new;
	return (new);
}

void	get_vars(t_data *data)
{
	size_t	i;
	char	*name;
	char	*value;
	int		index;

	index = get_varindex(data->line);
	while (index >= 0)
	{
		name = get_varname(data, &data->line[index + 1]);
		value = ft_getenv(name, data->env);
		if (!get_newline(data, index, value, name))
		{
			free(name);
			exit_error("An allocation failed", data);
		}
		free(name);
		index = get_varindex(data->line);
	}
}
