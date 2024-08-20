/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:51:20 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/20 09:43:55 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

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
	char	**paths;
	t_cmd	**cmds;
}t_data;

typedef struct s_parser{
	bool	d_quotes;
	bool	s_quotes;
	char	sep;
}t_parser;

#endif