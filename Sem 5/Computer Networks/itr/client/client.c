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
        struct sockaddr_in       servaddr;
        if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
                perror("socket creation failed");
                exit(EXIT_FAILURE);
        }
        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(PORT);
        servaddr.sin_addr.s_addr = INADDR_ANY;
        int n, len;
        do
        {
                printf("Message to send (q to quit): ");
                scanf("%s",msg);
                sendto(sockfd,(const char *)msg, strlen(msg),MSG_CONFIRM, (const struct sockaddr *) &servaddr,sizeof(servaddr));
                n = recvfrom(sockfd, (char *)buffer, MAXLINE,MSG_WAITALL, (struct sockaddr *) &servaddr,&len);
                buffer[n] = '\0';
                printf("Server : %s\n", buffer);
        }while(msg[0]!='q');
        close(sockfd);
        return 0;
}
