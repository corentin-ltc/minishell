#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>

int main(int argc, char **argv, char **env)
{
	char *line;
	char *prompt;
	char *userline;
	int i;

	userline = NULL;
	i = 0;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "USER=", 5) == 0)
		{
			userline = ft_strdup(env[i] + 5);
			break ;
		}
	}
	printf("%s", userline);
}