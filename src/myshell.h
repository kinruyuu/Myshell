/*
Student Name: Quamdeen Adebowale Timson
Student Number: 22337421
Declaration: I, Quamdeen Timson, acknowledge all of DCU's Academic Integrity Policies.
*/
// Header file for the custom shell, MyShell, defining constants, including necessary libraries, and declaring utility functions.

#ifndef MYSHELL_H // Ensures this header file is included only once to prevent duplicate declarations.
#define MYSHELL_H

// Standard library includes for various functionalities.
#include <dirent.h> // For working with directories.
#include <fcntl.h> // Defines file control options like access modes.
#include <unistd.h> // Provides access to POSIX operating system API.
#include <stdio.h> // Standard input/output library.
#include <stdlib.h> // Standard library for memory allocation, process control, etc.
#include <string.h> // String handling functions.
#include <sys/types.h> // Definitions for many types used in system calls.
#include <sys/wait.h> // Declarations for waiting for process termination.
#include <errno.h> // Defines the integer variable errno, which is set by system calls and some library functions in the event of an error.

// Constants for shell operation.
#define MAX_BUFFER 1024 // Maximum length of a command line input.
#define MAX_ARGS 64     // Maximum number of arguments allowed in a command.
#define SEPARATORS " \t\n" // Characters that separate command arguments.

// Declaration of utility functions used by the shell.
void welcomeMessage(); // Displays a welcome message.
void clearScreen(); // Clears the terminal screen.
void changeDirectory(char *path); // Changes the current working directory.
void listDirectoryContents(char **args); // Lists contents of a directory.
void listEnvironmentVariables(); // Lists all environment variables.
void echoCommand(char **args); // Echoes arguments back to the terminal.
void showHelp(); // Shows help/documentation.
void pauseShell(); // Pauses shell execution until ENTER is pressed.
int executeInternalCommand(char **args); // Executes built-in shell commands.
void executeProgram(char **args, int in, int out, int append); // Executes external programs with optional I/O redirection.
void executeCommand(char **args); // Parses and executes a command.
void batchMode(char *batchFilePath); // Executes commands from a batch file.
void syserr(char *msg); // Prints system error messages.
void setShellEnv(char *path); // Sets SHELL environment variable to the shell path.

#endif // Ends the inclusion guard.
