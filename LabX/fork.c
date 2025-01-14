#include <stdio.h>
#include <unistd.h>

int main() {
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            printf("Child with PID: %d\n", getpid());
            break;
        } else if (pid > 0) {
            printf("Parent with PID: %d\n", getpid());
        } else {
            perror("Failed");
            return 1;
        }
    }
    return 0;
}
