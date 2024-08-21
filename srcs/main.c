/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:55:57 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/21 02:59:44 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	minishell_loop(t_data *data)
// {
// 	size_t	i;

// 	while (true)
// 	{
// 		data->line = readline("minishell > ");
// 		if (!data->line)
// 			exit_error("success", data);
// 		add_history(data->line);
// 		get_vars(data);
// 		get_cmds(data);
// 		get_infiles(data);
// 		get_outfiles(data);
// 		get_args(data);
// 		show_data(*data);
// 		reset_data(data);
// 	}
// }

int main(int argc, char **argv, char **env)
{
	t_data	data_test;
	t_cmd 	*cmd_test;

	cmd_test = malloc(sizeof(t_cmd) * 3);
	cmd_test[0].line =  ft_strdup("echo -n $SALUT > outfile | < infile cat");
	cmd_test[0].args = malloc(sizeof(char *) * 4);
	cmd_test[1].args = malloc(sizeof(char *) * 4);

	cmd_test[0].args[0] = ft_strdup("cat"); 
	cmd_test[0].args[1] = ft_strdup("Makefile"); 
	cmd_test[0].out_fd = -42; //open("chat.txt", O_WRONLY | O_CREAT | O_APPEND, 0777);// fd de outfile
	cmd_test[0].in_fd = STDIN_FILENO; // fd de infile
	cmd_test[0].is_heredoc = false; // fd de infile
	
	cmd_test[1].out_fd = STDOUT_FILENO; //open("chat.txt", O_WRONLY | O_CREAT | O_APPEND, 0777);// fd de outfile
	cmd_test[1].in_fd = -42; // fd de infilecmd_test[0].out_fd = STDOUT_FILENO; //open("chat.txt", O_WRONLY | O_CREAT | O_APPEND, 0777);// fd de outfile
	cmd_test[1].args[0] = ft_strdup("wc");
	cmd_test[1].args[1] = ft_strdup("-l");
	
	data_test.cmds = &cmd_test;
	data_test.env = ft_arrdup(env);
	data_test.paths = get_paths(data_test.env);
	if (!data_test.paths)
	{
		// No path found, free and exit
	}
	maxi_piping(&data_test, cmd_test);
}
