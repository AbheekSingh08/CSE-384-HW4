#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void delayed_message(int seconds, const char* message)
{
    signal(SIGALRM, [](int sig){ printf("%s\n", message); });

    alarm(seconds);

    pause();
}

int main()
{
    delayed_message(10, "Delayed message");

    return 0;
}
