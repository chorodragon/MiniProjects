#include <stdio.h>
#include <time.h>

int binsearch(int x, int v[], int n);

int main(){
    int x, n, aux;
    n = 10;
    int v[n];
    for(aux = 0; aux < n; aux ++){
        v[aux] = aux;
    }

    printf("Ingrese el numero a buscar: ");
    scanf("%d", &x);
    
    printf("Posicion: %d\n", binsearch(x, v, n));
    return 0;
}

int binsearch(int x, int v[], int n){
    clock_t start, stop;
    start = time(0);
    int mid, low, high;
    low = 0;
    high = n-1;
    mid = (high + low) / 2;
    while(low <= high && v[mid] != x){
        mid = (high + low) / 2;
        if (x < v[mid])
            high = mid - 1;
        else 
            low = mid + 1;
    }
    
    if(v[mid] != x)
        mid= -1;

    stop = time(0);
    double spent = (double)(stop-start) / CLOCKS_PER_SEC;
    printf("Tiempo total: %f\n", spent);
    return mid;
}
