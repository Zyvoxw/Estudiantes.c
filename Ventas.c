/*Integrantes:
Descripcion:*/
#include <stdio.h>
int main() {
    int ID, Stock = 0, opcion, cantidad = 0, Agregar = 0;
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
                do {
                    printf("Stock: ");
                    scanf("%d", &Stock);
                    if (Stock <= 0) {
                        printf("Ingresar otro valor\n");
                    }
                } while (Stock <= 0);
                do {
                    printf("Valor unitario: ");
                    scanf("%f", &precio);
                    if (precio <= 0) {
                        printf("Debe ingresar un valor positvo.\n");
                    }
                } while (precio <= 0);
                printf("Producto registrdo\n");
                break;
            case 2: 
                if (Stock == 0) {
                    printf("No hay stock disponible\n");
                } else {
                    do {
                        printf("Ingrese cantidad a vender\n");
                        scanf("%d", &cantidad);
                        if (cantidad <= 0) {
                            printf("Cantidad invalida\n");
                        } else if (cantidad > Stock) {
                            printf("Stock insuficiente\n");
                        }
                    } while (cantidad <= 0 || cantidad > Stock);
                    printf("Aplicar descuento: ");
                    scanf("%f", &descuento);
                    Mdes = precio * descuento / 100;     
                    PrecioFinal = precio - Mdes;
                    Total = PrecioFinal * cantidad;
                    Stock = Stock - cantidad;
                    ganancias += Total;
                    printf("Descuento aplicado: %.2f\n", descuento);
                    printf("Precio final por unidad: $%.2f\n", PrecioFinal);
                    printf("Total venta: $%.2f\n", Total);
                    printf("Stock restante: %d\n", Stock);
                }
                break;
            case 3: 
                do {
                    printf("\nAgregar mas producto ");
                    scanf("%d", &Agregar);
                    if (Agregar <= 0) {
                        printf("Numero invalido\n");
                    }
                } while (Agregar <= 0);
                Stock += Agregar;
                printf("Stock actualizado");
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

