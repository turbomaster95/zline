#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <zline.h>

struct termios orig_termios;

void my_completion(const char *buf, zl_completions_t *lc) {
    // List of all possible commands
    const char *commands[] = {"ls", "lscpu", "lsblk", "znu-kernel", NULL};

    for (int i = 0; commands[i] != NULL; i++) {
        // Only add to the suggestions if the command starts with 
        // what the user has typed so far
        if (zl_startswith(commands[i], buf)) {
            zl_add_completion(lc, commands[i]);
        }
    }
}

int main() {
    printf("ZLINE 2.0 - Press Ctrl-C to exit, Ctrl-R to search\n");

    zline_t *zl = zline_init("\033[1;32mzline\033[0m> ");
    zline_set_completion_callback(zl, my_completion);

    while (1) {
        char *line = zline_read(zl);
        
        if (line == NULL) { // Ctrl-C returns NULL
	    printf("Goodbye!");
            break;
        }

        printf("You entered: [%s]\n", line);
    }

    return 0;
}
