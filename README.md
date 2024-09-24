MyShell User Manual

Welcome to MyShell, a lightweight, user-friendly command-line interface designed to introduce beginners to the UNIX environment.
MyShell simplifies interaction with the underlying operating system, offering essential functionalities like command execution, file management, and process control.

Getting Started
Upon launching MyShell, you're greeted with a welcome message. The shell waits for your input. Type a command and press Enter to execute it.

Type 'help' to see the list of available commands.
Type 'quit' to exit the shell.

MyShell Built-in Commands
'cd'
Usage: cd `<directory>`

Changes the current working directory to '`<directory>`'. If no directory is specified, it displays the current working directory.
This command is fundamental for navigation within the filesystem.

Examples:
   cd /home/user/Documents changes the current directory to /home/user/Documents.
   cd with no arguments prints the path of the current working directory.

'clr'
Usage: clr

Clears the terminal screen, removing all previously displayed commands and output. This command is useful for decluttering the terminal view.

'dir'
Usage: dir `<directory>`

Lists the contents of '`<directory>`'. If no directory is specified, it lists the contents of the current directory.
This command is similar to ls in UNIX/Linux systems and is essential for exploring the filesystem.

   Example: dir src lists all files and directories inside src.

'environ'

Usage: environ

Displays all environment variables and their values. Environment variables are key-value pairs that store information affecting the program's execution environment.
This command is crucial for understanding the current shell environment.

'echo'
Usage: echo `<message>`

Prints '`<message>`' to the screen. This command is used for displaying messages or variable values in scripts or during shell interaction.

   Example: echo Hello, World! displays Hello, World! in the terminal.

'help'
Usage: help

Shows the MyShell user manual, providing descriptions and usage examples of all built-in commands. This command is the go-to resource for learning how to use MyShell.

'pause'
Usage: pause

Pauses shell operations, waiting for the user to press the 'Enter' key before continuing. This command is useful for scripting and interactive tutorials,
allowing users to take a moment before moving on to the next command.

'quit'
Usage: quit

Exits MyShell. This command terminates the shell session, returning control to the parent process or closing the terminal window.

Advanced Features

I/O redirection is a process in UNIX and UNIX-like operating systems that allows the standard input (stdin), standard output (stdout),
and standard error (stderr) of a command to be redirected from their default sources or destinations to other files or devices.
This feature enables users to direct the output of a command to a file, append output to an existing file, or even use a file as input to a command, among other uses.
I/O redirection is a powerful tool for managing the flow of data in shell scripting and command-line operations, allowing for greater flexibility and automation.
MyShell supports this feature, enhancing your ability to manage data flows in your commands.

Output Redirection ('>' and '>>')

Output redirection allows you to manage where the output of your commands goes, with the flexibility to either overwrite existing files or append to them, using the > and >> operators, respectively.

Overwrite (>):

When you're looking to capture the output of a command and save it to a file, essentially starting fresh, you'll use the > operator.
This action overwrites any content that may already exist in the file with the new output.

   Example: Imagine you want to create or update a file called dirlist.txt with a fresh list of the contents in your current directory.
   The command ls > dirlist.txt accomplishes this. If dirlist.txt already exists, its previous content will be replaced entirely by the new directory listing.

Append (>>):

Alternatively, if your goal is to retain existing content in a file while adding new output to it, the >> operator is your friend.
This appends the command output to the end of the specified file without disturbing what was there before.

   Example: Suppose you've already got a file, dirlist.txt, with some content, and you want to add the current directory's listing to it without overwriting the existing data.
   By using ls >> dirlist.txt, the new directory listing is added to the end of dirlist.txt, preserving its original content.

Input Redirection ('<')

Input redirection allows a command to receive its input from a file, rather than directly from the keyboard.
This feature is particularly useful for supplying commands with large amounts of input data or for automating tasks in scripts.

Standard input (stdin) is the default source of input for commands and programs in UNIX-like systems, which usually comes from the keyboard.
By using the < operator, you can redirect stdin to read from a file, providing a flexible way to input data into commands.

Example: Let's say you have a text file named input.txt that contains the text "Today is a good day".
You want to display this text in the shell using the cat command, which normally reads from stdin and prints to standard output (stdout).

1. First, create a file named input.txt and write the following inside it:
   'Today is a good day'
2. Use the command cat < input.txt to redirect the content of input.txt to the cat command.
   command: cat < input.txt

This command tells the shell to redirect the content of input.txt to cat, which then reads the file as if it were typed directly into the terminal.
The shell will print:
   Today is a good day
to the standard output, allowing you to see the content of input.txt on your screen

Background Program Execution

One of the powerful features of MyShell, and UNIX-like shells in general, is the ability to run programs in the background.
This means you can start a program and have it execute without tying up your terminal, allowing you to continue working on other tasks in the meantime.

How It Works:

When you append an ampersand (&) to the end of a command, you instruct the shell to launch the program in a background process.
The shell then immediately returns you to the prompt, ready for your next command, while the background process continues to run.

Example Usage:

Imagine you have a script named longrunningtask.sh that takes several minutes to complete. Instead of waiting at the terminal for the script to finish,
you can start it in the background:
   longrunningtask.sh &

After executing the command with &, MyShell prints a job number and process ID for the background task, then returns you to the prompt.
The background process's output will not be shown in your terminal. If you need to capture the output, consider redirecting it to a file using >.
You can check the status of background jobs at any time with 'ps -a'

Foreground Program Execution
In MyShell, like in traditional UNIX-like shells, programs executed from the command prompt run in the foreground by default.
This means that after you enter a command and press Enter, the shell initiates the program's execution and waits for it to finish,
displaying any output to the terminal. Control is returned to the shell prompt only after the program exits.

Understanding Foreground Execution:

Direct Interaction: Running a program in the foreground is ideal for applications that require user interaction or when you need to monitor the program's output in real time.
Sequential Execution: Commands run in the foreground must complete before the next command is started, ensuring operations are performed in a sequential order.
Signal Reception: Programs running in the foreground can be directly interrupted or stopped with keyboard signals like Ctrl+C (interrupt) or Ctrl+Z (suspend).

Example Usage:
Executing a simple command, such as listing directory contents, is an instance of foreground execution:
   dir src
This command lists the contents of src, and the shell waits for the dir command to finish before you can enter another command.

The Program Environment

In MyShell, like in many UNIX-like systems, the environment plays a pivotal role in the operation of the shell and the execution of commands.
The environment consists of a set of variables, known as environment variables, that store information used to configure the system's behavior for user sessions and shell scripts.

Understanding Environment Variables

Environment variables contain data such as the current user's home directory (HOME), the path to executable files (PATH),
and the preferred editor (EDITOR), among others. They influence how commands execute and how programs determine their configuration.

For example, when you run the environ command in MyShell, you get an output similar to this:
   SHELL=/home/ade/ca216/MyshellAssignment/bin/myshell
   PATH=/home/ade/.vscode-server/bin/...:/usr/local/bin:/usr/bin:/bin

This output lists the environment variables available in your MyShell session, showing their names and values.
The SHELL variable, for instance, points to the path of MyShell's executable, and PATH lists the directories the shell searches for command executables.

How MyShell Utilizes the Environment

When you execute a command, MyShell uses these environment variables to determine how to execute it:

PATH is searched for the command if it's not a built-in or an alias.
HOME is used when referencing the user's home directory, such as when using cd without arguments to go to the home directory.

Listing Environment Variables

To see all the environment variables in your current session, simply type environ:
   MyshellAssignment ==> environ
This command is particularly useful for debugging scripts or understanding your current shell session's configuration.

Processes: MyShell can create and manage processes, allowing for multitasking within the shell environment.
   Foreground processes require the shell to wait until the process completes.
   Background processes allow the shell to continue accepting commands.

References
Cooper, M. (2014) Advanced bash-scripting guide: An in-depth exploration of the art of Shell scripting. Linux Documentation Project.
Quigley, E. (1997) Unix shells by example. London etc.: Prentice Hall.
Robbins, A. (2005) Unix in a nutshell: A desktop quick reference ; covers GNU/Linux, mac OS X, and solaris. Beijing: O’Reilly.
Siever, E. (2009) Linux in a Nutshell. Beijing: O’Reilly.
Stones, R. and Matthew, N. (2000) Beginning linux programming, 2nd edition. John Wiley & Sons.
Tansley, D. (2011) Linux and unix shell programming. Harlow, England: Addison-Wesley.
WANG, P.S. (2017) Mastering linux. CRC Press.

Student Name: Quamdeen Adebowale Timson
Student Number: 22337421
Declaration: I, Quamdeen Timson, acknowledge all of DCU's Academic Integrity Policies.
