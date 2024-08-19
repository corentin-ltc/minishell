/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbellila <nbellila@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:32:01 by nbellila          #+#    #+#             */
/*   Updated: 2024/08/19 16:59:22 by nbellila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_countwords_noquotes(char *s, char sep)
{
	t_parser	parser;
	size_t		count;
	size_t		i;

	parser = new_parser();
	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == sep && update_parser(&parser, s[i]))
			i++;
		if (s[i] && parser.s_quotes == false && parser.d_quotes == false)
			count++;
		while (s[i] && s[i] != sep && update_parser(&parser, s[i]))
			i++;
	}
	return (count);
}

char	**ft_minisplit(char **dest, char *src, char sep, t_parser parser)
{
	size_t	i;
	size_t	col;
	size_t	start;

	i = 0;
	col = 0;
	start = i;
	while (true)
	{
		while (update_parser(&parser, src[i])
			&& (parser.s_quotes || parser.d_quotes))
			i++;
		if (src[i] == '\0' || src[i] == sep)
		{
			dest[col] = ft_substr(src, start, i - start);
			if (!dest[col])
				return (NULL);
			col++;
			start = i + 1;
		}
		if (!src[i])
			break ;
		i++;
	}
	return (dest);
}

char	**ft_split_noquotes(char *s, char sep)
{
	char		**split;
	t_parser	parser;
	size_t		wordscount;

	wordscount = ft_countwords_noquotes(s, sep);
	split = calloc((wordscount + 1), sizeof(char *));
	if (!split)
		return (NULL);
	if (wordscount == 0)
		return (split);
	parser = new_parser();
	parser.sep = sep;
	if (!ft_minisplit(split, s, sep, parser))
	{
		free_2d((void **)split, 0);
		return (NULL);
	}
	return (split);
}
