/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:25:33 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/21 19:34:57 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_childs(t_data *data)
{
	while (data->childs)
	{
		waitpid(0, &data->exit_code, 0);
		data->childs--;
	}
}