#include <stdio.h>
#include <arpa/inet.h>

int main() {
    int ip_address = -1;
    struct in_addr in_address;
    char *ip_address_string;

    in_address.s_addr = (in_addr_t)ip_address;
    ip_address_string = inet_ntoa(in_address);

    printf("%s\n", ip_address_string ? ip_address_string : "Error converting -1 to an IP address.");

    return 0;
}
