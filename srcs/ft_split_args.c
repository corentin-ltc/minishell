/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-tort <cle-tort@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:47:06 by cle-tort          #+#    #+#             */
/*   Updated: 2024/08/16 21:54:01 by cle-tort         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	countwords(char const *str)
{
	size_t	i;
	int		j;
	int	opened_quote;

	opened_quote = -1;
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != 32 && i == 0 )
			j++;
		else if (str[i] != 32 && str[i - 1] == 32 && opened_quote != 1)
			j++;
		if (str[i] == 34 || str[i] == 39)
			opened_quote = -opened_quote;
		i++;
	}
	return (j);
}

static void	freeall(char **dest)
{
	int	k;

	k = 0;
	while (dest[k])
	{
		free(dest[k]);
		k++;
	}
	free(dest);
}

char	*get_value(char *variable_name, char **env)
{
	char	*variable_value;
	size_t	i;

	i = 0;
	variable_value = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], variable_name, ft_strlen(variable_name)) == 0)
		{
			variable_value = ft_strdup(env[i] + ft_strlen(variable_name));
			if (!variable_value)
			{
				//free and exit
			}
			break ;
		}
		i++;
	}
	free (variable_name);
	if (!variable_value)
		variable_value = ft_strdup("");
		if (!variable_value)
		{
			// free and exit
		}
	
	return (variable_value);
}

char *get_variable(const char *str, int index, char **env)
{
	char *variable_name;
	int index_tmp;
	int	number_of_letters;
	int	i;

	index_tmp = index;
	variable_name = NULL;
	number_of_letters = 0;
	while (str[++index] && str[index] != 34)
		number_of_letters++;
	if (number_of_letters == 0)
		return ("$");
	variable_name = malloc(number_of_letters + 2);
	if (!variable_name) 
	{
		// free all and exit
	}
	variable_name[number_of_letters + 1] = 0;
	i = 0;
	while (str[++index_tmp] && str[index_tmp] != 34)
		variable_name[i++] = str[index_tmp];
	variable_name[i] = '=';
	return (get_value(variable_name, env));
}

int handle_doublequote (const char *str, int index, char **dest, char **env)
{
	int number_of_letters;
	
	number_of_letters = 0;
	index++;
	while(str[index] && str[index] != 34)
	{
		if (str[index] == '$')
		{
			number_of_letters += ft_strlen(get_variable(str, index, env));
			index++;
			while (str[index] != 32 && str[index] != 34 && str[index])		
				index++;
		}
		else
		{
			number_of_letters++;
			index++;
		}
	}
	return (number_of_letters);
}

static char	**countletters(char const *str, char **dest, char **env)
{
	int	i;
	int k;
	int	j;
	int number_of_letters;

	i = 0;
	k = 0;
	j = 0;
	while (str[i])
	{
		number_of_letters = 0;
		if (str[i] == 34)
		{
			number_of_letters = handle_doublequote(str, i, dest, env);
			dest[k] = malloc(number_of_letters + 1);
			if (!dest[k])
			{

			}
		}
		i++;
	}
}

// static void	gigachadsplit(char const *s, char sep, char **dest)
// {
// 	int	i;
// 	int	j;
// 	int	k;

// 	i = 0;
// 	k = 0;
// 	j = 0;
// 	while (s[i])
// 	{
// 		while (s[i] != sep && s[i])
// 		{
// 			dest[k][j] = s[i];
// 			i++;
// 			j++;
// 		}
// 		if (j > 0)
// 		{
// 			dest[k][j] = 0;
// 			k++;
// 		}
// 		if (s[i] == 0)
// 			return ;
// 		i++;
// 		j = 0;
// 	}
// }

char	**ft_split_args(char const *str, char **env)
{
	int		countw;
	char	**dest;

	if (!str)
		return (NULL);
	countw = countwords(str);
	dest = malloc(sizeof(char *) * (countw + 1));
	if (!dest)
		return (NULL);
	dest[countw] = 0;
	if (!countletters(str, dest, env))
		return (NULL);
	//gigachadsplit(s, c, dest);
	return (dest);
}

#include <stdio.h>

int main(int argc, char **argv, char **env)
{
	// char *t;

	// t = NULL;
	// ft_split(t, 0);
	char *line;

	line = readline("minishell > ");
	ft_split_args(line, env);
//	printf("countwords : %d", countwords(readline("minishell > ")));

}
