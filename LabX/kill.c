#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handle_signal(int sig) {
    printf("Child received signal %d\n", sig);
}

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        signal(SIGUSR1, handle_signal);
        pause();
    } else if (pid > 0) {
        // Parent process
        printf("Parent sending signal.\n");
        sleep(1);
        kill(pid, SIGUSR1);
    } else {
        perror("failed");
        return 1;
    }

    return 0;
}
