/*Nombre: Zaskia Sunta
Fecha: 15/06/2025
Descripcion: Crear un programa que permita al usuario adivinar el numero secreto en tres intentos*/
#include <stdio.h>

int main() {
    int numSecreto, intento, intentosRestantes;
    numSecreto=12;
    intentosRestantes=3;

    printf("Adivinar el numero secreto\n");

    while (intentosRestantes > 0) {
        printf("Hay %d intentos, ingresa un numero\n", intentosRestantes);
        scanf("%d", &intento);

        if (intento == numSecreto) {
            printf("Adivinaste el numero secreto\n");
        } else if (intento < numSecreto) {
            printf("El numero ingresado es menor al numero secreto\n");
        } else {
            printf("El numero ingresado es mayor al numero secreto\n");
        }
         intentosRestantes--;
    }

    printf("Se acabaron los intentos\n");
}
