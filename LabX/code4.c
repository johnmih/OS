#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

    	FILE *file;
    	file = fopen("PIDs.txt", "w");
    	if (file == NULL) {
        	perror("Failed to open file");
        	exit(EXIT_FAILURE);
    	}

    	pid_t pid = fork();
    	if (pid < 0) {
        	// error occurred
        	perror("Fork failed");
        	fclose(file);
        	exit(EXIT_FAILURE);
    	} else if (pid == 0) {
        	// child process
        	fprintf(file, "Child PID: %d\n", getpid());
        	fclose(file);
    	} else {
        	// parent process
        	wait(NULL); // Wait for the child process to finish
        	fprintf(file, "Parent PID: %d\n", getpid());
        	fclose(file);
    	}

    	return 0;
}
