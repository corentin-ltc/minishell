/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:28:07 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/17 19:18:19 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_setenv(char *name, char *value, char ***env)
{
	char	*str;
	size_t	i;

	str = ft_strjoin_sep(name, value, "=");
	if (!str)
		return (NULL);
	i = 0;
	while (env[0][i])
	{
		if (!ft_strncmp(name, env[0][i], ft_strlen(name)))
			if (!ft_remove_index(env, i))
			{
				free(str);
				return (NULL);
			}
		i++;
	}
	if (!ft_arradd(env, str))
	{
		free(str);
		return (NULL);
	}
	return (str);
}


void	ft_export(char **argv, char ***env)
{
	size_t	i;
	size_t	name_len;

	i = 1;
	while (argv[i])
	{
		name_len = 0;
		while (argv[i][name_len] && argv[i][name_len] != '=')
			name_len++;
		argv[i][name_len] = '\0';
		if (name_len != 0 || name_len != ft_strlen(argv[i]))
		{
			if (!ft_setenv(argv[i], &argv[i][name_len + 1], env))
				//todo: free & exit
				exit(EXIT_FAILURE);
		}
		i++;
	}
}