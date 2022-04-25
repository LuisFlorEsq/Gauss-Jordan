/*
 *Nombre: Flores Esquivel Luis Antonio
 *Grupo: 2BM1
 *Carrera: IIA
 *Ultima modificacion: 22/04/22
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>



typedef double **matriz;
typedef double *pdouble;

void printMenu();
matriz crear_matriz(int filas, int columnas);
void imprimir_matriz(matriz matrizX, int filas, int columnas);
pdouble crear_arreglo(int elementos);
void imprimir_arreglo(pdouble pintX, int elementos);
void Gauss(matriz matrizX, int filas, int columnas);
int CalcularRango(matriz matrizX, int filas, int columnas, int *rango);
void resultadoFinal(matriz matrizX, int filas, int columnas, int flag, int rango, int opcion);