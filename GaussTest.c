#include "GaussJordan.h"

/*
 *Nombre: Flores Esquivel Luis Antonio
 *Grupo: 2BM1
 *Carrera: IIA
 *Ultima modificacion: 22/04/22
 */

int main(int argc, char **argv)
{
    // Variables necesarias para el problema 1
    int nv = 0;
    int ncv = 0;
    int ncu = 0;
    double v = 0;
    double u = 0;
    int nM;

    // Variables de control
    int i;
    int j;
    int flag2;
    int opc = 0;

    system("cls");

    printf("----------------------------------------");
    printf("\nBienvenido, para iniciar selecciona una opcion de las disponibles:\n");
    printf("NOTA: Ingresa solo el numero de la opcion\n");

    do
    {
        printMenu();

        fflush(stdin);
        scanf("%d", &opc);

        // Declaramos los posibles flujos de la opcion que decida el usuario

        switch (opc)
        {
        case 1:

            printf("----------------------------------------");
            printf("\nHas elegido la opcion 1: Combinaciones lineales\n");
            printf("\nCuantas V desea ingresar?\n");
            fflush(stdin);
            scanf("%d", &nv);
            printf("\nIngrese el numero de componentes de las V\n");
            fflush(stdin);
            scanf("%d", &ncv);
            ncu = ncv;
            pdouble arregloU = crear_arreglo(ncu);
            matriz matrizV = crear_matriz(nv, ncv);

            for (i = 0; i < nv; i++)
            {
                printf("Ingrese las componentes del vector v(%d)\n", i + 1);

                for (j = 0; j < ncv; j++)
                {
                    printf("Componente (%d): ", j + 1);
                    fflush(stdin);
                    scanf("%lf", &v);
                    matrizV[i][j] = v;
                }
            }

            printf("\nIngrese las componentes del vector U:\n");
            for (i = 0; i < ncu; i++)
            {
                printf("Componente (%d): ", i + 1);
                fflush(stdin);
                scanf("%lf", &u);
                arregloU[i] = u;
            }

            // Imprimimos los datos con los que estaremos operando

            printf("\n------------------------------\n");
            printf("La matriz que contiene a nuestros vectores V:\n");
            printf("\n------------------------------\n");
            imprimir_matriz(matrizV, nv, ncv);
            printf("\n------------------------------\n");
            printf("El arreglo que contiene las componentes de nuestro vector U:");
            printf("\n------------------------------\n");
            imprimir_arreglo(arregloU, ncu);
            printf("\n------------------------------\n");

            // Creamos nuestra matriz aumentada que contiene a los vectores V y el vector U
            nM = nv + 1;
            matriz matrizGauss = crear_matriz(ncv, nM);

            for (j = 0; j < nv; j++)
            {
                for (i = 0; i < ncv; i++)
                {

                    matrizGauss[i][j] = matrizV[j][i];
                    // cont++;
                }
            }

            for (i = 0; i < ncv; i++)
            {
                matrizGauss[i][nv] = arregloU[i];
            }

            printf("\n------------------------------\n");
            printf("La matriz a la que le buscaremos su rango:\n");
            printf("\n------------------------------\n");
            imprimir_matriz(matrizGauss, ncv, nM);
            printf("\n------------------------------\n");

            printf("Aplicamos Gauss Jordan");
            Gauss(matrizGauss, ncv, nM);
            printf("\nMatriz despues de hacer 0 por debajo y arriba de la diagonal:\n");
            imprimir_matriz(matrizGauss, ncv, nM);
            int rango = 0;

            // Obtenemos el rango de la matriz final para determinar si tiene solucion, infinidad de soluciones o no tiene solucion

            fflush(stdin);
            flag2 = CalcularRango(matrizGauss, ncv, nM, &rango);
            printf(" Bandera despues de calcular el rango = %d", flag2);
            // printf("%d", flag2);
            resultadoFinal(matrizGauss, ncv, nM, flag2, rango, opc);
            /*printf("\nVector U\n");
            imprimir_arreglo(arregloU, ncu);
            printf("\nMatriz con los vectores V\n");
            imprimir_matriz(matrizV, nv, ncv);
            */
            free(matrizV);
            free(arregloU);
            free(matrizGauss);
            rango = 0;
            flag2 = 0;

            break;

        case 2:
            printf("----------------------------------------");
            printf("\nHas elegido la opcion 2: Espacio generado\n");

            printf("\nCuantas V desea ingresar?\n");
            fflush(stdin);
            scanf("%d", &nv);
            printf("\nIngrese el numero de componentes de las V (orden)\n");
            fflush(stdin);
            scanf("%d", &ncv);
            matriz matrizV2 = crear_matriz(nv, ncv);

            for (i = 0; i < nv; i++)
            {
                printf("Ingrese las componentes del vector v(%d)\n", i + 1);

                for (j = 0; j < ncv; j++)
                {
                    printf("Componente (%d): ", j + 1);
                    fflush(stdin);
                    scanf("%lf", &v);
                    matrizV2[i][j] = v;
                }
            }

            // Creamos nuestra matriz aumentada que contiene a los vectores V y el vector U

            matriz matrizGauss2 = crear_matriz(ncv, nv);

            for (j = 0; j < nv; j++)
            {
                for (i = 0; i < ncv; i++)
                {

                    matrizGauss2[i][j] = matrizV2[j][i];
                    // cont++;
                }
            }

            free(matrizV2);

            printf("\n------------------------------\n");
            printf("La matriz a la que le buscaremos su rango:\n");
            printf("\n------------------------------\n");
            imprimir_matriz(matrizGauss2, ncv, nv);
            printf("\n------------------------------\n");

            printf("Aplicamos Gauss Jordan");
            Gauss(matrizGauss2, ncv, nv);
            printf("Bandera = %d", flag2);
            printf("\nMatriz despues de hacer 0 por debajo y arriba de la diagonal:\n");
            imprimir_matriz(matrizGauss2, ncv, nM);
            rango = 0;
            // Obtenemos el rango de la matriz final para determinar si tiene solucion, infinidad de soluciones o no tiene solucion

            flag2 = CalcularRango(matrizGauss2, ncv, nv, &rango);

            // printf("%d", flag2);
            resultadoFinal(matrizGauss2, ncv, nv, flag2, rango, opc);
            rango = 0;
            free(matrizGauss2);

            break;

        case 3:
            printf("----------------------------------------");
            printf("\nHas elegido la opcion 3: Independencia lineal\n");

            printf("\nCuantas V desea ingresar?\n");
            fflush(stdin);
            scanf("%d", &nv);
            printf("\nIngrese el numero de componentes de las V (orden)\n");
            fflush(stdin);
            scanf("%d", &ncv);
            matriz matrizV3 = crear_matriz(nv, ncv);

            for (i = 0; i < nv; i++)
            {
                printf("Ingrese las componentes del vector v(%d)\n", i + 1);

                for (j = 0; j < ncv; j++)
                {
                    printf("Componente (%d): ", j + 1);
                    fflush(stdin);
                    scanf("%lf", &v);
                    matrizV3[i][j] = v;
                }
            }

            // Creamos nuestra matriz aumentada que contiene a los vectores V y el vector U
            nM = nv + 1;
            matriz matrizGauss3 = crear_matriz(ncv, nM);

            for (j = 0; j < nv; j++)
            {
                for (i = 0; i < ncv; i++)
                {

                    matrizGauss3[i][j] = matrizV3[j][i];
                    // cont++;
                }
            }

            free(matrizV3);

            printf("\n------------------------------\n");
            printf("La matriz a la que le buscaremos su rango:\n");
            printf("\n------------------------------\n");
            imprimir_matriz(matrizGauss3, ncv, nM);
            printf("\n------------------------------\n");

            printf("Aplicamos Gauss Jordan");
            Gauss(matrizGauss3, ncv, nM);

            printf("\nMatriz despues de hacer 0 por debajo y arriba de la diagonal:\n");
            imprimir_matriz(matrizGauss3, ncv, nM);
            rango = 0;
            // Obtenemos el rango de la matriz final para determinar si tiene solucion, infinidad de soluciones o no tiene solucion

            flag2 = CalcularRango(matrizGauss3, ncv, nM, &rango);
            printf("Bandera = %d", flag2);
            // printf("%d", flag2);
            resultadoFinal(matrizGauss3, ncv, nM, flag2, rango, opc);
            rango = 0;
            free(matrizGauss3);

            break;

        case 4:
            printf("----------------------------------------");
            printf("\nHas elegido la opcion 4: Base de un espacio vectorial\n");

            break;

        case 5:
            printf("\nHasta luego!");
            break;

        default:

            // Solicitamos al usuario que ingrese un valor valido
            printf("\nPor favor, ingresa una opcion valida\n");

            break;
        }

    } while (opc != 5);
    return 0;
}