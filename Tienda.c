#include <stdio.h>
int main() {
    int ID, Stock = 0, opcion = 0, cantidad = 0, Agregar = 0;
    char nombre[30];
    float precio = 0, ganancias = 0, descuento, PrecioFinal, Total, Mdes = 0;
    do {
        printf("Tienda\n");  
        printf("1.Registrar el producto\n");
        printf("2.Venta\n");
        printf("3.Reabastecer\n");
        printf("4.Informacion\n");
        printf("5.Ganancias\n");
        printf("6.Salida\n");
        printf("Ingrese una opcion: ");   
        scanf("%d", &opcion);          
        switch (opcion) {
            case 1: 
                printf("\nIngresar ID: ");
                scanf("%d", &ID);
                printf("Nombre del producto: ");
                scanf("%s", nombre); 
                printf("Stock ");//IF para que evalue los positivos y negativos 
                scanf("%d", &Stock);
                printf("Valor unitario: ");
                scanf("%f", &precio);
                break;
            case 2: 
                if (Stock == 0) {
                    printf("No hay stock disponible\n");
                } else {
                    printf("Ingrese cantidad a vender: \n");
                    scanf("%d", &cantidad);
                    if (cantidad > Stock) {
                        printf("Stock insuficiente\n");
                    } 
                    if (cantidad<=0)
                    {
                        printf("Cantidad invalida");
                    }
                    else{
                        printf("Aplicar descuento: ");
                        scanf("%f", &descuento);
                        Mdes = precio * descuento / 100;
                        PrecioFinal = precio - Mdes;
                        Total = PrecioFinal * cantidad;
                        Stock=Stock-cantidad;
                        ganancias += Total;
                        printf("Descuento aplicado: %.2f\n", descuento);
                        printf("Precio final por unidad: $%.2f\n", PrecioFinal);
                        printf("Total venta: $%.2f\n", Total);
                        printf("Stock restante: %d\n", Stock);
                    }
                }
                break;
            case 3: 
                printf("\nAgregar mas producto ");
                scanf("%d", &Agregar);
                if (Agregar > 0) {
                    Stock += Agregar;
                    printf("Stock actualizado");
                } else {
                    printf("Numero invalido\n");
                }
                break;
            case 4: 
            printf("ID: %d\n", ID);
            printf("Nombre: %s\n", nombre);
            printf("Stock: %d\n", Stock);
            printf("Precio: $%.2f\n", precio);
                break;
            case 5:  
                printf("ganancias $%.2f\n", ganancias);
                break;
            case 6: 
                printf("salir\n");
                break;
            default:
                printf("opcion invalida\n");
        }
    } while (opcion != 6);

    return 0;
}
