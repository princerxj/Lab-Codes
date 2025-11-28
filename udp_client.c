#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[1024];
    socklen_t addr_len = sizeof(server_addr);

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    printf("Enter message: ");
    fgets(buffer, sizeof(buffer), stdin);

    sendto(sock, buffer, strlen(buffer), 0,
           (struct sockaddr*)&server_addr, addr_len);

    int bytes = recvfrom(sock, buffer, sizeof(buffer), 0, NULL, NULL);

    buffer[bytes] = '\0';
    printf("Echo from server: %s\n", buffer);

    close(sock);
    return 0;
}
