#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t p = vfork(); // Call to vfork system call
    if (p == -1)
        printf("Error occurred while calling vfork()\n");
    else if (p == 0)
        printf("This is the child process with ID=%d\n", getpid());
    else
        printf("This is the parent process with ID=%d\n", getpid());
    return 0;
}
