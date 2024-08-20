/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:55:57 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/20 11:46:35 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	cmd_test[0].out_fd = STDOUT_FILENO; //open("chat.txt", O_WRONLY | O_CREAT | O_APPEND, 0777);// fd de outfile
	cmd_test[0].in_fd = STDIN_FILENO; // fd de infile
	cmd_test[0].is_heredoc = false; // fd de infile
	
	cmd_test[1].out_fd = STDOUT_FILENO; //open("chat.txt", O_WRONLY | O_CREAT | O_APPEND, 0777);// fd de outfile
	cmd_test[1].in_fd = -42; // fd de infilecmd_test[0].out_fd = STDOUT_FILENO; //open("chat.txt", O_WRONLY | O_CREAT | O_APPEND, 0777);// fd de outfile
	//cmd_test[1].args[0] = ft_strdup("wc");
	//cmd_test[1].args[1] = ft_strdup("Makefile");
	
	data_test.cmds = &cmd_test;
	data_test.env = ft_arrdup(env);
	maxi_piping(&data_test, cmd_test);
}
