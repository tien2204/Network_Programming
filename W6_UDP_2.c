#<sys/socket.h>
#<netinet/in.h>
#<stdio.h>
#<stdlib.h>
#<string.h>
#<unistd.h>
#include<arpa/inet.h>

// chinh file launch.json cho debug

typedef struct sockaddr_in SOCKADDR_IN;

typedef struct sockaddr SOCKADDR;

typedef struct in_addr IN_ADDR;

int main() {
    int d = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    SOCKADDR_IN daddr, caddr;
    int clen;
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(8888);
    saddr.sin_addr.s_addr = inet_addr("0.0.0.0");  
    int error = bind(d, (SOCKADDR*)&saddr, sizeof(SOCKADDR));
    if (error == 0) {
        char* welcome = "Welcome to the UDP server\n";
        char buffer[1024] = {0};
        caddr.sin_family = AF_INET;
        caddr.sin_port = htons(8888);
        caddr.sin_addr.s_addr = inet_addr("255.255.255.255");
        int on  = 1;
        setsockopt(d, SOL_SOCKET, SO_BROADCAST, &on);
        sendto(d, welcome, strlen(welcome), 0, (SOCKADDR*)&caddr, sizeof(SOCKADDR));
        int receive = recvfrom(d, (void*)buffer, sizeof(buffer) - 1, 0, (SOCKADDR*)&caddr, &clen);
        printf("Received %d bytes : %s\n", receive, buffer);
        sendto(d, welcome, strlen(welcome), 0, (SOCKADDR*)&caddr, sizeof(SOCKADDR));
        close(d);
    }else {
        printf("Failed to bind.\n");
    }
    
}
