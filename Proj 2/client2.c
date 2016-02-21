#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE	1024
#define	SERVER_IP	"127.0.0.1"
#define SERVER_PORT	60000
#define PEER_PORT	50000
//#define PEER_IP
void serve();

    int 	            sock_listen,sock_recv;
    struct sockaddr_in	    my_addr,recv_addr;
    int               	    y,addr_size,bytes_received;
    fd_set                  readfds;
    //struct timeval	    timeout={0,0};
    int	                    incoming_len;
    struct sockaddr	    remote_addr;
    int	                    recv_msg_size;
    char                    buf[BUF_SIZE];
    int	                    select_ret;

int main(int argc, char *argv[]){
    int	sock_send;
    struct sockaddr_in	addr_send,addr2_send;
    int	i,x,n;
    char text[80],buf[BUF_SIZE],IP[20];
    int	send_len,bytes_sent;


    sock_send=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock_send < 0){
        printf("error...socket failed\n");
        exit(0);
    }


    memset(&addr_send, 0, sizeof (addr_send));
    addr_send.sin_family = AF_INET; 
    addr_send.sin_addr.s_addr = inet_addr(SERVER_IP);
    addr_send.sin_port = htons((unsigned short)SERVER_PORT);
    
/*

    memset(&addr2_send, 0, sizeof (addr2_send));
    addr2_send.sin_family = AF_INET; 
    addr2_send.sin_addr.s_addr = inet_addr(IP);
    addr2_send.sin_port = htons((unsigned short)PEER_PORT);
    
     x=connect(sock_send, (struct sockaddr *) &addr_send, sizeof (addr_send));
    if (x < 0){
        printf("error...connection failed\n");
        exit(0);
    }

  */  
    i=connect(sock_send, (struct sockaddr *) &addr_send, sizeof (addr_send));
    if (i < 0){
        printf("error...connection failed\n");
        exit(0);
    }
    serve();
    while (1){
	    //serve();

        printf("Enter message to send: ");
        scanf("%s",text);
        if (strcmp(text,"Exit") == 0)
            break;

        strcpy(buf,text);
        send_len=strlen(text);
        bytes_sent=send(sock_send,buf,send_len,0);
	
	bzero(buf,1024);
	n = read(sock_send,buf,1024);
	if (n < 0) 
         printf("ERROR reading from socket");
	printf("%s\n",buf);

	
    }
    

    close(sock_send);
    
}

void serve()
{
   /* int 	            sock_listen,sock_recv;
    struct sockaddr_in	    my_addr,recv_addr;
    int               	    i,addr_size,bytes_received;
    fd_set                  readfds;
    struct timeval	    timeout={0,0};
    int	                    incoming_len;
    struct sockaddr	    remote_addr;
    int	                    recv_msg_size;
    char                    buf[BUF_SIZE];
    int	                    select_ret;
*/
    sock_listen=socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock_listen < 0){
        printf("error...socket failed\n");
        exit(0);
    }
    memset(&my_addr, 0, sizeof (my_addr));	
    my_addr.sin_family = AF_INET;	
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY);  
    my_addr.sin_port = htons((unsigned short)PEER_PORT);
        
    y=bind(sock_listen, (struct sockaddr *) &my_addr, sizeof (my_addr));
    if (y < 0){
        printf("error...bind failed\n");
        exit(0);
    }
    
    y=listen(sock_listen, 5);
    if (y < 0)
    {
        printf("error... listen failed\n");
        exit(0);
    }

        
    addr_size=sizeof(recv_addr);
    sock_recv=accept(sock_listen, (struct sockaddr *) &recv_addr, &addr_size);

    while (1){
        bytes_received=recv(sock_recv,buf,BUF_SIZE,0);
        buf[bytes_received]=0;
        printf("Received: %s\n",buf);
    if (strcmp(buf,"Finish") == 0)
        break;
    }

    close(sock_recv);
    close(sock_listen);
}