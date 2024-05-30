#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h> // For exit()

int main() {
    pid_t child_pid;

    // Fork a child process
    child_pid = fork();

    // Check for fork failure
    if (child_pid == -1) {
        perror("fork failed"); // Print error message
        exit(EXIT_FAILURE);    // Exit with failure status
    } 
    // Child process
    else if (child_pid == 0) {
        printf("Child process: PID = %d\n", getpid());
    } 
    // Parent process
    else {
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), child_pid);
    }

    return 0; // Exit with success status
}
