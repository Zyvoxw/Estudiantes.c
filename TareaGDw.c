#include <stdio.h>
#include <string.h>

int main() {
    int opcion, cantidad;
    char prenda[20];
    float precioUnitario = 0, subtotalTotal = 0, descuentoTotal = 0, ivaTotal = 0, totalAPagar = 0;
    char seguir = 's';

    printf("\nCosas de la tienda");

    while (seguir == 's' || seguir == 'S') {
        printf("\nSeleccione el tipo de prenda por número:\n");
        printf("1. Blusas- $20.00\n");
        printf("2. Vestidos- $35.00\n");
        printf("3. Faldas- $25.00\n");
        printf("4. Tacones- $50.00\n");
        printf("5. Camisas- $22.00\n");
        printf("6. Jeans- $40.00\n");
        printf("7. Zapatos- $45.00\n");
        printf("8. Chaquetas- $60.00\n");

        printf("\nIngrese el número de la prenda que desea comprar: ");
        scanf("%d", &opcion);

        switch (opcion) {
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
                printf("Opción inválida.\n");
                continue;  // Vuelve a pedir la opción
        }

        printf("Ingrese la cantidad de %s que desea comprar: ", prenda);
        scanf("%d", &cantidad);

        float subtotal = precioUnitario * cantidad;
        float descuento = 0;

        if (cantidad > 5) {
            descuento = subtotal * 0.10; // 10% de descuento general
        }

        float subtotalConDescuento = subtotal - descuento;
        float iva = subtotalConDescuento * 0.12; // 12% IVA general
        float total = subtotalConDescuento + iva;

        printf("\nResumen de la compra");
        printf("\nProducto: %s", prenda);
        printf("\nCantidad: %d", cantidad);
        printf("\nPrecio unitario: $%.2f", precioUnitario);
        printf("\nSubtotal: $%.2f", subtotal);
        printf("\nDescuento: -$%.2f", descuento);
        printf("\nIVA (12%%): $%.2f", iva);
        printf("\nTotal a pagar: $%.2f\n", total);

        subtotalTotal += subtotal;  //nota. esto de aquí suma el valor actual y el anterior, acumuladores.
        descuentoTotal += descuento;
        ivaTotal += iva;
        totalAPagar += total;

        printf("\n¿Desea seguir comprando? (s/n): ");
        scanf(" %c", &seguir); 
    }
    printf("\n=== RESUMEN FINAL DE TODAS LAS COMPRAS ===");
    printf("\nSubtotal total: $%.2f", subtotalTotal);
    printf("\nDescuento total: -$%.2f", descuentoTotal);
    printf("\nIVA total (12%%): $%.2f", ivaTotal);
    printf("\nTotal a pagar: $%.2f\n", totalAPagar);

    return 0;
}
