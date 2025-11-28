#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];
    socklen_t addr_len = sizeof(client_addr);

    server_fd = socket(AF_INET, SOCK_DGRAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    while (1) {
        int bytes = recvfrom(server_fd, buffer, sizeof(buffer), 0,
                             (struct sockaddr*)&client_addr, &addr_len);

        printf("Client says: %.*s", bytes, buffer);

        sendto(server_fd, buffer, bytes, 0,
               (struct sockaddr*)&client_addr, addr_len);
    }

    close(server_fd);
    return 0;
}
