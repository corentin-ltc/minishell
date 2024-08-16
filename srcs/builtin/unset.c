/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:28:07 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/16 22:18:44 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	ft_unset(char **argv, char ***env)
{
	size_t	i_arg;
	size_t	i_env;

	i_arg = 1;
	while (argv[i_arg])
	{
		i_env = 0;
		while (env[0][i_env])
		{
			if (!ft_strncmp(argv[i_arg], env[0][i_env], ft_strlen(argv[i_arg])))
				if (!ft_remove_index(env, i_env))
					exit(EXIT_FAILURE);
				else
					break ;
			i_env++;
		}
		i_arg++;
	}
}