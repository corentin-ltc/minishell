#include <minishell.h>

void handle_sig(int sig)
{
	(void)sig;
	if (sig == SIGINT)
		write(STDOUT_FILENO, "\nminishell > ", 13);
}

int main(int argc, char **argv, char **env)
{
	char *line;

	signal(SIGQUIT, handle_sig);
	signal(SIGINT, handle_sig);
	while (1)
	{
		line = readline("minishell > ");
		if (!line)
			exit(1);
		add_history(line);
		free(line);
		argc++;
		argv++;
		env++;
	}
}

