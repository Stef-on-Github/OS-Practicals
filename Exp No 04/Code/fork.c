#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t child_pid; // Variable to store the child process ID

    child_pid = fork(); // Fork a child process

    if (child_pid < 0) { // Fork failed
        fprintf(stderr, "Fork failed\n");
        return 1; // Exit with failure status
    } else if (child_pid == 0) { // Child process
        printf("Child process: PID = %d\n", getpid());
    } else { // Parent process
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), child_pid);
    }

    return 0; // Exit with success status
}
