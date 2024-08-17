/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:18:19 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/17 18:27:24 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char *name, char **env)
{
	size_t	i;
	size_t	name_len;

	name_len = ft_strlen(name);
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(name, env[i], name_len))
			return (&env[i][name_len + 1]);
		i++;
	}
	return (NULL);
}