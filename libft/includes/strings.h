/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:20:11 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/19 23:23:55 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGS_H
# define STRINGS_H

# include <stdlib.h>

size_t	ft_strlen(const char *s);

size_t	ft_strlcpy(char *dst, const char *src, size_t siz);

char	*ft_strcat(char *dst, char const *src);

size_t	ft_strlcat(char *dst, const char *src, size_t siz);

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

size_t	ft_strlcat(char *dst, const char *src, size_t siz);

size_t	ft_countchar(char const *s, char const c);

size_t	ft_skipcharset(char const *s, char *set);

size_t	ft_reachcharset(char const *s, char *set);

char	*ft_strcut(char *str, size_t start, size_t end);

char	*ft_strchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		ft_strcmp(const char *s1, const char *s2);

int		ft_strcontains(char *str, char c);

char	*ft_strnstr(const char *big, const char *little, size_t len);

char	*ft_strdup(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strjoin_sep(char const *s1, char const *s2, char const *sep);

char	*ft_strtrim(char const *s1, char const *set);

char	**ft_split(char const *s, char *set);

int		*ft_splittoi(char *str, char *set);

size_t	ft_countwords(char const *s, char *set);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void	ft_striteri(char *s, void (*f)(unsigned int, char *));

#endif