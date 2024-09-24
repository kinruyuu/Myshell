# Student Name: Quamdeen Adebowale Timson.
# Student Number: 22337421.
# Operating System: CA216 project 1. 
# Declaration: I, Quamdeen Timson, acknowledge all of DCU's Academic Integrity Policies.

myshell: src/myshell.c src/utility.c src/myshell.h
	mkdir -p bin
	gcc -Wall src/myshell.c src/utility.c -o bin/myshell