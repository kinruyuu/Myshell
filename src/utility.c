/*
Student Name: Quamdeen Adebowale Timson
Student Number: 22337421
Declaration: I, Quamdeen Timson, acknowledge all of DCU's Academic Integrity Policies.
*/
#include "myshell.h"

extern char **environ;  // Access to the environment variables

// image taken from https://www.asciiart.eu/animals/reptiles/dinosaurs
void welcomeMessage() {
    printf("+---------------------------------------+\n");
    printf("|                                       |\n");
    printf("|       Welcome to MyShell!             |\n");
    printf("|                                       |\n");
    printf("|       Name: Quamdeen Timson           |\n");
    printf("|       Student Number: 22337421        |\n");
    printf("|               __                      |\n");
    printf("|              / _)                     |\n");
    printf("|     _.----._/ /                       |\n");
    printf("|    /         /                        |\n");
    printf("| __/ (  | (  |                         |\n");
    printf("|/__.-'|_|--|_|                         |\n");
    printf("|                                       |\n");
    printf("+---------------------------------------+\n");
    printf("Type 'help' to see the list of available commands.\n");
    printf("Type 'quit' to exit the shell.\n");
}

// Defines the `clearScreen` function that takes no arguments and returns nothing (void).
// Its purpose is to clear the terminal screen to provide a clean slate for further output.
void clearScreen() {
    // Executes the shell command "clear" by calling the `system` function.
    system("clear");
}


// Defines a function named `changeDirectory` that takes a single argument, `path`, which is a pointer to a character array (a string). This function is designed to change the shell's current working directory to the directory specified by `path`.
void changeDirectory(char *path) {
    // Checks if the path provided is NULL. If it is, the function aims to print the current working directory instead of changing to a new directory.
    if (path == NULL) {
        char cwd[1024]; // Declares an array of characters to hold the current working directory.
        // Tries to get the current working directory and store it in the 'cwd' array. The size of the array is specified to prevent buffer overflow.
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("%s\n", cwd); // If getting the current directory succeeds, prints the directory to the standard output.
        } else {
            perror("getcwd() error"); // If getting the current directory fails, prints an error message.
        }
    } else {
        // If a non-NULL path is provided, attempts to change the current working directory to the specified path.
        if (chdir(path) != 0) {
            perror("cd failed"); // If changing the directory fails, prints an error message.
        }
    }
}

// Defines a function named `listDirectoryContents` designed to list the contents of a directory. 
void listDirectoryContents(char **args) {
    char arr[250] = "ls -al"; // Initializes `arr` with the command "ls -al".
    
    // Checks if there is a second argument provided in `args` (args[1]), which is not NULL.
    if (args[1] != NULL) {
        strcat(arr, " "); // Ensures a space before appending the directory argument.
        strcat(arr, args[1]); // Appends the second argument to the command.
    }

    // Executes the command stored in `arr` by calling the `system` function and checks for errors.
    int status = system(arr);
    if (status == -1) {
        perror("system call failed");
    } else if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
        // Check if the command executed but exited with an error code.
        fprintf(stderr, "Command executed with a non-zero exit status.\n");
    }
}


// Defines a function to list all environment variables.
void listEnvironmentVariables() {
    extern char **environ; // Points to an environment variables array.

    // Loop through the environment variables array.
    for (char **env = environ; *env != 0; env++) {
        // Dereferences `env` to get the current environment variable (in "key=value" format) and prints it.
        printf("%s\n", *env);
    }
}


// Implements `echoCommand` to print arguments.
void echoCommand(char **args) {
    // Skips command name at args[0], prints arguments from args[1] onwards.
    for (int i = 1; args[i] != NULL; i++) {
        printf("%s ", args[i]); // Prints each argument with a trailing space.
    }
    printf("\n"); // Ends output with a newline.
}


// The `showHelp` function displays the application's help documentation using the `system` call.
void showHelp() {
    // Executes the "more" command to paginate the content of "manual/readme.md".
    // This allows users to scroll through the help file.
    system("more manual/readme.md");
}


// Implements a function to pause the shell's execution, prompting the user to press ENTER to continue.
void pauseShell() {
    // Displays a message prompting the user to press the ENTER key.
    printf("Press ENTER to continue...");

    // Enters a loop that continuously calls `getchar()` to read characters from the standard input.
    // The loop only exits when `getchar()` returns '\n', which corresponds to the ENTER key being pressed.
    while (getchar() != '\n');
}


// Defines a function to terminate the shell program.
void quitShell() {
    // Prints a message to standard output indicating the shell is about to exit.
    printf("Exiting shell...\n");

    // Calls the `exit` function with an argument of 0, indicating successful completion of the shell.
    // This causes the shell program to terminate immediately.
    exit(0);
}

// Handles system errors by reporting them and aborting the program.
void syserr(char *msg) {
    // Prints an error message combining a custom message and the system error string.
    fprintf(stderr, "%s: %s\n", msg, strerror(errno)); // `errno` holds the last error code.

    // Terminates the program indicating failure.
    exit(EXIT_FAILURE); // `EXIT_FAILURE` signifies program failure.
}


// Executes supported internal shell commands based on the first argument.
int executeInternalCommand(char **args) {
    // Checks if the first argument is "cd" and executes the change directory command.
    if (!strcmp(args[0], "cd")) {
        changeDirectory(args[1]);
        return 1; // Successfully executed an internal command.
    } 
    // Checks for the "clr" command to clear the screen.
    else if (!strcmp(args[0], "clr")) {
        clearScreen();
        return 1;
    } 
    // Checks for the "dir" command to list directory contents.
    else if (!strcmp(args[0], "dir")) {
        listDirectoryContents(args);
        return 1;
    } 
    // Checks for the "environ" command to list environment variables.
    else if (!strcmp(args[0], "environ")) {
        listEnvironmentVariables();
        return 1;
    } 
    // Checks for the "echo" command to echo arguments.
    else if (!strcmp(args[0], "echo")) {
        echoCommand(args);
        return 1;
    } 
    // Checks for the "help" command to show help documentation.
    else if (!strcmp(args[0], "help")) {
        showHelp();
        return 1;
    } 
    // Checks for the "pause" command to pause the shell.
    else if (!strcmp(args[0], "pause")) {
        pauseShell();
        return 1;
    } 
    // Checks for the "quit" command to exit the shell.
    else if (!strcmp(args[0], "quit")) {
        quitShell();
        return 1;
    }
    // Returns 0 if no internal command matches the first argument.
    return 0; 
}


// Executes an external program, possibly in the background, with optional input/output redirection.
void executeProgram(char **args, int in, int out, int append) {
    int background = 0; // Indicates if the program should run in the background.
    pid_t pid; // Process ID for the child process.
    int status; // Status returned by the child process.

    // Loop through args to check if '&' is the last argument, signaling background execution.
    for (int i = 0; args[i] != NULL; i++) {
        if (!strcmp(args[i], "&") && args[i+1] == NULL) {
            background = 1; // Enable background execution.
            args[i] = NULL; // Remove '&' for execution.
            break;
        }
    }

    pid = fork(); // Create a new process.
    if (pid == -1) {
        // If fork fails, report the error.
        perror("fork failed");
    } else if (pid == 0) { // In the child process.
        // Set up redirection if specified.
        if (in != -1) {
            dup2(in, STDIN_FILENO); // Redirect standard input.
            close(in);
        }
        if (out != -1) {
            dup2(out, STDOUT_FILENO); // Redirect standard output.
            close(out);
        } else if (append != -1) {
            dup2(append, STDOUT_FILENO); // Append to standard output.
            close(append);
        }

        execvp(args[0], args); // Execute the program.
        perror("execvp failed"); // Report if execution fails.
        exit(EXIT_FAILURE); // Exit with a failure status.
    } else { // In the parent process.
        if (!background) {
            // Wait for the child process to finish if not in background.
            do {
                waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        } else {
            // Notify that the process is running in the background.
            printf("Process %d running in background\n", pid);
        }
    }
}


// This code was adapted from stack overflow https://stackoverflow.com/questions/52939356/redirecting-i-o-in-a-custom-shell-program-written-in-c
// Function to execute a command with support for I/O redirection and checking for internal commands.
void executeCommand(char **args) {
    int in = -1, out = -1, append = -1; // Initializes file descriptors for I/O redirection to invalid values.
    char *args_clean[MAX_ARGS]; // Array to store arguments after removing I/O redirection symbols.
    int cleanidx = 0; // Index for populating args_clean.
    int stdout_copy = dup(STDOUT_FILENO); // Creates a copy of the current STDOUT file descriptor.
    int stdin_copy = dup(STDIN_FILENO); // Creates a copy of the current STDIN file descriptor.

    // Iterates over args to check for and handle I/O redirection symbols ("<", ">", ">>").
    for (int i = 0; args[i] != NULL; i++) {
        if (!strcmp(args[i], "<")) {
            in = open(args[++i], O_RDONLY); // Opens file for reading if "<" is found.
            if (in < 0) {
                perror("Error opening input file");
                return; // Exits the function on error.
            }
        } else if (!strcmp(args[i], ">")) {
            out = open(args[++i], O_WRONLY | O_CREAT | O_TRUNC, 0644); // Opens file for writing, truncating it if it exists.
            if (out < 0) {
                perror("Error opening output file");
                return; // Exits the function on error.
            }
        } else if (!strcmp(args[i], ">>")) {
            append = open(args[++i], O_WRONLY | O_CREAT | O_APPEND, 0644); // Opens file for appending.
            if (append < 0) {
                perror("Error opening output file for append");
                return; // Exits the function on error.
            }
        } else {
            args_clean[cleanidx++] = args[i]; // Saves non-redirection arguments.
        }
    }
    args_clean[cleanidx] = NULL; // Null-terminates the cleaned arguments array.

    // Sets up redirection if needed.
    if (in >= 0) {
        dup2(in, STDIN_FILENO); // Redirects STDIN.
        close(in);
    }
    if (out >= 0) {
        dup2(out, STDOUT_FILENO); // Redirects STDOUT.
        close(out);
    } else if (append >= 0) {
        dup2(append, STDOUT_FILENO); // Redirects STDOUT for appending.
        close(append);
    }

    // Tries to execute the command as an internal command first; if not found, executes it as an external program.
    if (!executeInternalCommand(args_clean)) {
        executeProgram(args_clean, in, out, append);
    }

    // Restores the original STDIN and STDOUT file descriptors.
    dup2(stdout_copy, STDOUT_FILENO);
    dup2(stdin_copy, STDIN_FILENO);
    close(stdout_copy);
    close(stdin_copy);
    // No need to explicitly close in, out, append here since they're already closed.
}

// Executes commands from a batch file, allowing automated script execution.
void batchMode(char *batchFilePath) {
    // Opens the batch file for reading. The path is provided by the caller.
    FILE *batchFile = fopen(batchFilePath, "r");
    if (!batchFile) {
        perror("Error opening batch file"); // If the file can't be opened, report the error and exit.
        exit(EXIT_FAILURE);
    }

    char buf[MAX_BUFFER]; // Buffer to hold each line read from the batch file.
    char *args[MAX_ARGS]; // Array to hold the command and its arguments after splitting.
    char **arg; // Pointer used to populate the args array.

    // Reads the batch file line by line until the end of the file is reached.
    while (fgets(buf, MAX_BUFFER, batchFile) != NULL) {
        arg = args; // Resets arg to the start of args array for each new line.
        // Splits the line into tokens based on SEPARATORS, initializing the args array.
        *arg++ = strtok(buf, SEPARATORS); 
        // Continues to tokenize the rest of the line and populate args array.
        while ((*arg++ = strtok(NULL, SEPARATORS)));

        // If the first argument (the command) is not NULL, executes the command.
        if (args[0]) {
            executeCommand(args);
        }
    }
    fclose(batchFile); // Closes the batch file after processing all commands.
}

// Sets the SHELL environment variable to the absolute path of the shell executable.
void setShellEnv(char *path) {
    char fullpath[1024]; // Buffer to store the resolved absolute path.

    // Attempts to resolve the absolute path of the given path and stores it in fullpath.
    if (realpath(path, fullpath) != NULL) {
        // Attempts to set the SHELL environment variable to the resolved path.
        if (setenv("SHELL", fullpath, 1) == -1) {
            perror("Failed to set SHELL environment variable");
            // Handle the error appropriately. For now, we just print an error message.
            // Depending on your application's needs, you might exit or take other actions.
        }
    } else {
        // If realpath fails, prints an error message.
        perror("Failed to resolve the path to set SHELL environment variable");
    }
}