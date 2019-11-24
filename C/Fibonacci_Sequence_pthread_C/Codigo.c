#include <stdio.h>
#include <pthread.h>

static int num = 0;
static int num2 = 1;
static int op;

void *suma (void *param);


int main(){

	pthread_t hilo;
	pthread_attr_t attr;
	pthread_attr_init(&attr);

	printf("Hasta que numero desea calcular la serie Fibonacci?: ");
	scanf("%d", &op);

	pthread_create(&hilo, &attr, suma, NULL);
	pthread_join(hilo, NULL);	
	
	printf("Resultado = %d", num2);
	
	return 0;
}

void *suma (void *arg){
	int i;
	for (i = 1; i < op; i++){
		num2 = num2 + num;
		num=num2-num;
	}
}
