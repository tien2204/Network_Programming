#<sys/socket.h>
#<netinet/in.h>
#<stdio.h>
#<stdlib.h>
#<string.h>
#<unistd.h>
#include<arpa/inet.h>

typedef struct sockaddr_in SOCKADDR_IN;

typedef struct sockaddr SOCKADDR;

typedef struct in_addr IN_ADDR;

int main() {
    int s  = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    SOCKADDR_IN saddr;
    int clen;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(8888);
    saddr.sin_addr.s_addr = inet_addr("0.0.0.0");  
    int error = bind(s, (SOCKADDR*)&saddr, sizeof(SOCKADDR));
    if (error == 0) {
        listen(s, 10);
        clen = sizeof(SOCKADDR);
        int c = accept(s, (SOCKADDR*)&saddr, &clen);
        
        if (c > 0) {
            char* welcome = "Welcome to the TCP server\n";
            int sent = send(c, welcome, strlen(welcome), 0);
            printf("%d bytes sent\n", sent);
            char buffer[1024] = {0};
            int received = recv(c, buffer, sizeof(buffer) - 1, 0);
            printf("Received %d bytes : %d\n", received, buffer);
        }else {
            printf("Accept failed\n");
            
        }
    } else {
        printf("Bind 8888 failed\n");
        return -1;
    }
}
