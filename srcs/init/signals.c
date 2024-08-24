/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:57:44 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/24 20:04:47 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_sig(int sig)
{
	(void)sig;
	if (sig == SIGINT)
		write(STDOUT_FILENO, "\nminishell > ", 13);
}	

void	set_signals(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handle_sig);
}
