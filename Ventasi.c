/*Integrantes:
Descripcion:*/
#include <stdio.h>
int main() {
    int ID, Stock = 0, opcion, cantidad = 0, Agregar = 0;
    char nombre[30];
    float precio = 0, ganancias = 0, descuento, PrecioFinal, Total, Mdes = 0;
    do {
        printf("\tTienda\n");  
        printf("\t1.Registrar el producto\n");
        printf("\t2.Venta\n");
        printf("\t3.Reabastecer\n");
        printf("\t4.Informacion\n");
        printf("\t5.Ganancias\n");
        printf("\t6.Salida\n");
        printf("\tIngrese una opcion: ");   
        scanf("%d", &opcion);          
        switch (opcion) {
            case 1: 
                printf("\n\tIngresar ID: ");
                scanf("%d", &ID);
                printf("\tNombre del producto: ");
                scanf("%s", nombre); 
                do {
                    printf("\tStock: ");
                    scanf("%d", &Stock);
                    if (Stock <= 0) {
                        printf("\tIngresar otro valor\n");
                    }
                } while (Stock <= 0);
                do {
                    printf("\tValor unitario: ");
                    scanf("%f", &precio);
                    if (precio <= 0) {
                        printf("\tDebe ingresar un valor positvo.\n");
                    }
                } while (precio <= 0);
                printf("\tProducto registrdo\n");
                break;
            case 2: 
                if (Stock == 0) {
                    printf("\tNo hay stock disponible\n");
                } else {
                    do {
                        printf("\tIngrese cantidad a vender\n");
                        scanf("%d", &cantidad);
                        if (cantidad <= 0) {
                            printf("\tCantidad invalida\n");
                        } else if (cantidad > Stock) {
                            printf("\tStock insuficiente\n");
                        }
                    } while (cantidad <= 0 || cantidad > Stock);
                    printf("\tAplicar descuento: ");
                    scanf("%f", &descuento);
                    Mdes = precio * descuento / 100;     
                    PrecioFinal = precio - Mdes;
                    Total = PrecioFinal * cantidad;
                    Stock = Stock - cantidad;
                    ganancias += Total;
                    printf("\tDescuento aplicado: %.2f\n", descuento);
                    printf("\tPrecio final por unidad: $%.2f\n", PrecioFinal);
                    printf("\tTotal venta: $%.2f\n", Total);
                    printf("\tStock restante: %d\n", Stock);
                }
                break;
            case 3: 
                do {
                    printf("\n\tAgregar mas producto ");
                    scanf("%d", &Agregar);
                    if (Agregar <= 0) {
                        printf("\tNumero invalido\n");
                    }
                } while (Agregar <= 0);
                Stock += Agregar;
                printf("\tStock actualizado");
                break;
            case 4: 
                printf("\tID: %d\n", ID);
                printf("\tNombre: %s\n", nombre);
                printf("\tStock: %d\n", Stock);
                printf("\tPrecio: $%.2f\n", precio);
                break;
            case 5:  
                printf("\tganancias $%.2f\n", ganancias);
                break;
            case 6: 
                printf("\tsalir\n");
                break;
            default:
                printf("\topcion invalida\n");
        }
    } while (opcion != 6);

    return 0;
}
