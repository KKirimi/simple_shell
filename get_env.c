#include "shell.h"

/**
 * _getenv - this function gets the env variables
 * @env_var: this is the env variable
 * Return: env variable result
 */

char *_getenv(char *env_var)
{
        int k = 0, m;
        int status;

        while (environ[k])
        {
                status = 1;

                for (m = 0; environ[k][m] != '='; m++)
                {
                        if (environ[k][m] != env_var[m])
                                status = 0;
                }
                if (status == 1)
                        break;
                k++;
        }
        return (&environ[k][m + 1]);
}

/**
 * _env - this function prints the environment
*/
void _env(void)
{
        int k = 0;

        while (environ[k])
        {
                printf("%s\n", environ[k]);
                k++;
        }
}
