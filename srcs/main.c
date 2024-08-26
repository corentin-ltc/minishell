/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (argc > 2 && argv)
		exit_error("Too many arguments", NULL);
	init_data(&data, env);
	while (true)
	{
		data.line = readline("minishell > ");
		if (!data.line)
			exit_free(&data);
		add_history(data.line);
		if (is_valid_line(data.line))
		{
			get_vars(&data);
			get_cmds(&data);
			get_cleanlines(&data);
			get_args(&data);
			if (!single_builtin(&data))
				exec_cmds(&data);
		}
		reset_data(&data);
	}
	return (0);
}
