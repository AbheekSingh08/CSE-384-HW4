#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signal);

int main() {
    int pid = getpid();
    printf("My PID is %d\n", pid);

    signal(SIGUSR1, sig_handler);

    while (1) {
        pause();
    }
}

void sig_handler(int signal) {
    static int recsignal = 0;

    // Block SIGUSR1.
    sigset_t blks;
    sigemptyset(&blks);
    sigaddset(&blks, SIGUSR1);
    sigprocmask(SIG_BLOCK, &blks, NULL);

    recsignal = recsignal + 1;

    if (recsignal < 5) {
        printf("Signal %d received. Waiting for more signals...\n", recsignal);

        // Unblock SIGUSR1.
        sigprocmask(SIG_UNBLOCK, &blks, NULL);

    } else {
        printf("Five signals received.\n");
        exit(0);
    }
}
