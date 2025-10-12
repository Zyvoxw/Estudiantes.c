    /*Integrantes: Iveth Castro,  Zaskia Sunta
    Fecha: 12/10/2025
    Descripción: Programa de calificaciones*/
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

        for (int i = 0; i < 5; i++)
        {
            suma = 0;
            printf("Ingrese las notas del estudiante %d: \n", i+1);
            for (int j = 0; j < 3; j++)
            {
            do {
                printf("Asignatura %d: ", j + 1);
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
        printf("Promedio por estudiante:\n");
        for (int i = 0; i < 5; i++) {
            printf("Estudiante %d: %.2f\n", i + 1, promEstudiantes[i]);
        }

        printf("Promedio por asignatura:\n");
        for (int j = 0; j < 3; j++) {
            printf("Asignatura %d: %.2f\n", j + 1, promAsignaturas[j]);
        }
        printf("Notas maxima y minima por estudiante:\n");
        for (int i = 0; i < 5; i++) {
            printf("Estudiante %d --Max: %.2f--Min: %.2f\n", i + 1, NotaMaxE[i], NotaMinE[i]);
        }

        printf("Notas maxima y minima por asignatura:\n");
        for (int j = 0; j < 3; j++) {
            printf("Asignatura %d --Max: %.2f--Min: %.2f\n", j + 1, NotaMaxA[j], NotaMinA[j]);
        }

        return 0;  
    }

