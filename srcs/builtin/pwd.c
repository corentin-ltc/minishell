/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabil <nabil@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:28:07 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/23 06:18:26 by nabil            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_data *data, t_cmd *cmd)
{
	char	*path;

	path = getcwd(NULL, 0);
	if (!path)
		exit_error("couldn't get cwd", data);
	ft_putendl(path);
	free(path);
	data->exit_code = 0;
	(void *)cmd;
}
