/*Integrantes:Zaskia Sunta, Iveth Castro
Fecha:
Descripción: Realizar un programa que simula la vento de productos en una tienda de ropa*/
#include<stdio.h>
#include<string.h>
int main()
{
    float Vestido=10.5, Collar=6.6, Tacos=20.8, Falda=3.2, Corbata=10, Traje=40, Chompa=30, Reloj=59.7; 
    char Usuario, Contraseña, Genero;
   printf("Ingrese el usuario->");
   scanf(" %c", &Usuario);
   printf("Ingrese la contraseña->");
   scanf(" %c", &Contraseña);
   if (Usuario=='0' && Contraseña=='0')
   {
    printf("Ingrese el genero->");
    scanf(" %c", &Genero);
        if (Genero=='M' || Genero=='m')
        {
            printf("Seleccione las prendas de ropa->");
            printf("\nVestido");
            printf("\nCollar");
            printf("\nTacos");
            printf("\nFalda");
        }
        
    
   }
   
    return 0;
}

