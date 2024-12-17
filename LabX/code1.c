#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {

	printf("ORIGINAL PROCESS: PID = %d \n\n", getpid());
	for (int i=0; i<3; i++) {

		printf("FORK NUMBER %d \n", i+1);
		pid_t pid = fork();

		if (pid < 0) {
			perror("Fork failed!");
			return 1;
		} else if (pid == 0) {
			printf("Child process: PID = %d, Parent PID = %d \n", 
				getpid(), getppid());
		} else {
			printf("Parent process: PID = %d, Child PID = %d \n", 
				getpid(), pid);
		}
		sleep(1);
	}
	sleep(2);
	return 0;
}
