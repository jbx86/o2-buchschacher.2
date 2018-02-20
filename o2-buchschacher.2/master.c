// Master program that will take a commandline
// argument n and fork a produceer and n consumers
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	pid_t pid;
	int i;
	int n = 10;
	int x = 7;
	
	//char *buffer;

	char *cmd = "./consumer";
	char *buff[] = {"./consumer", "4", "5", NULL};

	fprintf(stderr, "%s\n", buff[2]);
	sprintf(buff[2], "%d", n);
	fprintf(stderr, "%s\n", buff[2]);

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
	
	for (i = 0; i <= n; i++) {
		fprintf(stderr, "%d", i);
		pid = fork();
		if (pid == 0) {
			// char *cmd = "./consumer";
			//char *buff[] = {"./consumer", "4", "5", NULL};
			execvp(cmd, buff);		
		}
		wait();		
/*
		pid = fork();
		if (i == 0) {
			cmd = "producer";
			buff[0] = "producer";
		}
		else {
			cmd = "consumer";
			buff[0] = "consumer";
		}
		execvp(cmd, buff);
		*/
	}

}

