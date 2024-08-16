/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:22:59 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/17 18:59:17 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
/*wait*/
# include <sys/wait.h>
/*libft*/
# include "libft.h"
/*structs*/
typedef struct s_data {
	char	**paths;
	char	**env;
	char	***args;
	size_t	count;
	int		in_fd;
	int		out_fd;
	int		is_heredoc;
}t_data;
/*check*/
void	check_args(int ac, char **av);
/*parsing*/
void	init_data(int ac, char **av, char **ev, t_data *data);

char	**get_paths(char **envp);

char	***get_args(t_data data, char **av);

void	*check_exec(t_data *data);
/*exit*/
void	exit_error(char *str, t_data *data);

void	free_data(t_data *data);
/*pipex*/
void	maxi_piping(t_data data);

#endif