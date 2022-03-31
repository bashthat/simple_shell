#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define PRMTSIZ 255
#define MAXARGS 63
#define EXITCMD "exit"

int main(void) {
    for (;;) {
        char input[PRMTSIZ + 1] = { 0x0 };
        char *ptr = input;
        char *args[MAXARGS + 1] = { NULL };
        int wstatus;

        // prompt
        fgets(input, PRMTSIZ, stdin);

        // ignore empty input
        if (*ptr == '\n') continue;

        // convert input line to list of arguments
        for (int i = 0; i < sizeof(args) && *ptr; ptr++) {
            if (*ptr == ' ') continue;
            if (*ptr == '\n') break;
            for (args[i++] = ptr; *ptr && *ptr != ' ' && *ptr != '\n'; ptr++);
            *ptr = '\0';
        }

        // built-in: exit
        if (strcmp(EXITCMD, args[0]) == 0) return 0;

     }
}