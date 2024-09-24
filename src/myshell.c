/*
Student Name: Quamdeen Adebowale Timson
Student Number: 22337421
Declaration: I, Quamdeen Timson, acknowledge all of DCU's Academic Integrity Policies.
*/
#include "myshell.h"

// I adapted this from https://loop.dcu.ie/mod/book/view.php?id=2322719&chapterid=492181
// Main entry point for the MyShell program.
int main(int argc, char **argv) {
    char buf[MAX_BUFFER]; // Buffer to hold each command line input.
    char *args[MAX_ARGS]; // Array to hold pointers to parsed arguments.
    char **arg;           // Pointer used for traversing through arguments.
    char cwd[1024];       // Buffer to store the current working directory's path.

    welcomeMessage(); // Displays a welcome message at the start.

    // Sets the SHELL environment variable to the full path of this shell executable.
    setShellEnv(argv[0]);

    // If the shell is started with an argument (expecting a batch file), enters batch mode.
    if (argc > 1) {
        batchMode(argv[1]); // Processes commands from the specified batch file.
        return 0; // Exits after batch processing is complete.
    }

    // Main loop for interactive mode: reads and executes commands until EOF (Ctrl+D).
    while (!feof(stdin)) {
        // Displays a command prompt that includes the current working directory.
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("%s ==> ", cwd); // Shows current directory in prompt.
        } else {
            perror("getcwd() error"); // Reports an error if current directory can't be determined.
            printf("==> "); // Provides a fallback prompt.
        }

        // Reads a line of input from the user.
        if (fgets(buf, MAX_BUFFER, stdin)) {
            // Ignores empty commands (just a newline).
            if (strcmp(buf, "\n") == 0) continue;

            // Begins tokenizing the input into arguments.
            arg = args;
            *arg++ = strtok(buf, SEPARATORS); // Splits the input on whitespace.
            while ((*arg++ = strtok(NULL, SEPARATORS))); // Continues to split the input.

            // If there's at least one argument, attempts to execute it as a command.
            if (args[0]) {
                executeCommand(args);
            }
        }
    }
    return 0;
}