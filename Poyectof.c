/*Integrantes: Zaskia Sunta, Iveth Castro
Fecha: 06/07/2025
Descripción: Programa que calcula la compra de cada cliente en una tiendad de ropa */
#include <stdio.h>
#include <string.h>
int main() {
    char usuario[10], clave[10];
    char usuariocorrecto[] = "zaskia";
    char claveCorrecta[] = "1111";

    int vendidos[8] = {0};
    char continuarClientes = 's';

    while (continuarClientes == 's' || continuarClientes == 'S') {
        printf("\nNuevo cliente");
        printf("\nIniciar sesión");
        printf("\nUsuario -> ");
        scanf("%s", usuario);
        printf("\nClave -> ");
        scanf("%s", clave);

        if (strcmp(usuario, usuariocorrecto) != 0 || strcmp(clave, claveCorrecta) != 0) {
            printf("\nUsuario o clave incorrectos\n");
            continue;
        }
        int opcion, cantidad;
        char prenda[20], seguir = 's';
        float precioUnitario = 0, subtotalTotal = 0, descuentoTotal = 0, ivaTotal = 0, totalAPagar = 0;
        
        while (seguir == 's' || seguir == 'S') {
            printf("\nSeleccione el tipo de prenda por número->\n");
            printf("1. Blusas-$20.00\n");
            printf("2. Vestidos-$35.00\n");
            printf("3. Faldas-$25.00\n");
            printf("4. Tacones-$50.00\n");
            printf("5. Camisas-$22.00\n");
            printf("6. Jeans-$40.00\n");
            printf("7. Zapatos-$45.00\n");
            printf("8. Chaquetas-$60.00\n");

            printf("Ingrese el número de la prenda que desea comprar: ");
            scanf("%d", &opcion);

            switch (opcion) {   //Nota. Tipo de prenda
                case 1:
                    strcpy(prenda, "Blusas");
                    precioUnitario = 20.0;
                    break;
                case 2:
                    strcpy(prenda, "Vestidos");
                    precioUnitario = 35.0;
                    break;
                case 3:
                    strcpy(prenda, "Faldas");
                    precioUnitario = 25.0;
                    break;
                case 4:
                    strcpy(prenda, "Tacones");
                    precioUnitario = 50.0;
                    break;
                case 5:
                    strcpy(prenda, "Camisas");
                    precioUnitario = 22.0;
                    break;
                case 6:
                    strcpy(prenda, "Jeans");
                    precioUnitario = 40.0;
                    break;
                case 7:
                    strcpy(prenda, "Zapatos");
                    precioUnitario = 45.0;
                    break;
                case 8:
                    strcpy(prenda, "Chaquetas");
                    precioUnitario = 60.0;
                    break;
                default:
                    printf("Opción incorrecta");
                    continue;  
            }

            printf("Ingrese la cantidad de %s que desea comprar: ", prenda); //Nota. Cantidad de cada ropa
            scanf("%d", &cantidad);

            float subtotal = precioUnitario * cantidad;
            float descuento = 0;

            if (cantidad > 5) {
                descuento = subtotal * 0.10; //Nota.Descuento por volumen
            }

            float subtotalConDescuento = subtotal - descuento;
            float iva = subtotalConDescuento * 0.12;
            float total = subtotalConDescuento + iva;

            printf("\nFactura");
            printf("\nProducto:         %s", prenda);
            printf("\nCantidad:         %d", cantidad);
            printf("\nPrecio unitario:  $%.2f", precioUnitario);
            printf("\nSubtotal:         $%.2f", subtotal);
            printf("\nDescuento:        -$%.2f", descuento);
            printf("\nIVA (12%%):        $%.2f", iva);
            printf("\nTotal a pagar:    $%.2f\n", total);

            subtotalTotal += subtotal;
            descuentoTotal += descuento;
            ivaTotal += iva;
            totalAPagar += total;
            vendidos[opcion - 1] += cantidad;

            printf("\n¿Desea seguir comprando? (s/n)->");
            scanf(" %c", &seguir);
        }

        float cupon = 0;
        printf("\nIngrese el valor de su cupón de descuento (0 si no tiene cupon)->$");
        scanf("%f", &cupon);    //Nota. Ingresar descuento por cupon adicional.

        float totalAntesDeIva = subtotalTotal - descuentoTotal - cupon;
        ivaTotal = totalAntesDeIva * 0.12;
        totalAPagar = totalAntesDeIva + ivaTotal;

        printf("\nFactura");    //Nota. Desglose de la compra.
        printf("\nSubtotal total->$%.2f", subtotalTotal);
        printf("\nDescuento total->$%.2f", descuentoTotal + cupon);
        printf("\nIVA total (12%%)-> $%.2f", ivaTotal);
        printf("\nTotal a pagar->$%.2f\n", totalAPagar);

        printf("\nNuevo cliente (s/n)-> ");
        scanf(" %c", &continuarClientes);
    }
    int maxIndex = 0;
    for (int i = 1; i < 8; i++) {
        if (vendidos[i] > vendidos[maxIndex]) {
            maxIndex = i;
        }
    }
    printf("\nProducto más vendido: ");
    switch (maxIndex) {
        case 0: printf("Blusas"); break;
        case 1: printf("Vestidos"); break;
        case 2: printf("Faldas"); break;
        case 3: printf("Tacones"); break;
        case 4: printf("Camisas"); break;
        case 5: printf("Jeans"); break;
        case 6: printf("Zapatos"); break;
        case 7: printf("Chaquetas"); break;
    }
    printf("\n(%d unidades)", vendidos[maxIndex]);
    return 0;
}