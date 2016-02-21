#include <stdio.h>
#include <sys/types.h>	/* system type defintions */
#include <sys/socket.h>	/* network system functions */
#include <netinet/in.h>	/* protocol & struct definitions */
#include <stdlib.h>	/* exit() warnings */
#include <string.h>	/* memset warnings */
//void clients();
void func(int);
#define BUF_SIZE	1024
#define LISTEN_PORT	60000
#define	SERVER_IP	"127.0.0.1"

//char client_list[10];
struct sockaddr	remote_addr;
struct sockaddr_in	my_addr,recv_addr;
int main(int argc, char *argv[]){
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


            /* create socket for listening */
    sock_listen=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock_listen < 0){
        printf("error...socket() failed\n");
        exit(0);
    }
        /* make local address structure */
    memset(&my_addr, 0, sizeof (my_addr));	/* zero out structure */
    my_addr.sin_family = AF_INET;	/* address family */
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY);  /* current machine IP */
    my_addr.sin_port = htons((unsigned short)LISTEN_PORT);
        /* bind socket to the local address */
    SO_REUSEADDR;
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
   return 0;
}

/*void func (int sock)
{
   int x;
   char buffer[1024];
   while(1){
     
   bzero(buffer,1024);
   x = read(sock,buffer,1024);
   if (x < 0)
     printf("Client %s communication has been disconnect\n",inet_ntoa(recv_addr));
   printf("Message received from %s: %s\n",inet_ntoa(recv_addr),buffer);
  // clients();
   x = write(sock,"Message successfully received\n",29);
   if (x < 0) 
     printf("error...failed to write to socket");
     
  }
*/
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
/*  
}

void clients(){
  char client_list[10]={""};
  int c;
  for(c=0;c<10;c++){
    client_list[c]=inet_ntoa(recv_addr);
    }
    printf("clients %s",client_list[c]);
}
*/
