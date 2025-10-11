#include <stdio.h>
#include <time.h>

// Función recursiva para calcular el factorial
unsigned long long factorial_recursivo(int n) {
    if (n <= 1) return 1;
    return n * factorial_recursivo(n - 1);
}

// Función iterativa para calcular el factorial
unsigned long long factorial_iterativo(int n) {
    unsigned long long resultado = 1;
    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }    return resultado;
}

int main() {
    int numero = 1200000; // Puedes cambiar este número para probar otros casos
    clock_t inicio, fin;
    double tiempo;

    // Medir tiempo de la función recursiva
    inicio = clock();
    unsigned long long resultado_rec = factorial_recursivo(numero);
    fin = clock();
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Factorial recursivo de %d es %llu. Tiempo: %f segundos\n", numero, resultado_rec, tiempo);

    // Medir tiempo de la función iterativa
    inicio = clock();
    unsigned long long resultado_it = factorial_iterativo(numero);
    fin = clock();
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("Factorial iterativo de %d es %llu. Tiempo: %f segundos\n", numero, resultado_it, tiempo);

    return 0;
}







