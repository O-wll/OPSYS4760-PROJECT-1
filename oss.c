#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

// Author: Dat Nguyen
// Date: 2/12/2025

int help() {  // Help function prints out instructions to run this program and also explains what the program does.
	printf("Test \n");
}

int main(int argc, char** argv) { // Main program
	int userInput = 0;
	int childProcesses = 0;
	int iterations = 1;
	int simulations = 0;
	int currentProc = 0;
	int currentIter = 0;

	if (argc < 2) {  // If user enters no arguments
		printf("Error: Argument expected \n");
		printf("Usage: ./oss -h to learn how to use this program \n");
		return(EXIT_FAILURE);
	}

	// Input handling 
	while ((userInput = getopt(argc, argv, "n:s:t:h")) != -1) {
		switch(userInput) {
			case 'n': // How many child processes to launch.
				childProcesses = atoi(optarg);
				if (childProcesses <= 0) {
					printf("Error: Total child processes must be at least one. \n");
					return(EXIT_FAILURE);
				}
				break;
			case 's': // How many simulations to run at once.
				simulations = atoi(optarg);
				// Ensuring simulations isn't zero or below for the program to work.
				if (simulations <= 0) {
					printf("Error: Simulations must be at least one. \n");
					return(EXIT_FAILURE);
				}	
				break;
			case 't': // How many iterations of user process to run.
				iterations = atoi(optarg);
				break;
			case 'h': // Prints out help function.
				help();
				return 0;
			case '?': // Invalid user argument handling.
				printf("Error: Invalid argument detected \n");
				printf("Usage: ./oss.c -h to learn how to use this program \n");
				return(EXIT_FAILURE);
		}
	}
	
	// Incase user inputs iteration equal to or below zero.
	if (iterations <= 0) {
		printf("Error: Iterations must be above 0 \n");
		return(EXIT_FAILURE);
	}
	
	// Main forking process
	pid_t pid;
	while (currentProc < childProcesses) { // Continue until total child processes is reached.
		pid = fork();
		if (pid == 0) { // Fork successful.
			printf("Child pid: %d Parent pid: %d\n", getpid(), getppid());
			exit(EXIT_SUCCESS);
		} else {
			currentProc++;
		}
	}
	
	// Waiting for the child processes to complete, to ensure clean output.
	for (int i = 0; i < childProcesses; i++) {
		wait(NULL);
	}

	return 0;
}
