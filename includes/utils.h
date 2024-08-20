/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:48:54 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/20 19:24:00 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/*functions*/
char	*ft_getenv(char *name, char **env);

char	*ft_setenv(char *name, char *value, char ***env);

char	*get_filenaname(char *str);

#endif