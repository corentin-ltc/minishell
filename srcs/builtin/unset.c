/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:28:07 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/16 21:34:11 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	ft_unset(char **argv, char ***env)
{
	size_t	i;

	if (!argv[1])
		return ;
	i = 0;
	while (env[0][i])
	{
		if (!ft_strncmp(argv[1], env[0][i], ft_strlen(argv[1])))
			if (!ft_remove_index(env, i))
				exit(EXIT_FAILURE);
			else
				return ;
		i++;
	}
}