#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main(int argc, char **argv, char **env)
{
	char *line;

	line = readline("minishelll > ");
	printf("%s", line);
}