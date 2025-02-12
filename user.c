#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Author: Dat Nguyen
// Date: 2/12/2025
// user.c is a program that is called from oss.c and takes in an integer argument and do iterations based on the input. The iterations display the user PID and the parents PID before sleeping and then after sleeping.

int main(int argc, char **argv) {
	int calls = 0;

	// Input validation
	if (argc < 2) {
		printf("Error: Please input an integer \n");
		return(EXIT_FAILURE);
	}

	// Exit if input integer is less than zero.
	calls = atoi(argv[1]);
	if (calls <= 0) {
		printf("Error: Please input a positive integer. \n");
		return(EXIT_FAILURE);
	}

	return 0;
}
