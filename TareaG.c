/*Integrantes: Zaskia Sunta, Iveth Castro
Fecha:21/06/2025
Descripcion: Realizar un programa en C que permita a los usuarios saber diametro y altura de los arboles
*/
#include<stdio.h>
int main()
{
    float SumaD, SumaA, Diametro, Altura, PromDi=0, PromAl=0;
    int Cont=0;
    char Rta;
    do {
        printf("Ingrese el diametro del tronco->");
        scanf("%f", &Diametro);
        printf("Ingrese la altura del tronco->");
        scanf("%f", &Altura);
        PromAl+=Altura;
        PromDi+=Diametro;
        Cont++; 
        printf("¿Seguir ingresando datos?");
        scanf(" %c", &Rta);

    } while(Rta=='S');
    
    if (Cont>0)
    {
        SumaA=PromAl/Cont;
        SumaD=PromDi/Cont;
        printf("El promedio del diametro es %2f", PromDi);
        printf("El promedio de la altura es %2f", PromAl);
    }
    return 0;
}
