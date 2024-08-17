/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:28:07 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/17 19:19:39 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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