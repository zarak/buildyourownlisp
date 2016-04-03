#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32

/* Fake readline function */
char *readline(char *prompt) {
    fputs(prompt, stdout);
    fgets(buffer, 20148, stdin);
    char *cpy = malloc(strlen(buffer) + 1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy) - 1] = '\0';
    return cpy;
}

/* Fake add_history function */
void add_history(char *unused) {}

/* Otherwise include the editline headers */
#else
#include <editline/readline.h>
#endif

int main(int argc, char *argv[])
{
    /* Print version and exit information */
    puts("Lispy Version 0.0.0.0.1");
    puts("Press Ctrl-c to Exit\n");

    /* In a never ending loop */
    while (1) {
        char *input = readline("lispy> ");

        add_history(input);

        /* Echo input back to user */
        printf("=> %s\n", input);

        free(input);
    }

    return 0;
}
