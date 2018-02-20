// Master program that will take a commandline
// argument n and fork a produceer and n consumers
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int makeargv(const char *s, const char *delimiters, char ***argvp);

int main(int argc, char *argv[]) {
	pid_t pid;
	int i = 0;
	int n = 10;
	int x = 7;

	char delim[] = " \t";
	char **myargv;
	int numtokens;
	char *strProd = "./producer 1 2";
	char *strCons = "./consumer 3 4";

	
	// Determine n value from commandline
	if (argc > 2) {
		fprintf(stderr, "Usage: %s n", argv[0]);
	}

	if (argc == 1) {
		n = 10;		// Default to 10
	}
	else
	{
		n = atoi(argv[1]);
		if (n > 20)
			n = 20;		// Restrict to 20 processes
		else if (n < 1) {
			fprintf(stderr, "Invalid input '%s'\n", argv[1]);
			return 1;
		}
	}


	// Fork n processes
	for (i = 1; i < n; i++) {
		fprintf(stderr, "%d", i);
		pid = fork(); //Fork proccess
		if (pid == 0) {
			//Execute children as producer or consumer(s)
			if (i == 1) {
				// Construct producer arguments
				if (makeargv(strProd, delim, &myargv) == -1)
					fprintf(stderr, "Failed to construct argument array\n");
				else
					execvp(myargv[0], &myargv[0]);
			}
			else {
				// Construct consumer arguments
				if (makeargv(strCons, delim, &myargv) == -1)
					fprintf(stderr, "Failed to construct argument array\n");
				else
					execvp(myargv[0], &myargv[0]);
			}
		}
		wait();
	}


/*
	//Test output of variabls
	fprintf(stderr, "process %d executed as 'master'\n", i++);
	fprintf(stderr, "process %d executed as 'producer'\n", i++);
	while (i < n) {
		fprintf(stderr, "process %d executed as 'consumer'\n", i++);	
	}
*/

	

}

