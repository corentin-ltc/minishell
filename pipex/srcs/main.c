/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:22:38 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/18 20:10:37 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;

	check_args(ac, av);
	init_data(ac, av, env, &data);
	data.paths = get_paths(env);
	if (!data.paths)
		exit_error("No path found\n", &data);
	data.args = get_args(data, av);
	if (!data.args)
		exit_error("An allocation failed\n", &data);
	check_exec(&data);
	maxi_piping(data);
	free_data(&data);
	exit(EXIT_SUCCESS);
}
