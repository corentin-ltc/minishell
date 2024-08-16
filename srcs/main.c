/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:55:57 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/16 19:52:25 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **env)
{
	char *line;

	set_signals();
	while (1)
	{
		line = readline("minishell > ");
		if (!line)
			exit(1);
		add_history(line);
		check_builtin(ft_split(line, " "), &env);
		free(line);
	}
}