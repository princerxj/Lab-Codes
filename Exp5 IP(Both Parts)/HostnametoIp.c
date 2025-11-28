#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
    char host[100];
    printf("Enter hostname: ");
    scanf("%s", host);

    struct hostent *he = gethostbyname(host);
    if (he == NULL) {
        printf("Lookup failed\n");
        return 1;
    }

    struct in_addr **addr_list = (struct in_addr **) he->h_addr_list;

    printf("IP Address: %s\n", inet_ntoa(*addr_list[0]));

    return 0;
}
