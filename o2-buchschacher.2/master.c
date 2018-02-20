// Master program that will take a commandline
// argument n and fork a produceer and n consumers
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	pid_t pid;
	int n = 10;

	if (argc > 2) {
		fprintf(stderr, "Usage: %s n", argv[0]);
	}

	if (argc == 1)
		n = 10;
	else
	{
		n = atoi(argv[1]);
		if (n > 20)
			n = 20;
		else if (n < 1) {
			fprintf(stderr, "Invalid input '%s'\n", argv[1]);
			return 1;
		}
	}
	fprintf(stderr, "%d\n", n);

/*
	pid = fork();
	if (pid == 0) {
		//
	}
	else {
		//
	}
	//produce
	//consummer
*/
}

