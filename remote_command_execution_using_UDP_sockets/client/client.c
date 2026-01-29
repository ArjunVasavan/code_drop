#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/wait.h>


#define PORT 2000
#define IP "127.0.0.1"

typedef struct 
{

    char data_buf[65];

    int pack_no;

    int n_flag;

} data_packet ;


typedef struct 
{

    char command[100];

    int no_of_times;

} command_request_packet;

typedef struct 
{

    char data[65];

    int pack_no;

} acknowledgement_packet;

int main(int argc, char** argv) 
{
    
    data_packet data;
    command_request_packet cmd;
    acknowledgement_packet ack;

    printf("Enter the command: ");
    scanf("%s",cmd.command);
    printf("Read: %s\n",cmd.command);

    printf("Enter no. of times to be executed: ");
    scanf("%d",&cmd.no_of_times);

    int sockfd = socket(AF_INET,SOCK_DGRAM,0);

    if ( sockfd < 0 ) 
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(IP);

    sendto(sockfd,&cmd,sizeof(cmd),0,(struct sockaddr*)&server_addr,sizeof(server_addr));

    struct sockaddr_in from_addr;
    socklen_t from_len = sizeof(from_addr);
    int recv_data_buf_len = 1;
    while ( true ) {

        int recieved = recvfrom(sockfd,&data,sizeof(data),0,(struct sockaddr*)&from_addr,&from_len); // NOTE: recieved always print 76 here

        recv_data_buf_len = data.n_flag;

        ack.pack_no = data.pack_no;
        sendto(sockfd,&ack,sizeof(ack),0,(struct sockaddr*)&server_addr,sizeof(server_addr));

        write(STDOUT_FILENO, data.data_buf, data.n_flag);

        if ( data.n_flag != 64 ) 
        {
            break;
        }

    }

    close(sockfd);
}
