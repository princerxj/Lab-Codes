#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int client_socket;
    char buffer[1024];
    struct sockaddr_in server_addr;

    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    printf("Connected to server!\n");

    while (1) {
        printf("Client: ");
        fgets(buffer, sizeof(buffer), stdin);
        send(client_socket, buffer, strlen(buffer), 0);

        recv(client_socket, buffer, sizeof(buffer), 0);
        printf("Server: %s", buffer);
    }

    close(client_socket);
    return 0;
}
