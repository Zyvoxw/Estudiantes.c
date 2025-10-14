/*Integrantes: Remmy y Oscar
Fecha: 12/10/2025
*/
#include <stdio.h>

int main()
{
    int Aprobados[3] = {0};   
    int Reprobados[3] = {0}; 
    float notas[5][3];
    float promEstudiantes[5];
    float promAsignaturas[3];
    float NotaMaxE[5]; 
    float NotaMinE[5];
    float NotaMaxA[3];
    float NotaMinA[3];
    float suma=0, sumaA=0;
    int resultado;
    char estudiantes[5][50];    
    char asignaturas[3][50];   

    for (int i = 0; i < 5; i++) {
        printf("Ingrese el nombre del estudiante %d: ", i + 1);
        scanf(" %[^\n]", estudiantes[i]); 
    }

    for (int j = 0; j < 3; j++) {
        printf("Ingrese el nombre de la asignatura %d: ", j + 1);
        scanf(" %[^\n]", asignaturas[j]);
    }

    for (int i = 0; i < 5; i++)
    {
        suma = 0;
        printf("\nIngrese las notas del estudiante %s: \n", estudiantes[i]);
        for (int j = 0; j < 3; j++)
        {
            do {
                printf("%s: ", asignaturas[j]);
                resultado = scanf("%f", &notas[i][j]);

                if (resultado != 1) {
                    printf("Ingrese solo numeros\n");
                    while (getchar() != '\n'); 
                    notas[i][j] = -1;          
                    continue;
                }

                if (notas[i][j] < 0 || notas[i][j] > 10) {
                    printf("Nota invalida, debe estar entre 0 y 10\n");
                }

            } while (notas[i][j] < 0 || notas[i][j] > 10);

            while (getchar() != '\n');  
            suma += notas[i][j];
        }
        promEstudiantes[i] = suma / 3;
    }

    for (int j = 0; j < 3; j++)
    {
        sumaA = 0;
        for (int i = 0; i < 5; i++)
        {
            sumaA += notas[i][j];
            if (notas[i][j] >= 6)
                Aprobados[j]++;
            else 
                Reprobados[j]++;
        }
        promAsignaturas[j] = sumaA / 5;
    }

    for (int i = 0; i < 5; i++)
    {
        NotaMaxE[i] = notas[i][0];
        NotaMinE[i] = notas[i][0];
        for (int j = 1; j < 3; j++)
        {
            if (notas[i][j] > NotaMaxE[i])
                NotaMaxE[i] = notas[i][j];
            if (notas[i][j] < NotaMinE[i])
                NotaMinE[i] = notas[i][j];
        }
    }
    for (int j = 0; j < 3; j++){
        NotaMaxA[j] = notas[0][j];
        NotaMinA[j] = notas[0][j];
        for (int i = 1; i < 5; i++)
        {
            if (notas[i][j] > NotaMaxA[j])
                NotaMaxA[j] = notas[i][j];
            if (notas[i][j] < NotaMinA[j])
                NotaMinA[j] = notas[i][j];
        }
    }

    printf("\nPromedio por estudiante:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s: %.2f\n", estudiantes[i], promEstudiantes[i]);
    }

    printf("\nPromedio por asignatura:\n");
    for (int j = 0; j < 3; j++) {
        printf("%s: %.2f\n", asignaturas[j], promAsignaturas[j]);
    }

    printf("\nNotas maxima y minima por estudiante:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s Nota mas alta %.2f -- Nota mas baja%.2f\n", estudiantes[i], NotaMaxE[i], NotaMinE[i]);
    }

    printf("\nNotas maxima y minima por asignatura:\n");
    for (int j = 0; j < 3; j++) {
        printf("%s Nota mas alta: %.2f  Nota mas baja: %.2f\n", asignaturas[j], NotaMaxA[j], NotaMinA[j]);
    }

    printf("\nCantidad de estudiantes aprobados y reprobados por asignatura:\n");
    for (int j = 0; j < 3; j++) {
        printf("%s Aprobados: %d Reprobados: %d\n", asignaturas[j], Aprobados[j], Reprobados[j]);
    }

    return 0;  
}
