#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void handler(int sig) {
    	if (sig == SIGUSR1) {
        	printf("Child: Received SIGUSR1 from parent!\n");
        	exit(0); // exit after receiving the signal
    	}
}

int main() {

	pid_t pid;

    	// Fork to create a child process
    	pid = fork();
    	if (pid < 0) {
        	perror("Fork failed!");
        	return 1;
    	}

	// child process
    	if (pid == 0) {
        	printf("Child: Waiting for a signal from parent...\n");
        	signal(SIGUSR1, handler); // register signal handler

		// wait for a signal
        	while (1) {
            	pause();
        	}
	//parent process
    	} else {

        	printf("Parent: Sending SIGUSR1 to child... (PID: %d)\n", pid);
        	sleep(1); // give the child process some time to set up the signal handler
        	kill(pid, SIGUSR1); // send SIGUSR1 to the child
        	wait(NULL); // wait for the child process to terminate
        	printf("Parent: Child process terminated...\n");
    	}

    	return 0;
}
