#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    // Load config files, if any.

    // Run command loop.
    lsh_loop();

    // Perform any shutdown/cleanup.

    return EXIT_SUCCESS;
}

void lsh_loop(void)
{
    char *line;  // line is going represent our cli argument
    char **args; // args is going represent array of arguments
    int status;  // status is terminating console

    // This is event loop that is constantly
    // responding to provided commands
    do
    {
        printf("> ");
        line = lsh_read_line();
        args = lsh_split_line(line);
        status = lsh_execute(args);

        // free memo
        free(line);
        free(args);
    } while (status);
}

#define LSH_RL_BUFSIZE 1024
char *lsh_read_line(void)
{
    int bufsize = LSH_RL_BUFSIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c;

    // Checking if memory is getting properly allocated
    if (!buffer) // that mean if buffer size is equal to 0
    {
        fprintf(stderr, "lsh: allocation errors\n");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        // Read a character
        c = getchar();

        if (c == EOF || c == '\n')
        {
            buffer[position] = '\0';
            return buffer;
        }
        else
        {
            buffer[position] = c;
        }
    }
