/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:05:54 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/21 19:17:04 by nbellila         ###   ########.fr       */
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
/*wait*/
#include <sys/wait.h>
/*dirs*/
# include <sys/types.h>
# include <dirent.h>
/*structs|defines*/
# include "defines.h"
/*sources*/
# include "init.h"
# include "builtin.h"
# include "parsing.h"
# include "errors.h"
# include "utils.h"
# include "exec.h"

#endif
