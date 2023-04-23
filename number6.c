#include <stdio.h>
#include <arpa/inet.h>

int main() {
    int ip_int = -1;
    struct in_addr ip_addr;

    // Assign the integer value to s_addr
    ip_addr.s_addr = (in_addr_t)ip_int;

    // Print the IP address string directly using printf and inet_ntoa
    printf("IP address: %s\n", inet_ntoa(ip_addr));

    return 0;
}
