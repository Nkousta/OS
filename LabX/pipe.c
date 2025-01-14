#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    char message[] = "Hello";
    char buffer[100];

    if (pipe(fd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
    } else if (pid > 0) {
        // Parent process
        write(fd[1], message, strlen(message) + 1);
        printf("Parent sent: %s\n", message);
    } else {
        perror("failed");
        return 1;
    }

    return 0;
}
