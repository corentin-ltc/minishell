/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:14:55 by nbellila          #+#    #+#             */
/*   Updated: 2024/07/03 17:37:08 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*get_lines(char *filename)
{
	t_list	*lines;
	t_list	*new;
	char	*line;
	int		fd;

	lines = NULL;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		new = ft_lstnew(line);
		if (!new)
		{
			free(line);
			ft_lstclear(&lines, free);
			close(fd);
			return (NULL);
		}
		ft_lstadd_back(&lines, new);
		line = get_next_line(fd);
	}
	close(fd);
	return (lines);
}
