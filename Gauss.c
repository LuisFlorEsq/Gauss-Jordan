#include<stdio.h>
// Si aun no han visto funciones, basta con que sepan que son subrutinas dentro del algoritmo,
// Que reciben datos de este y ejecutan un algoritmo por separado.
void imprimir(int filas, int columnas, float * );
void pivotear(int filas, int columnas, float *, float*,float*,int j);

main()
{
	// Definicion de las dimenciones de la matriz y captura de los datos de esta
	int filas = 0, columnas = 0;
	
	printf("Ingresa el numero de filas: ");
	scanf("%i",&filas);
	printf("\nIngresa el numero de columanas: ");
	scanf("%i",&columnas);
	columnas = columnas + 1;
	float MatrizA[filas][columnas];
	
	printf("\nIngresa los valores de la matriz A:");
	for(int j=0; j<columnas;j++)
	{
		for(int i = 0; i<filas; i++)
		{
			if (columnas - 1 == j)
			{
				printf("\nIngresa los datos del vector de resultados");
			}
			printf("\nIngresa el valor de en (%i,%i): ",i+1,j+1);
			scanf("%f",&MatrizA[i][j]);
		}
	}
	// Impresion de la matriz inicial
	printf("Matriz Inicial\n");
	imprimir(filas,columnas,&MatrizA[0][0]);
	printf("\n");
	
	//Metodo de gauss-jordan
	
	float pivoteaux = 0;
	float vectorPivote[columnas];
	float vectorPivoteaux[columnas];
	float n = 0;
    

        for(int j =0; j<columnas-1;j++)
	    {
	    	// Se necesita la posicion j, el vector pivote
	    	pivotear(filas, columnas,&MatrizA[0][0], &vectorPivote[0], &vectorPivoteaux[0], j);
	    	
		    for(int i = 0; i<filas; i++)
	        {
	        	printf("\n(%d,%d)\n",i+1,j+1);
			 //Cuando i sea diferente de j se asigna el valor n, y se restringe para evitar que tome el valor de columna de resultados
			 if (i != j && j < columnas-1)
	         {
	         	n = MatrizA[i][j];
	         	
	         }
	         
	     
		 // Opera sobre toda la fila sin importar que esta contenga ya un pivote
	        for(int k = 0; k < columnas; k++)
			{
				MatrizA[i][k] = (-1*n*vectorPivote[k]) + MatrizA[i][k];
				
			}
			 
			 if(i == j )
			 {
			 	// Para evitar que se altere la fila pivote se realizan las siguientes asignaciones.
				for(int l = 0; l < columnas; l++)
				{
					MatrizA[i][l] = vectorPivoteaux[l];
					if(MatrizA[i][l] == -0)
					{
						MatrizA[i][l] = 0;
					}
					
				}		
			 }
	         imprimir(filas,columnas,&MatrizA[0][0]);			
	    	}
	    	
	    	// Se limpia la fila pivote para evitar arrastrar basura al igual que n 
	    	n = 0;		
	        for(int k = 0; k < columnas; k++)
	    	{
	    	     vectorPivote[k] = 0;
			}
	    	
	
	}			
	  
}

void imprimir(int filas, int columnas, float * MatrizA)
{
	printf("\n\n");
	int contar = 0;
	   
	for(int i = 0; i<filas*columnas; i++)
	{
		if(contar < columnas)
		{
			printf(" %f ",MatrizA[i]);
			contar++;
		}
		else
		{
			contar = 0;
			printf("\n");
			printf(" %f ",MatrizA[i]);
			contar++;
		}
		
	}
	
}

void pivotear(int filas, int columnas, float *MatrizA, float *vectorPivote, float *vectorPivoteaux, int j)
{
	float pivoteaux = 0;
	float matrizTemporal[filas][columnas];
	int sumi = 0;
	//Copiamos los datos de la MatrizA  a una matriz temporal porque al enviarla como apuntador esta se convierte en un vector.
	
	for (int  i =  0; i < filas; i++)
	{
		for( int k = 0; k < columnas; k++)
		{
			matrizTemporal[i][k] = MatrizA[sumi];
			sumi ++;
		}
	}
	
	//Una vez copiados los datos en una matriz temporal operamos para obtener el pivote y su fila asociada

		for(int i = 0; i<filas;i++)
		{
			if(i == j )
			 {
			 	// Suponemos que el pivote esta en la posicion (i,j) y lo calculamos dividiendo el numero en esa posicion entre si mismo.
					pivoteaux = matrizTemporal[i][j];
					printf("Pivote: %f\n",pivoteaux);
				// En la matriz temporal realizamos la divicion de toda la fila donde se encuentra el pivote y la guardamos en la matriz temporal y en dos vectores que usaremos mas tarde.	
					for(int l = 0; l < columnas; l++)
					{
						matrizTemporal[i][l] = matrizTemporal[i][l] / pivoteaux;
						vectorPivote[l] = matrizTemporal[i][l];
						vectorPivoteaux[l] = matrizTemporal[i][l];
						
					}		
			 }
		}

		
	//Luego pasamos los datos de la matriz temporal a nuestra matriz de trabajo MA.
	sumi = 0;
	
	for (int  i =  0; i < filas; i++)
	{
		for( int k = 0; k < columnas; k++)
		{
			MatrizA[sumi] = matrizTemporal[i][k];
			sumi++;
		}
	}
	
	
}