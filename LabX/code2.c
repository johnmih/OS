#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 128

int main() {

	// two file descriptors
	int pipefd[2];
    	pid_t pid;
    	char buffer[BUFFER_SIZE];
    	if (pipe(pipefd) == -1) {
        	perror("Pipe creation failed!");
        	return 1;
    	}

    	pid = fork();
    	if (pid < 0) {
        	perror("Fork failed!");
        	return 1;
    	}

    	// child process
    	if (pid == 0) {

		// close unused write end
        	close(pipefd[1]);  

        	// read message from the pipe
        	ssize_t bytesRead = read(pipefd[0], buffer, BUFFER_SIZE);
        	if (bytesRead > 0) {
            		buffer[bytesRead] = '\0';
            		printf("Child received: %s\n", buffer);
        	} else {
            		printf("Child: No message received\n");
        	}

		// close read end
        	close(pipefd[0]);
	// parent process
    	} else {
		// close unused read end
        	close(pipefd[0]);

        	const char* message = "Hello from parent!";
        	printf("Parent sending: %s\n", message);
        	write(pipefd[1], message, strlen(message));

		// close write end
        	close(pipefd[1]);

        	// wait for the child to finish
       	 	wait(NULL);
    	}

	return 0;
}
