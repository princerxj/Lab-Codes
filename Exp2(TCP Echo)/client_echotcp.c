#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[1024];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr));

    printf("Enter message: ");
    fgets(buffer, sizeof(buffer), stdin);

    send(sock, buffer, strlen(buffer), 0);

    int bytes = recv(sock, buffer, sizeof(buffer), 0);
    buffer[bytes] = '\0';

    printf("Echo from server: %s\n", buffer);

    close(sock);
    return 0;
}
