#include "shell.h"

/**
 * main - entry to ths shell progrm
 * Return: An int
 */

int main(void)
{
        char *buffer = NULL, **args;
        size_t read_size = 0;
        ssize_t buffer_size = 0;
        int exit_status = 0;

        while (1)
        {
                if (isatty(0))
                        printf("hsh$ ");

                buffer_size = getline(&buffer, &read_size, stdin);
                if (buffer_size == -1 || _strcmp("exit\n", buffer) == 0)
                {
                        free(buffer);
                        break;
                }
                buffer[buffer_size - 1] = '\0';

                if (_strcmp("env", buffer) == 0)
                {
			print_env();
                        continue;
                }

	if (no_line(buffer) == 1)
                {
                        exit_status = 0;
                        continue;
                }

                args = _split(buffer, " ");
                args[0] = search_path(args[0]);

                if (args[0] != NULL)
                        exit_status = search_cmd(args);
                else
                        perror("Error");
                free(args);
        }
        return (exit_status);
}
