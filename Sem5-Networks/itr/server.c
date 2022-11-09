#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define PORT     8090
#define MAXLINE 1024
int main() {
        int sockfd;
        char buffer[MAXLINE];
        char msg[40];
        struct sockaddr_in servaddr, cliaddr;
        if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
                perror("socket creation failed");
                exit(EXIT_FAILURE);
        }
        memset(&servaddr, 0, sizeof(servaddr));
        memset(&cliaddr, 0, sizeof(cliaddr));
        servaddr.sin_family = AF_INET; // IPv4
        servaddr.sin_addr.s_addr = INADDR_ANY;
        servaddr.sin_port = htons(PORT);
        if ( bind(sockfd, (const struct sockaddr *)&servaddr,
                                sizeof(servaddr)) < 0 )
        {
                perror("bind failed");
                exit(EXIT_FAILURE);
        }
        int len, n;
        do
        {
                printf("Message to send(q to quit): ");
                scanf("%s",msg);
                len = sizeof(cliaddr); //len is value/resuslt
                n = recvfrom(sockfd, (char *)buffer, MAXLINE,MSG_WAITALL, ( struct sockaddr *) &cliaddr,&len);
                buffer[n] = '\0';
                printf("Client : %s\n", buffer);
                sendto(sockfd, (const char *)msg, strlen(msg),
                                MSG_CONFIRM, (const struct sockaddr *) &cliaddr,len);
        }while(msg[0]!='q');
        return 0;
}
