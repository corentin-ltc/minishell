/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:28:07 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/16 23:10:46 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	ft_export(char **argv, char ***env)
{
	size_t	i_arg;
	size_t	i_env;
	size_t	i_equal;

	i_arg = 1;
	while (argv[i_arg])
	{
		i_equal = 0;
		while (argv[i_arg][i_equal] && argv[i_arg][i_equal] != '=')
			i_equal++;
		if (i_equal && argv[i_arg][i_equal] && argv[i_arg][i_equal + 1] != '=')
		{
			i_env = 0;
			while (env[0][i_env])
			{
				if (!ft_strncmp(argv[i_arg], env[0][i_env], i_equal))
					if (!ft_remove_index(env, i_env))
						exit(EXIT_FAILURE);
				i_env++;
			}
			if (!ft_arradd(env, argv[i_arg]))
				exit(EXIT_FAILURE);
		}
		i_arg++;
	}
}
//export salut=salut cc= =nope nope nope== double=fail double=ez