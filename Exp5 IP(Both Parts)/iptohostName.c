#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
    char ip[100];
    printf("Enter IP address: ");
    scanf("%s", ip);

    struct in_addr addr;
    inet_aton(ip, &addr);

    struct hostent *he = gethostbyaddr(&addr, sizeof(addr), AF_INET);
    if (he == NULL) {
        printf("Reverse lookup failed\n");
        return 1;
    }

    printf("Host name: %s\n", he->h_name);

    return 0;
}
