#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h> 

int main(int argc, char *argv[])
{
    int sockfd = 0, n = 0;
    char mensaje[1024];
    struct sockaddr_in direccion_servidor; 

    if(argc != 2){
		printf("Se debe proporcionar la direccion del servidor. \n",argv[0]);
	    return 1;
    } 

    memset(mensaje, '0',sizeof(mensaje));
    
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		printf("No se pudo crear el socket.\n");
		return 1;
    } 

    memset(&direccion_servidor, '0', sizeof(direccion_servidor)); 

    direccion_servidor.sin_family = AF_INET;
    direccion_servidor.sin_port = htons(5000); 

    if(inet_pton(AF_INET, argv[1], &direccion_servidor.sin_addr)<=0){
		printf("Ha ocurrido un error.\n");
	    return 1;
    } 

    if( connect(sockfd, (struct sockaddr *)&direccion_servidor, sizeof(direccion_servidor)) < 0){
		printf("No se pudo conectar al servidor.\n");
	    return 1;
     } 
	printf("PID Cliente: %d\n", getpid());

    while ( (n = read(sockfd, mensaje, sizeof(mensaje))) > 0){
		mensaje[n] = 0;
		printf("%s\n", mensaje);
    } 

    if(n < 0){
		printf("Error al leer el mensaje\n");
    } 

    return 0;
}
