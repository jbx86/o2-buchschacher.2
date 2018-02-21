// Master program that will take a commandline
// argument n and fork a produceer and n consumers
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int makeargv(const char *s, const char *delimiters, char ***argvp);
void forkProducer(int, int);
void forkConsumer(int, int);


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

	printf("n = %d\n", n);

	char buffArg[100] = "";
	snprintf(buffArg, 100, "%d %2d %3d", n, n, n);

	// Fork n processes
	for (i = 0; i < n; i++) {
		if ((pid = fork()) == 0) {
			if (i == 1)
				forkProducer(i, n);
			else
				forkConsumer(i, n);
		}
	}

	return 0;
}

void forkProducer(int i, int n) {
	// Spawn off a producer with max number of children and which child it is
	char buffArg1[100];
	char buffArg2[100];
	snprintf(buffArg1, 100, "%d", i);
	snprintf(buffArg2, 100, "%d", n);
	execlp("./producer", "producer", buffArg1, buffArg2, NULL);
}

void forkConsumer(int i, int n) {
	// Spawn off a consumer with max number of children and which child it is
	char buffArg1[100];
	char buffArg2[100];
	snprintf(buffArg1, 100, "%d", i);
	snprintf(buffArg2, 100, "%d", n);
	execlp("./consumer", "consumer", buffArg1, buffArg2, NULL);
}
