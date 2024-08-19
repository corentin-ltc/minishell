/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:51:20 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/20 00:25:52 by nbellila         ###   ########.fr       */
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
	t_cmd	**cmds;
}t_data;

typedef struct s_parser{
	bool	d_quotes;
	bool	s_quotes;
	bool	infile;
	bool	here_doc;
	bool	outfile;
	bool	append;
	char	*set;
}t_parser;

#endif