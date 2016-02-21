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
void func();
struct sockaddr	remote_addr;
struct sockaddr_in	my_addr,recv_addr;

     int	sock_listen,sock_recv;
    //struct sockaddr_in	my_addr,recv_addr;
    int i,addr_size,bytes_received,pid;
    fd_set readfds;
    //struct timeval	timeout={0,0};
    int	incoming_len;
    //struct sockaddr	remote_addr;
    //int	recv_msg_size;
    //char buf[BUF_SIZE];
    int	select_ret;

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
  */  if (x < 0){
        printf("error...connection failed\n");
        exit(0);
    }

  
    i=connect(sock_send, (struct sockaddr *) &addr_send, sizeof (addr_send));
    if (i < 0){
        printf("error...connection failed\n");
        exit(0);
    }
  //  serve();
    while (1){
        
        
        
        fork();
    serve();
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
 
    sock_listen=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock_listen < 0){
        printf("error...socket() failed\n");
        exit(0);
    }
        /* make local address structure */
    memset(&my_addr, 0, sizeof (my_addr));	/* zero out structure */
    my_addr.sin_family = AF_INET;	/* address family */
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY);  /* current machine IP */
    my_addr.sin_port = htons((unsigned short)PEER_PORT);
        /* bind socket to the local address */
        
        int yes=1;
//char yes='1'; // use this under Solaris

if (setsockopt(sock_recv, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) == -1) {
    perror("setsockopt");
    exit(1);
}
        
    i=bind(sock_listen, (struct sockaddr *) &my_addr, sizeof (my_addr));
    if (i < 0){
        printf("error...bind() failed\n");
        exit(0);
    }
        /* listen ... */
    listen(sock_listen, 5);
    addr_size=sizeof(recv_addr);
    
        /* get new socket to receive data on */
	while(1){
	sock_recv=accept(sock_listen, (struct sockaddr *) &recv_addr, &addr_size);
       // bytes_received=recv(sock_recv,buf,BUF_SIZE,0);
        //buf[bytes_received]=0;
	
	if (sock_recv < 0)
        printf("error...listen() failed\n");
        //exit(0);

        pid=fork();
	if (pid<0)
	   printf("error...fork() failed\n");
	if (pid == 0)  {
           close(sock_listen);
	   
	   //client_list[0]=inet_ntoa(recv_addr);
	   //printf( " client %s\n",client_list[0]);
           func(sock_recv);
	       exit(0);
    }
	else close(sock_recv);
   }
   close(sock_listen);
}


void func(int sock)
{
   int x;
   char buffer[1024];
   while(1){
     
   bzero(buffer,1024);
   x = read(sock,buffer,1024);
   if (x < 0)
     printf("Client communication has been disconnect");
   printf("Message received: %s\n",buffer);
   x = write(sock,"I got your message",18);
   if (x < 0) 
     printf("error...failed to write to socket");
     
  }
  
}