#include "GaussJordan.h"
/*
 *Nombre: Flores Esquivel Luis Antonio
 *Grupo: 2BM1
 *Carrera: IIA
 *Ultima modificacion: 22/04/22
 */

// Imprimimos el menu de opciones

void printMenu()
{
    printf("\n");
    printf("1.- Combinaciones lineales\n");
    printf("2.- Espacio generado\n");
    printf("3.- Independencia lineal\n");
    printf("4.- Base de un espacio vectorial\n");
    printf("5.- Salir del sistema\n");
    printf("\n");
}

// Creamos nuestra matriz con la que trabajaremos

matriz crear_matriz(int filas, int columnas)
{

    matriz aux;
    aux = (matriz)malloc(filas * sizeof(pdouble));
    for (int i = 0; i < filas; i++)
    {
        aux[i] = (pdouble)malloc(columnas * sizeof(double));
    }

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            aux[i][j] = 0;
        }
    }
    return aux;
}

void imprimir_matriz(matriz matrizX, int filas, int columnas)
{

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("%lf\t", matrizX[i][j]);
        }
        printf("\n");
    }
}

pdouble crear_arreglo(int elementos)
{

    pdouble aux;
    aux = (pdouble)malloc(elementos * sizeof(double));

    for (int i = 0; i < elementos; i++)
    {
        aux[i] = 0;
    }
    return aux;
}

void imprimir_arreglo(pdouble pdoubleX, int elementos)
{

    for (int i = 0; i < elementos; i++)
    {
        printf("%lf\t", pdoubleX[i]);
    }
    printf("\n");
}

void Gauss(matriz matrizX, int filas, int columnas)
{
    printf("\nLlegamos\n");
    int flag = 0;
    double pivote;
    int i, j, k, c;

    for (i = 0; i < filas; i++)
    {
        pivote = matrizX[i][i];
        printf("\nPIVOTE: %lf\n", pivote);

        if (matrizX[i][i] == 0)
        {
            c = 1;
            while ((c + i) < filas && matrizX[i + c][i] == 0)
            {
                c++;
            }

            if ((c + i) == filas)
            {
                flag = 1;
                break;
            }
            // Cambiamos el pivote y toda la fila
            for (j = i, k = 0; k <= columnas; k++) // Checar esto despues
            {

                /*pdouble fila1 = matrizX[i];
                pdouble aux = fila1;
                pdouble fila2 = matrizX[i + 1];
                matrizX[i] = fila2;
                matrizX[i + 1] = aux;
                pivote = matrizX[i][i];
                */

                int aux2 = matrizX[j][k];
                matrizX[j][k] = matrizX[j + c][k];
                matrizX[j + c][k] = aux2;
            }
        }

        printf("\nMatriz en i = %d\n", i);
        imprimir_matriz(matrizX, filas, columnas);

        /*
        for (k = 0; k < columnas; k++)
        {
            matrizX[i][k] = matrizX[i][k] / matrizX[i][i];
        }
*/
        for (j = 0; j < filas; j++)
        {
            if (i != j)
            {
                printf("\nMatriz[j][i] = %lf, Matriz[i][i] = %lf \n", matrizX[j][i], matrizX[i][i]);
                double aux1 = (double)matrizX[j][i];
                double aux2 = (double)matrizX[i][i];
                // printf("\nAuxiliar: %.2lf\n", aux);

                for (k = 0; k < columnas; k++)
                {
                    matrizX[j][k] = ((aux2)*matrizX[j][k]) - ((aux1) * (matrizX[i][k]));
                }
            }
        }
    }

    // imprimir_matriz(matrizX, filas, columnas);
    // return flag;
}

int CalcularRango(matriz matrizX, int filas, int columnas, int *rango)
{

    int i, j;
    int sumaA = 0, sumaB = 0, rangoA = 0, rangoB = 0, flag = 0;
    int incognitas = (columnas - 1);

    // flag == 2 Infinidad de soluciones
    // flag == 3 No hay solucion

    // Matriz A (Matriz A* o aumentada)
    for (i = 0; i < filas; i++)
    {
        // Sumaremos todos los elementos de cada una de las filas, por lo que es necesario limpiar la suma cada que pasemos a otra fila
        sumaA = 0;

        for (j = 0; j < columnas; j++)
        {
            sumaA = sumaA + matrizX[i][j];
        }

        if (sumaA != 0)
        {
            rangoA++;
        }
    }

    // Matriz B (Matriz A o matriz original)
    for (i = 0; i < filas; i++)
    {
        sumaB = 0;
        for (j = 0; j < (columnas - 1); j++)
        {
            sumaB = sumaB + matrizX[i][j];
        }
        if (sumaB != 0)
        {
            rangoB++;
        }
    }

    printf("\nRango A: %d Rango B: %d Incognitas: %d\n", rangoA, rangoB, incognitas);

    if (rangoA == rangoB && rangoA == incognitas)
    {
        flag = 0;
        printf("Flag 0; ");
    }
    else if (rangoA == rangoB && rangoA < incognitas)
    {
        flag = 2;
        printf("Flag 2; ");
    }
    else if (rangoA != rangoB)
    {
        flag = 3;
        printf("Flag 3; ");
    }

    *rango = rangoA;

    printf("Bandera = %d", flag);
    return flag;
}

void resultadoFinal(matriz matrizX, int filas, int columnas, int flag, int rango, int opcion)
{
    printf("\n---------------------\n");
    printf("\nLA MATRIZ\n");
    imprimir_matriz(matrizX, filas, columnas);
    printf("\nEl resultado es:\n");

    if (flag == 2)
    {
        printf("\nEl sistema tiene infinidad de soluciones\n");

        if (opcion == 1)
        {
            printf("\nPor lo tanto el vector U SI es una combinacion lineal de los vectores V\n");
        }
        else if (opcion == 2)
        {
            printf("\nPor lo tanto el conjunto de vectores V, SI es un campo generador de R(%d)\n", filas);
        }
        else if (opcion == 3)
        {
            printf("\nPor lo tanto el conjunto de vectores V, NO son linealmente independientes\n");
        }
    }
    else if (flag == 3)
    {
        printf("\nEl sistema no tiene solucion\n");
        if (opcion == 1)
        {
            printf("\nPor lo tanto el vector U NO es una combinacion lineal de los vectores V\n");
        }
        else if (opcion == 2)
        {
            printf("\nPor lo tanto el conjunto de vectores V, NO es un campo generador de R(%d)\n", filas);
        }
        else if (opcion == 3)
        {
            printf("\nPor lo tanto el conjunto de vectores V, NO son linealmente independientes\n");
        }
    }

    // Si el sistema tiene solucion unica la imprimimos
    else if (flag == 0)
    {
        printf("\nEl sistema tiene solucion unica\n");
        if (opcion == 1)
        {
            printf("\nPor lo tanto el vector U SI es una combinacion lineal de los vectores V\n");
            for (int i = 0; i < rango; i++)
            {
                printf("\nMatriz[i][columnas] = %lf, Matriz[i][i] = %lf \n", matrizX[i][columnas - 1], matrizX[i][i]);
                printf("x(%d) %lf ", i, matrizX[i][columnas - 1] / matrizX[i][i]);
            }
        }
        else if (opcion == 2)
        {
            printf("\nPor lo tanto el conjunto de vectores , SI son linealmente independientes\n");
        }
        else if (opcion == 3)
        {
            printf("\nPor lo tanto el conjunto de vectores V, SI son linealmente independientes\n");
        }
    }

    printf("\n---------------------\n");
}