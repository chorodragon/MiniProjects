#include <stdio.h>

struct dato{
	int pos;
	int pos2;
}vector[6];

void menu();
void ingresar();
void mostrar();
void mostrar_todo();
int op=0, inicio = 0, fin = 0;

int main(){

	while (op != 4){
		menu();
		switch(op){
			case 1: ingresar();  break;
			case 2: mostrar(); break;
			case 3: mostrar_todo(); break;
			case 4: op=4; break;
			default: printf("El numero de opcion ingresado no es valido"); break;
		}
	}
}

void menu(){
	printf("\nIngrese el numero de operacion que desea realizar");
	printf("\n1.Ingresar dato a la cola.");
	printf("\n2.Mostrar datos de la cola.");
	printf("\n3.Mostrar toda la cola.");
	printf("\n4.Salir");
	printf("\n>>:");
	scanf("%d", &op);
}

void mostrar_todo(){
	int aux, i=1;	
	
	if(inicio == fin){
		printf("\nLa cola esta vacia\n");
		return;
	}

	if(inicio < fin){
		for(aux=inicio; aux<fin; aux++){
			printf("\nPosicion #%d:\n", i);
			printf("Pos: %d\n", vector[aux].pos);
			printf("Pos2: %d", vector[aux].pos2);
			i++;
		}
	}
	else{
		aux = inicio;

		while(aux!=fin){
			if(aux <= 5){
				printf("\nPosicion #%d\n", i);
				printf("Pos: %d\n", vector[aux].pos);
				printf("Pos2: %d", vector[aux].pos2);
				i++;
				aux++;
			}
			else{
				aux = 0;
			}
		}
	}

}

void ingresar(){
	if(fin == 5){
		if(inicio == 0){
			printf("\nLa cola esta llena\n");
		}
		else{
		    	printf("Ingrese el valor en pos: ");
	        	scanf("%d", &vector[fin].pos);
	     		printf("Ingrese el valor en pos2: ");	
			scanf("%d", &vector[fin].pos2);
			fin = 0;
		}
	}
	else{
		if(fin+1 == inicio){
			printf("\nLa cola esta llena.\n");
		}
		else{
                        printf("Ingrese el valor en pos: ");
			scanf("%d", &vector[fin].pos);
                        printf("Ingrese el valor en pos2: ");  				                    scanf("%d", &vector[fin].pos2);					                fin++;
		}
	}
}

void mostrar(){
	if(inicio==fin){
		printf("La cola esta vacia.");
	}
	else{
		printf("\nPos: %d\n", vector[inicio].pos);
		printf("\nPos2: %d\n", vector[inicio].pos2);
		if(inicio == 5){
			inicio = 0;
		}
		else{
			inicio++;
		}
	}
}
