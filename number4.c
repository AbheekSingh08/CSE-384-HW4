#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void wait(int signum) {
// waiting til just after alarm
}

int main() {
    alarm(10);
    signal(SIGALRM, wait);

    pause();

    printf("Delayed message\n");
    return 0;
}
