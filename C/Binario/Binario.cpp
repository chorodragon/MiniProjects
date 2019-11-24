#include <stdio.h>
#include <conio.h>
#include <string.h>

struct animalito{
	int clave;
	char nombre[50];
	int edad;
};

int main(){
	
	struct animalito animal;
	
	printf ("Clave: ");
	scanf ("%i", &animal.clave);
	
	printf ("Nombre: ");
	gets (animal.nombre);
	gets (animal.nombre);
	
	printf ("Edad: ");
	scanf ("%i", &animal.edad);
	
	FILE *Archivo;
	
	Archivo = fopen ("archivo.pte","abt");
	
	fwrite (&animal, sizeof(animal), 1, Archivo);
	fclose (Archivo);
	
	printf ("Agregado");
	getch ();
	
	return 0;
}
