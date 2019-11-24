#include <stdio.h>
#include <string.h>

typedef struct {
	int codigo;
	char desc[20];
	float precio;
}producto;

int main (){
	producto aux[5];
	int i, cod;
	char des[20];
	float precio;
	FILE *f;
	
	f = fopen("Ejemplo.txt","a + r");
	for (i = 0; i <= 4; i++){
	printf ("Ingrese el codigo del producto: ");
	scanf ("%i", &cod);
	printf ("Ingrese la descripcion del producto: ");
	fflush (stdin);
	fgets (des,20,stdin);
	printf ("Ingrese el precio del producto: ");
	scanf ("%f", &precio);
	aux[i].codigo = cod;
	strcpy(aux[i].desc, des);
	aux[i].precio = precio;
	printf ("\n");
	fprintf(f, "%i", aux[i].codigo);
	fprintf(f, "%s", aux[i].desc);
	fprintf(f, "%f", aux[i].precio);
	}

	for (i = 0; i <= 4; i++){
	printf ("\n\n");
	printf ("Codigo de producto: %i", aux[i].codigo);
	printf ("\nDescripcion de producto: %s", aux[i].desc);
	printf ("\nPrecio de producto: %f", aux[i].precio); 
	}
	fclose(f);
	system ("pause");
	return 0;
}
