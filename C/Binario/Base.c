#include <stdio.h>
#include <windows.h>

void Opcion ();
void Mostrar();
void Arreglar();
void Ejecutar();
void Exe();
void ModificarColoryNombre ();
void CambiarColor();
void CambiarTitulo();

struct Dat{
	char Nombre[50];
	char Direccion[50];
	char Descripcion[500];
};

int main(){
	
	FILE *Archivo;
	int i, j, k, fondo, letra, ColorPred;
	struct Dat datos;
	i = 0;
	FILE *Opciones;
	char op[30];

	Opciones = fopen("Config_base.dat","r");
	if (Opciones == NULL){
			printf ("El archivo de configuracion no se puede abrir\n");
			exit(1);
	}
	fgets (op, 4, Opciones);
	ColorPred = atoi(op);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorPred);
	fgets (op, 30, Opciones);
	SetConsoleTitle(op);
	fclose(Opciones);

	while (i == 0){	
	j = 0;	
	system("cls");
	Archivo = fopen("Menu.dat","ab+");
	if (Archivo == NULL){
			printf ("El archivo no se puedo abrir\n");
			exit(1);
	}
	while (fread(&datos, sizeof(datos), 1, Archivo) == 1){
		j += 1;
		printf ("%i.%s", j, datos.Nombre);
	}
	j += 1;
	printf ("%i.Cambiar configuracion de ventana.\n", j);
	j += 1;
	printf ("%i.Salir",j);
	
	printf ("\nIngrese el numero de la opcion que desea: ");
	scanf ("%i", &k);
	
	if (k == j){
		fclose(Archivo);
		exit(1);
	}
	if (k > j){
		printf ("El numero de opcion ingresado no es valido.");
		getch ();
	}
	else if (k == (j -1)){
		ModificarColoryNombre();
	}
	
	else{
		fclose (Archivo);
		Opcion (k, ColorPred);
	}
	}
	return 0;
}

void Opcion(int k ,int ColorPred){
	
	FILE *Archivo;
	struct Dat datos;
	int i=0;
	
	k -= 1;
	
	while (i != 3){
	
	system("cls");
	Archivo = fopen("Menu.dat","ab+");
	if (Archivo == NULL){
			printf ("El archivo no se puedo abrir\n");
			exit(1);
	}

	fseek (Archivo, (long)(k)*sizeof(datos), 0);
	fread(&datos, sizeof(datos), 1, Archivo);
	printf ("El nombre de la opcion es: %s",datos.Nombre);
	printf ("El nombre del archivo es: %s", datos.Direccion);
	printf ("Descripcion: %s", datos.Descripcion);
	fclose(Archivo);
	
	printf ("\n\nQue desea hacer: ");
	printf ("\n1.Mostrar el codigo fuente.");
	printf ("\n2.Ejecutar el programa.");
	printf ("\n3.Regresar al menu.");
	printf ("\nIngrese el numero de la opcion: ");
	scanf ("%i", &i);
	
	if (i != 1 && i !=2 && i != 3){
		printf ("El numero de opcion seleccionado no es valido.\n");
		system ("pause");
	}
	else if (i == 1){
		Mostrar(datos.Direccion, ColorPred);
	}
	else if (i == 2){
		Ejecutar(datos.Direccion);
	}
	
	}
}

void Mostrar(char nombre[50], int ColorPred){
	
	FILE *Archivo2;
	char aux[500];
	int i, j, k, n;
	COORD gotoxy; //declaracion de variable de coordenada
	char key;
	j = 0;
	k = 0;

	Arreglar(nombre);
	
	Archivo2 = fopen ("%s",nombre);
	Archivo2 = fopen (nombre,"r");
	
	if (Archivo2 == NULL){
			printf ("El archivo no se puedo abrir\n");
			exit(1);
	}
	
	system ("cls");
	while (!feof (Archivo2)){
		fgets (aux, 500, Archivo2);
		printf ("%s", aux);
		j += 1; //Indica cuantas lineas posee el codigo
	}
	j -=1;
	n = j;
	gotoxy.X = 0; // Indica la posicion en x (columnas) siempre esta al principio de la linea
	gotoxy.Y = j-1; // Indica la posicion en y (filas) es un numero menor a donde esta el cursor
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), gotoxy);
	
	
	while (k == 0){
		i = 0;
		key = getch(); //Captura el valor Ascii
		
		if (key == 13){ //Compara el valor capturado con el valor de Ascii de Enter (13)
			k = 1; //Si la tecla oprimida es enter k tendra un valor de 1 por lo que se saldra del bucle
		}
		
		else if (key == 9){ //Compara el valor capturado con el valor Ascii de Tabulador
			if (j != 0){ // Si no esta hasta arriba del archivo pasa a la siguiente instruccion
				rewind (Archivo2);
				while (i < j){
					fgets (aux, 500, Archivo2);
					i++;
				}
				gotoxy.X = 0; // Indica la posicion en x (columnas) siempre esta al principio de la linea
				gotoxy.Y = j; // Indica la posicion en y (filas) es un numero menor a donde esta el cursor
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), gotoxy); //Coloca el cursos al principio de la linea una posicion arriba de donde esta
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorPred);
				fgets (aux, 500, Archivo2);
				printf ("%s", aux);
				j -= 1; //Se va una linea arriba 
				
			}
		}
		
		else if (key == 32){ //Compara el valor capturado con el valor Ascii de Espacio
			if (j < n){ //Si no esta hasta abajo del archivo pasa a la siguiente instruccion
				rewind (Archivo2);
				while (i < j){
					fgets (aux, 500, Archivo2);
					i++;
				}
				gotoxy.X = 0; // Indica la posicion en x (columnas) siempre esta al principio de la linea
				gotoxy.Y = j; // Indica la posicion en y (filas) es un numero menor a donde esta el cursor
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), gotoxy); //Coloca el cursos al principio de la linea una posicion arriba de donde esta
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorPred);
				fgets (aux, 500, Archivo2);
				printf ("%s", aux);
				j += 1; //Se va una linea abajo
			}
		}
		
		rewind (Archivo2); //Rebobina el archivo
		gotoxy.X = 0; // Indica la posicion en x (columnas) siempre esta al principio de la linea
		gotoxy.Y = j; // Indica la posicion en y (filas) es un numero menor a donde esta el cursor
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), gotoxy); //Coloca el cursos al principio de la linea una posicion arriba de donde esta
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 112); //Cambia el color de fondo a blanco y la letra a negro
		i = 0;
		while (i < j){
			fgets (aux, 500, Archivo2);
			i++;
		} //Este while vuelve a leer el archivo para obetner la linea que volvera a escribir en otro color
		
		fgets (aux, 500, Archivo2);
		printf ("%s", aux); //Vuleve a imprimir la misma linea que esta borrando pero con otro color
		
	}
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorPred); //Regresa el texto al color original
	fclose (Archivo2);
	system ("cls");	
}

void Arreglar (char nombre[50]){
	int i;
	
	for (i = 0; i <= 49; i++){
		if (nombre[i] == '\n'){	
			nombre[i] = '\0';
		}
	}
}

void Ejecutar(char nombre[50]){
	
	Arreglar(nombre);
	Exe (nombre);
	
	system("cls");
	system (nombre);
	system("cls");
	
}

void Exe(char app[50]){
	
	int i;
	for (i=0; i<=49; i++){
		if (app[i] == '.'){
			app[i+1] = 'e';
			app[i+2] = 'x';
			app[i+3] = 'e';
		}
	} 
}

void ModificarColoryNombre (){
	
	int opcion, salida;
	salida = 0;
	
	system ("cls");
	while(salida == 0){
		printf ("Que desea modificar?");
		printf ("\n1.Color de fondo y/o color de letra.");
		printf ("\n2.Titulo de ventana");
		printf ("\n3.Cancelar");
		printf ("\n\nIngrese el numero de la opcion que desea: ");
		scanf ("%i", &opcion);
		
		if (opcion == 1){
			CambiarColor();
			salida = 1;
		}
		else if (opcion == 2){
			CambiarTitulo();
			salida = 1;
		}
		else if (opcion == 3){
			salida = 1;
		}
		else {
			printf ("Error. El numero de opcion seleccionado no es valido");
			system ("cls");
		}
	}
}

void CambiarColor(){
		
		FILE *Archivo;
		FILE *Archivo2;
		int fondo, letra, ColorFinal;
		char aux[30];
		
		system ("cls");
		printf ("Listado de colores disponibles:\n");
		printf ("0 = Negro\n"); 
		printf ("1 = Azul\n"); 
		printf ("2 = Verde\n"); 
		printf ("3 = Aguamarina\n"); 
		printf ("4 = Rojo\n"); 
		printf ("5 = Purpura\n"); 
		printf ("6 = Amarillo\n\n"); 
		printf ("Ingrese el color de fondo que desea: ");
		scanf ("%i", &fondo);
		
		system ("cls");
		printf ("Listado de colores disponibles:\n");
		printf ("0 = Negro\n"); 
		printf ("1 = Azul\n"); 
		printf ("2 = Verde\n"); 
		printf ("3 = Aguamarina\n"); 
		printf ("4 = Rojo\n"); 
		printf ("5 = Purpura\n"); 
		printf ("6 = Amarillo\n"); 
		printf ("7 = Blanco\n"); 
		printf ("8 = Gris\n"); 
		printf ("9 = Azul claro\n"); 
		printf ("10 = Verde claro\n");
		printf ("12 = Rojo claro\n"); 
		printf ("13 = Purpura claro\n"); 
		printf ("14 = Amarillo claro\n"); 
		printf ("15 = Blanco brillante\n\n"); 
		printf ("Ingrese el color de fondo que desea: %i\n", fondo);
		printf ("Ingrese el color de letra que desea: ");
		scanf ("%i", &letra);
		
		ColorFinal = fondo*16+letra;
		
		Archivo = fopen ("Config_base.dat","r");
		Archivo2 = fopen ("Config_basetemp.dat","a");
		
		fgets(aux, 4, Archivo);
		fgets(aux, 30, Archivo);
		fprintf (Archivo2, "%i\n",ColorFinal);
		fprintf (Archivo2, "%s",aux);
		fclose (Archivo);
		fclose (Archivo2);
		
		system ("del Config_base.dat");
		rename("Config_basetemp.dat","Config_base.dat");
			
		printf ("\n\nOprima cualquier tecla para continuar...");
		getch ();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorFinal);
}

void CambiarTitulo(){
		
		FILE *Archivo;
		FILE *Archivo2;
		char nombre[30];
		char aux[4];
		
		system ("cls");
		printf ("Ingrese el nuevo nombre de la ventana: ");
		fgets (nombre, 30, stdin);
		fgets (nombre, 30, stdin);
		fflush(stdin);
		
		Archivo = fopen("Config_base.dat","r");
		Archivo2 = fopen("Config_basetemp.dat","w");
		
		fgets(aux, 4, Archivo);
		
		fprintf (Archivo2, "%s", aux);
		fprintf (Archivo2, "%s", nombre);
	
		fclose(Archivo);
		fclose(Archivo2);
		system ("del Config_base.dat");
		rename("Config_basetemp.dat","Config_base.dat");
		SetConsoleTitle(nombre);
}
