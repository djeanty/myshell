#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int tokenize(char *line, char *tokens []);


int main(void)
{ 	char line [257];
	char *tokens [100];
	printf("> "); fgets(line, 256, stdin);
	while (strcmp(line, "exit\n")) 
	{
		tokenize (line, tokens);
		if (fork() == 0)
        {
            // blabla
            if (execvp(tokens[0], tokens) == -1)
            {
                // invalid command.
                printf("Invalid command.\n");
                exit(0);
            }
        }
		wait (0);
		printf("> "); fgets(line, 256, stdin);
	}
	exit(0);
}

/*
 * Tokenize the line and null-terminate it. 
 */
int tokenize (char *line, char *tokens [])
{
	int i=0;
	tokens[i] = strtok(line, " \n");
	while (tokens[i] != NULL) 
		tokens[++i] = strtok(NULL, " \n");
	return i;
}
