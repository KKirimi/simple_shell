#include "shell.h"

/**
 * execute - this function executes a command path
 * @args: this is the arguments
 * Return: exit status
 */

int execute(char **args)
{
        int pp = fork(), status;

        if (pp == 0)
        {
                if (execve(args[0], args, environ) == -1)
                        perror("Error");
        }
        else
        {
                wait(&status);
                if (WIFEXITED(status))
                        status = WEXITSTATUS(status);
        }

        return (status);
}
