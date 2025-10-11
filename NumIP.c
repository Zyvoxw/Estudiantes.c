#include <stdio.h>
int main(int argc, char const *argv[])
{
    int Num;
    printf("Ingrese un número cualquiera: ");
    scanf("%d", &Num);

    if (Num % 2 == 0)
    {
        printf("%d es par\n", Num);
    }
    else
    {
        printf("%d es impar\n", Num);
    }

    return 0;
}
