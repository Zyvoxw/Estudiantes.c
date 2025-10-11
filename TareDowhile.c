/*Integrantes: Zaskia Sunta, Iveth Castro
Fecha:22/06/2025
Descripcion: Realizar un programa en C que permita al usuario saber  promedio en diametro y altura de los arboles
*/
#include <stdio.h>
int main() {
    float Diametro, Altura, SumaD = 0, SumaAl = 0, PromDiametro, PromAl;
    int Cont = 0;
    char Rta;
    do {
        printf("Ingresar información de un cipres. S/N: ");
        scanf(" %c", &Rta);  

        if (Rta == 'S') {
            printf("Ingrese el diámetro del tronco -> ");
            scanf("%f", &Diametro);

            printf("Ingrese la altura del tronco -> ");
            scanf("%f", &Altura);

            SumaD += Diametro;
            SumaAl += Altura;
            Cont++;
        }
    } while (Rta != 'N');

    if (Cont > 0) {
        PromDiametro = SumaD / Cont;
        PromAl = SumaAl / Cont;

        printf("\nPromedio del diámetro es -> %.2f cm\n", PromDiametro);
        printf("Promedio de altura es -> %.2f m\n", PromAl);
    } 
    return 0;
}


