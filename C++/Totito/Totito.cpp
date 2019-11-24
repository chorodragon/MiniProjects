#include <stdio.h>
#include <windows.h>

int comprobacion(char toto[3][3], char ficha);
void tablero(char toto[3][3], char p1[10], char p2[10], char p1_ficha, char p2_ficha);
void jugada(char toto[3][3], char player[10], char ficha);
int empate(char toto[3][3]);


int main(){
	char p1_ficha, p2_ficha, p1[10], p2[10];
	int aux, fila, columna, g, res;
	char toto[3][3];
	
	printf ("-----------------------------------TOTITO---------------------------------------\n\n");
	printf ("Ingrese el nombre del primer jugador: ");
	scanf ("%s", &p1);
	printf ("Ingrese el nombre del segundo jugador: ");
	scanf ("%s", &p2);
	
	do{
	aux = 0;
	printf ("Ingrese el signo que utilizara el jugador %s ", p1);
	scanf ("%s", &p1_ficha);
	if (p1_ficha == 'x'){
		p2_ficha = 'o';
		aux = 1;
	}
	else if (p1_ficha == 'o'){
		p2_ficha = 'x';
		aux = 1;
	}
	else {
		printf ("El simbolo ingresado no es valido\n");
		aux = 0;
	}
	}while (aux == 0);
	
	do {
	
	for (fila = 0; fila <= 2; fila ++){
		for (columna = 0; columna <= 2; columna ++){
			toto[fila][columna] = ' ';
		}
	}
	
	do {
	system ("cls");
	tablero (toto, p1, p2, p1_ficha, p2_ficha);
	jugada (toto, p1, p1_ficha);
	g = comprobacion (toto, p1_ficha);
	aux = 0;
	if (g == 0){
		g = empate(toto);
	}
	while(g == 0 && aux == 0){
	system ("cls");
	tablero (toto, p1, p2, p1_ficha, p2_ficha);
	jugada (toto, p2, p2_ficha);
	g = comprobacion (toto, p2_ficha);
	aux = 1;
	}
	
	}while (g == 0);
	system ("cls");
	tablero (toto, p1, p2, p1_ficha, p2_ficha);
	printf ("\n\n\n");
	if (g == 1){
		printf ("El ganador es %s", p1);
	}
	if (g == 2){
		printf ("El ganador es %s", p2);
	}
	if (g == 3){
		printf ("El juego ha terminado en empate");
	}

	do {
	printf ("\n\n 1. Si");
	printf ("\n 2. No");
	printf ("\n Desea volver a jugar: ");
	scanf ("%i", &res);
	
	if (res != 1) {
		if (res != 2){
			printf ("La respuesta ingresada no es valida");
			res = 3;
		}
	}
	} while (res == 3);

	}while (res == 1);
	
	system ("pause");
	return 0;
}

int comprobacion (char toto[3][3], char ficha){
	int g;
	g = 0;
	if (toto [0][0] == ficha && toto [0][1] == ficha && toto [0][2] == ficha){
		g = 1;
	}
	if (toto [0][0] == ficha && toto [1][1] == ficha && toto [2][2] == ficha){
		g = 1;
	}
	if (toto [0][0] == ficha && toto [1][0] == ficha && toto [2][0] == ficha){
		g = 1;
	}
	if (toto [1][0] == ficha && toto [1][1] == ficha && toto [1][2] == ficha){
		g = 1;
	}
	if (toto [0][1] == ficha && toto [1][1] == ficha && toto [2][1] == ficha){
		g = 1;
	}
	if (toto [2][0] == ficha && toto [1][1] == ficha && toto [0][2] == ficha){
		g = 1;
	}
	if (toto [2][0] == ficha && toto [2][1] == ficha && toto [2][2] == ficha){
		g = 1;
	}
	if (toto [0][2] == ficha && toto [1][2] == ficha && toto [2][2] == ficha){
		g = 1;
	}
	
	if (g == 1){
		if (ficha == 'x'){
			g = 1;
		}
		if (ficha == 'o'){
			g = 2;
		}
	}
	return g;
}

void tablero (char toto[3][3], char p1[10], char p2[10], char p1_ficha, char p2_ficha){
	printf ("-----------------------------------TOTITO---------------------------------------\n\n");
	
	printf ("%s (%c)                                                      %s (%c)\n", p1, p1_ficha, p2, p2_ficha);
	printf ("                                 |        |                                  \n");
	printf ("                            %c    |   %c    |    %c                          \n", toto[0][0], toto[0][1], toto[0][2]);
	printf ("                                 |        |                                  \n");
	printf ("                        -----------------------------                        \n");
	printf ("                                 |        |                                  \n");
	printf ("                            %c    |   %c    |    %c                          \n", toto[1][0], toto[1][1], toto[1][2]);
	printf ("                                 |        |                                  \n");
	printf ("                        -----------------------------                        \n");
    printf ("                                 |        |                                  \n");
	printf ("                            %c    |   %c    |    %c                          \n", toto[2][0], toto[2][1], toto[2][2]);
	printf ("                                 |        |                                  \n\n");
}

void jugada (char toto[3][3], char player[10], char ficha){
	int x, y, aux, g;
	char aux_c;
	
	printf ("Turno de %s \n", player);
	
	do{
		
	do{
	printf ("Ingrese la posicion en x donde desea colocar la ficha: ");
	scanf ("%i", &x);

	if (x >= 0 && x <= 2){
		aux = 1;
	}
	else {
		printf ("La posicion en x ingresada no es valida\n");
		aux = 0;
	}
	} while (aux == 0);
	
	do{
	printf ("Ingrese la posicion en y donde desea colocar la ficha: ");
	scanf ("%i", &y);

	if (y >= 0 && y <= 2){
		aux = 1;
	}
	else {
		printf ("La posicion en y ingresada no es valida\n");
		aux = 0;
	}
	} while (aux == 0);
	
	aux_c = toto [x][y];
	
	if (aux_c != 'x'){
		if (aux_c != 'o'){
			toto [x][y] = ficha;
			g = 1;
		}
	}	
	if (g != 1){
		printf ("La posicion (x,y) ingresada no es valida\n");
		g = 0;
	}	
	}while (g == 0);

}

int empate(char toto[3][3]){
	int fila, columna, aux, entero;
	
	aux = 0;
	for (fila = 0; fila <= 2; fila ++){
		for (columna = 0; columna <= 2; columna ++){
			if (toto[fila][columna] != 'x'){
				if (toto[fila][columna] != 'o'){
					aux = aux + 1;
				}
			}
		}
	}
	
	if (aux == 0){
		entero = 3;	
	}
	else {
		entero = 0;
	}
	
	return entero;
}
