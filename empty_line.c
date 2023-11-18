#include "shell.h"

/**
 * empty_line - this function checks if an empty line exists
 * @buff: this is the line
 * Return: 0 or 1
 */

int empty_line(char *buff)
{
        int k;

        for (k = 0; buff[k] != '\0'; k++)
        {
                if (buff[k] != ' ')
                        return (0);
        }
        return (1);
}
