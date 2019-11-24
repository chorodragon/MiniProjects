#include <stdio.h>
#include <windows.h>

int Menu();
void Mostrar();
void Agregar ();
void Modificar();
void Eliminar();
void Ejecutar();
void ModificarColoryNombre ();
void CambiarColor();
void CambiarTitulo();

struct Dat{
	char Nombre[50];
	char Direccion[50];
	char Descripcion[500];
};

int main(){
	
	int opcion, i, ColorPred;
	i = 0;
	char op[30];
	FILE *Opciones;
	
	Opciones = fopen("Config_menu.dat","r");
	if (Opciones == NULL){
			printf ("El archivo de 	configuracion no se puede abrir\n");
			getch();
			exit(1);
	}
	fgets (op, 4, Opciones);
	
	ColorPred = atoi(op);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorPred);
	
	fgets (op, 30, Opciones);
	SetConsoleTitle(op);
	
	fclose(Opciones);
	
	do{
		system ("cls");
		opcion = Menu();
		
		if (opcion == 1)
			Mostrar();
			
		else if (opcion == 2)
			Agregar();
			
		else if (opcion == 3)
			Modificar();
		
		else if (opcion == 4)
			Eliminar();
		
		else if (opcion == 5)
			Ejecutar();
		
		else if (opcion == 6)
			ModificarColoryNombre();
		else if (opcion == 7)
			i = 1;	
	}while (i == 0);
	
	return 0;
}

int Menu (){
	
	int opcion, i;
	i = 0;
	
	do{
		system ("cls");
		printf ("Que operacion desea realizar?\n");
		printf ("1- Mostrar las opciones existentes.\n");
		printf ("2- Agregar opciones al menu.\n");
		printf ("3- Modificar opciones del menu.\n");
		printf ("4- Eliminar opciones del menu.\n");
		printf ("5- Ejecutar Base de datos.\n");
		printf ("6- Cambiar la apariencia de la ventana.\n");
		printf ("7- Salir\n\n");
		printf ("Ingrese el numero de la opcion que desea: ");
		scanf ("%i", &opcion);
	
		if (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5 && opcion != 6 && opcion != 7){
			printf ("El numero de opcion seleccionada no es valido.\n");
			i = 0;
			system ("pause");
		}
		else {
			i = 1;
			system ("cls");
		}
	}while(i == 0);
	return opcion;
}

void Mostrar(){
	
	struct Dat datos;
	FILE *Archivo;
	int i = 1;
	
	Archivo = fopen("Menu.dat","ab+");
	
	if (Archivo == NULL){
		printf ("El archivo no se puedo abrir\n");
		getch();
		exit(1);
	}
	
	while (fread(&datos, sizeof(datos), 1, Archivo) == 1){
		printf ("%i.%s", i, datos.Nombre);
		i += 1;	
	}
	getch();
	
	fclose (Archivo);
}

void Agregar (){
	
	struct Dat datos;
	FILE *Archivo;
	
	Archivo = fopen("Menu.dat","ab+");
	
	if (Archivo == NULL){
		printf ("El archivo no se puedo abrir\n");
		getch();
		exit(1);
	}
	
	printf ("Ingrese el nombre de la opcion: ");
	fgets(datos.Nombre, 50, stdin);
	fgets(datos.Nombre, 50, stdin);
	fflush(stdin);
	
	printf ("Ingrese el nombre del archivo: ");
	fgets(datos.Direccion, 50, stdin);
	fflush(stdin);
	
	printf ("Ingrese la descripcion: ");
	fgets(datos.Descripcion, 500, stdin);
	fflush(stdin);
	
	fwrite(&datos, sizeof(datos), 1, Archivo);
	
	fclose(Archivo);
}

void Modificar(){
	
	FILE *Archivo;
	FILE *Archivo2;
	struct Dat datos;
	char nombre[50];
	int i=0;
	
	Archivo = fopen("Menu.dat","ab+");
	Archivo2 = fopen ("temp.dat","wb");
	
	if (Archivo == NULL && Archivo2 != NULL){
		printf ("El archivo no se puedo abrir\n");
		getch();
		fclose (Archivo2);
		exit(1);
	}
	
	else if (Archivo == NULL && Archivo2 == NULL){
		printf ("El archivo no se puedo abrir\n");
		getch();
		exit(1);
	}
	
	else if (Archivo2 == NULL && Archivo != NULL){
		printf ("El archivo no se puedo abrir\n");
		getch();
		fclose (Archivo);
		exit(1);
	}
	
	printf ("Ingrese el nombre del registro que desea modificar: ");
	fgets(nombre, 50, stdin);
	fgets(nombre, 50, stdin);
	fflush(stdin);
	
	while (fread(&datos, sizeof(datos), 1, Archivo) == 1){
		if (strcmp(datos.Nombre, nombre) == 0){
			printf ("Ingrese el nombre de la opcion: ");
			fgets(datos.Nombre, 50, stdin);
			fflush(stdin);
			
			printf ("Ingrese el nombre del archivo: ");
			fgets(datos.Direccion, 50, stdin);
			fflush(stdin);
			
			printf ("Ingrese la descripcion: ");
			fgets(datos.Descripcion, 500, stdin);
			fflush(stdin);
			
			fwrite(&datos, sizeof(datos), 1, Archivo2);
			i = 1;
		}
		else{
			fwrite(&datos, sizeof(datos), 1, Archivo2);
		}	
	}
	
	fclose(Archivo);
	fclose(Archivo2);
	system("del Menu.dat");
	rename("temp.dat","Menu.dat");
	if (i == 0){
		printf ("\nEl nombre de opcion ingresado no es valido o no existe.");
		getch();
	}
}

void Eliminar(){
		
	FILE *Archivo;
	FILE *Archivo2;
	struct Dat datos;
	char nombre[50];
	int i=0;
	
	Archivo = fopen("Menu.dat","ab+");
	Archivo2 = fopen ("temp.dat","wb");
	
	if (Archivo == NULL && Archivo2 != NULL){
		printf ("El archivo no se puedo abrir\n");
		getch();
		fclose (Archivo2);
		exit(1);
	}
	
	else if (Archivo == NULL && Archivo2 == NULL){
		printf ("El archivo no se puedo abrir\n");
		getch();
		exit(1);
	}
	
	else if (Archivo2 == NULL && Archivo != NULL){
		printf ("El archivo no se puedo abrir\n");
		getch();
		fclose (Archivo);
		exit(1);
	}
	
	printf ("Ingrese el nombre del registro que desea modificar: ");
	fgets(nombre, 50, stdin);
	fgets(nombre, 50, stdin);
	fflush(stdin);
	
	while (fread(&datos, sizeof(datos), 1, Archivo) == 1){
		if (strcmp(datos.Nombre, nombre) == 0){
			i = 1;
		}
		else{
			fwrite(&datos, sizeof(datos), 1, Archivo2);
		}	
	}
	
	fclose(Archivo);
	fclose(Archivo2);
	system("del Menu.dat");
	rename("temp.dat","Menu.dat");
	if (i == 0){
		printf ("\nEl nombre de opcion ingresado no es valido o no existe.");
		getch();
	}
}

void Ejecutar(){
	system ("start Base.exe");
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
		
		Archivo = fopen ("Config_menu.dat","r");
		Archivo2 = fopen ("Config_menutemp.dat","a");
		
		fgets(aux, 3, Archivo);
		fgets(aux, 30, Archivo);
		fprintf (Archivo2, "%i\n",ColorFinal);
		fprintf (Archivo2, "%s",aux);
		fclose (Archivo);
		fclose (Archivo2);
		
		system ("del Config_menu.dat");
		rename("Config_menutemp.dat","Config_menu.dat");
			
		printf ("\n\nOprima cualquier tecla para continuar...");
		getch ();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorFinal);
}

void CambiarTitulo(){
		
		FILE *Archivo;
		FILE *Archivo2;
		char nombre[30];
		char aux[3];
		
		system ("cls");
		printf ("Ingrese el nuevo nombre de la ventana: ");
		fgets (nombre, 30, stdin);
		fgets (nombre, 30, stdin);
		fflush(stdin);
		
		Archivo = fopen("Config_menu.dat","r");
		Archivo2 = fopen("Config_menutemp.dat","w");
		
		fgets(aux, 3, Archivo);
		
		fprintf (Archivo2, "%s", aux);
		fprintf (Archivo2, "%s", nombre);
	
		fclose(Archivo);
		fclose(Archivo2);
		system ("del Config_menu.dat");
		rename("Config_menutemp.dat","Config_menu.dat");
		SetConsoleTitle(nombre);
}

