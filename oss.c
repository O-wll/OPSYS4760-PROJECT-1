#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

// Author: Dat Nguyen
// Date: 2/12/2025

void help() {  // Help function prints out instructions to run this program and also explains what the program does.
	printf("This program forks and splits off into the amount of child processes of your choice (has to be above zero), how many iterations user.c will run, and how many simulations can happen at once.\n");
	printf("Command structure: ./oss [-h] [-n proc] [-s simul] [-t iter]\n");
	printf("-h prints out the help function you are currently seeing. \n");
	printf("-n is for indicating how many child processes you want to run, proc is the number you'll input. Default is one \n");
	printf("-t is for indicating how many iterations user will run, iter is the number you'll input. Default is one \n");
	printf("-s is for indicating how many simulations, child processes, will run at once, simul is the number you'll input. Default is equal to how many child processes you're running. \n");
}

int main(int argc, char** argv) { // Main program
	int userInput = 0;
	int childProcesses = 1; // Default value to one process if user does not input.
	int iterations = 1; // Default value to one iteration if user does not input.
	int simulations = 0;
	int currentProc = 0;
	int procRunning = 0;


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
				if (simulations < 0) {
					printf("Error: Simulations must be positive. \n");
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

	// If user does not put anything for how many concurrent simulations, default to do them all at once.
	if (simulations == 0) {
		simulations = childProcesses;
	}
	
	// Main forking process
	pid_t pid;
	char strIter[20]; // We need to convert our iteration value to a string to use execl().
	sprintf(strIter, "%d", iterations);

	while (currentProc < childProcesses) { // Continue until total child processes is reached.
		if (procRunning < simulations) {
			pid = fork();
			if (pid == 0) { // Fork successful.
				execl("./user", "user", strIter, (char *)NULL);  // Run ./user
				exit(EXIT_SUCCESS);
			} else {
				currentProc++;
				procRunning++;
			}
		} else { // If the current number of processes are running equal to the amount of simulations the user requested, than wait until a process finishes and then decrease the count to let another process run.
			wait(NULL); 
			procRunning--;
		}
	}
	
	// Prevent program from exiting too early after all child processes have loaded in also ensures the count of processes running still decreases, after child process is finished, after the while loop above ends.
	while (procRunning > 0) {
		wait(NULL);
		procRunning--;
	}

	return 0;
}
