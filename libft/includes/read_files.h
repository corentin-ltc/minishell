/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:31:43 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/10 14:09:43 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_FILES_H
# define READ_FILES_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif
# define FD_MAX 1024

# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);

int		read_line(t_list **lst, int fd);

char	*lst_to_line(t_list *lst);

int		clean_lst(t_list **lst);

void	ft_lstadd_back(t_list **lst, t_list *new);

int		ft_lstcontains(t_list *lst, char c);

size_t	ft_lststrlen(t_list *lst);

int		ft_strcontains(char *str, char c);

t_list	*get_lines(char *filename);

#endif
