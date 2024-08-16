#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>


void handle_sig(int sig)
{
	(void)sig;
	if (sig == SIGINT)
		write(STDOUT_FILENO, "\nminishell > ", 13);
}

int main(int argc, char **argv, char **env)
{
	char *line;

	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handle_sig);
	while (1)
	{
		line = readline("minishell > ");
		if (!line)
			exit(1);
		add_history(line);
		free(line);
	}
}

