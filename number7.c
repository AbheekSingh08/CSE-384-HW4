#include <stdio.h>
#include <arpa/inet.h>

const char *process_ip_address(const char *ip_address_string, uint32_t *ip_address_integer) {
    struct in_addr in_address;
    int result = inet_aton(ip_address_string, &in_address);

    if (result) {
        *ip_address_integer = ntohl(in_address.s_addr);
        return "The integer value of the IP address %s is %u\n";
    } else {
        return "Error converting IP address: %s\n";
    }
}

int main() {
    const char *ip_address_string = "225.2.0.0";
    uint32_t ip_address_integer;
    const char *format_string;

    format_string = process_ip_address(ip_address_string, &ip_address_integer);
    printf(format_string, ip_address_string, ip_address_integer);

    return 0;
}
