#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
    struct hostent *hst = gethostbyname("ecs.syracuse.edu");

    if (hst == NULL) {
        printf("Error resolving domain name.\n");
        return 1;
    }

    int i = 0;
    char *ip_address;

    while (hst->h_addr_list[i] != NULL) {
        struct in_addr *addr = (struct in_addr *)hst->h_addr_list[i];
        ip_address = inet_ntoa(*addr);
        printf("%s\n", ip_address);
        i++;
    }

    return 0;
}
