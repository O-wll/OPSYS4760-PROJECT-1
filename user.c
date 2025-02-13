#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

// Author: Dat Nguyen
// Date: 2/12/2025
// user.c is a program that is called from oss.c and takes in an integer argument and do iterations based on the input. The iterations display the user PID and the parents PID before sleeping and then after sleeping.

int main(int argc, char **argv) { // Main program
	
	int calls = 0;
	int iterations = 0;

	// Calls is how many times the program should run.
	calls = atoi(argv[1]);
	
	// For loop prints the user pid and the parent pid before sleeping, then the same info after sleeping.
	for (int i = 0; i < calls; i++) {
		iterations++;
		printf("USER PID: %d PPID: %d Iteration: %d before sleeping. \n", getpid(), getppid(), iterations);
		sleep(1);
		printf("USER PID: %d PPID: %d Iteration: %d after sleeping. \n", getpid(), getppid(), iterations);
	}

	return 0;
}
