Project Author: Dat Nguyen

Course: Comp Sci 4760 

Date: 2/12/2025

GitHub Link: github.com/O-wll/OPSYS4760-PROJECT-1

Description of Project:

This project allows the user to play around with fork() with two files, user.c and oss.c. user.c is a file that prints out iterations, determined by user input, of the child pid and parent pid. oss.c will be the file actually forking and handling the output of user.c. The user will be able to:
- Control how many child processes there are total.
- Control how many child processes can be ran at once.
- Control how many iterations of the child processes are displayed.

How to compile, build, and use project:

The project comes with a makefile so ensure that when running this project that the makefile is in it.

Type 'make' and this will generate both the oss exe and user exe along with their object file.

user exe is ONLY for testing if user works, to properly use this program, type './oss -h' for instructions on how to use it.

When done and want to delete, run 'make clean' and the exe and object files will be deleted.

Issues Ran Into:
- When printing out PID and PPID, PPID would not print due to my implementation using %p instead of %d, %p expects a pointer. RESOLVED
- When printing out the ./user output when forking, the result ends up with a mix of the two processess, I assume intentional due to them running concurrently.
- When trying to use execl(), at first I ran into a problem where it would not execute ./user, found out later it is because I was putting in an integer and not a string so I had to convert the iterations variable into a string for it to work. RESOLVED
