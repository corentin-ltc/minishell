/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:05:54 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/18 15:24:50 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*libft*/
# include "libft.h"
/*readline*/
# include <readline/readline.h>
# include <readline/history.h>
/*signals*/
# include <signal.h>
/*dirs*/
# include <sys/types.h>
# include <dirent.h>
/*structs*/
typedef struct s_cmd{
	char	*line;
	char	**args;
	int		in_fd;
	int		out_fd;
	bool	is_heredoc;
}t_cmd;
typedef struct s_data{
	char	**env;
	char	*line;
	t_cmd	**cmds;
}t_data;
/*sources*/
# include "init.h"
# include "builtin.h"
# include "errors.h"
# include "utils.h"

#endif
