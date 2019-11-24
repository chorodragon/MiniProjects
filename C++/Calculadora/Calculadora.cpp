//Calculadora

#include <stdio.h>  
#include <math.h>	//biblioteca que brinda mas opciones para realizar operaciones matematicas
#include <stdlib.h>

int main(){
	
	int x, y, m, res, di; //Variables necesarias para cualquier operacion y respuesta con numeros enteros
	char op, l;  //signo de la operacion	
	float resf, xf, yf; //variables de respuesta con numeros reales
	
	do //ciclo de repeticion para controlar cuando se sale del programa
	{
	system ("cls"); //limpia la pantalla en caso de segunda ejecucion
	printf ("Universidad Mariano Galvez              Nombre: Osbel Antonio Estrada Gutierrez\n");
	printf ("Algoritmos                              Seccion: A     No.Carnet: 5990-14-10891\n");
	printf ("--------------------------------------------------------------------------------");
	printf ("********************************************************************************");
	printf ("********************************Calculadora*************************************");
	printf ("********************************************************************************"); //presentacion de datos y nombre de programa
	printf ("\n");
	
	printf ("Intrucciones de Uso: Ingrese el primer numero de la operacion, luego se debe\n");
	printf ("                     escribir el signo de la operacion que desea realizar\n");
	printf ("                     (+, -, *, /, div, mod) Para concluir se debe introducir el");
	printf ("                      ultimo numero de la operacion.\n\n");		//Instrucciones de operacion
	
	m = 0;  //variable que utiliza el ciclo de repeticion
	
	printf("Ingrese el primer numero: "); //Ingreso del primero numero de la operacion
	scanf("%i", &x);//se guarda el primer numero
	
	printf("Ingrese el signo de la operacion: "); //ingreso del signo de la operacion
	scanf("%s", &op);
	
	printf("Ingrese el segundo numero: ");//Ingreso del segundo numero de la operacion
	scanf("%i", &y);//se guarda el segundo numero
	
	if (op == '+'){ //operacion en caso de que signo sea de suma
		res = x+y;
		printf ("\nEl resultado es: %i. \n\n", res);
	}
	else if (op == '-'){ //operacion en caso de que el signo sea de resta
		res = x - y;
		printf ("\nEl resultado es: %i. \n\n", res);
	}
	else if (op == '*'){ //operacion en caso de que el signo sea de multiplicacion
		res = x * y;
		printf ("\nEl resultado es: %i. \n\n", res);
	}
	else if(op == '/'){ //operacion en caso de que el signo sea de division
		xf = x;
		yf = y;
		resf = xf / yf;
		printf ("\nEl resultado es: %f. \n\n", resf);
	}
	else if(op == 'm'){ //operacion en caso de que el signo sea mod (resto)
		res = x % y;
		printf ("\nEl resultado es: %i. \n\n", res);
	}
	else if(op == 'd'){ //operacion en caso de que el signo sea div (division exacta)
		di = x % y;
		res = (x - di) / y;
		printf ("\nEl resultado es: %i. \n\n", res);
	}
	else { //operacion en caso de que el signo sea invalido
		printf ("\nEl signo de la operacion no es valida. \n\n");
		system ("pause");
	}
	
	printf ("\nDesea realizar otra operacion? s/n \n");	//pregunta para reinicio de programa
	scanf ("%s", &l);
	
	if (l == 'n'){			//decicion para determinar si el ciclo de repeticion se repite o no.
		printf ("Gracias por utilizar esta calculadora\n\n");
	}
	else {
		m = 1;
	}
	
	
	} while (m == 1); //cierre del ciclo de repeticion
	
	system ("pause"); //pausa el programa hasta que el usuario oprima una tecla
	return 0; //Se le regresa al int main el valor de 0
} //fin del programa
