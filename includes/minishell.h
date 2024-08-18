/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:05:54 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/18 14:11:57 by nbellila         ###   ########.fr       */
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
/*others*/
# include "signals.h"
# include "builtin.h"
# include "errors.h"
# include "utils.h"

#endif
