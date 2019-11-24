#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <time.h> 
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	    int listenfd = 0, connfd = 0;
	    struct sockaddr_in direccion; 

	    char mensaje[1025];

	    listenfd = socket(AF_INET, SOCK_STREAM, 0);

	    memset(&direccion, '0', sizeof(direccion));
	    memset(mensaje, '0', sizeof(mensaje)); 

	    direccion.sin_family = AF_INET;
	    direccion.sin_addr.s_addr = htonl(INADDR_ANY);
	    direccion.sin_port = htons(5000); 

	    bind(listenfd, (struct sockaddr*)&direccion, sizeof(direccion)); 
	
	    listen(listenfd, 10); 
		printf("PID Servidor: %d\n", getpid());

	    while(1){
			connfd = accept(listenfd, (struct sockaddr*)NULL, NULL); 
			
			pid_t hijo = fork();
			if (hijo == 0){
				snprintf(mensaje, sizeof(mensaje), "Este es el mensaje recibido\n");
				write(connfd, mensaje, strlen(mensaje)); 
				close(connfd);
				printf("PID Hijo: %d", getpid());
				return 0;
			}	
			wait(&hijo);
			close(connfd);
			sleep(1);
	    }
}
