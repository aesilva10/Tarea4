#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h> 
//numero de filas ycolumnas
int n_col=744;
int n_fil=500;
//funciones
int numerosx(int n_col);
int numerosy(int n_fil);
int R(int **mat);
//funcion principal
void main()
{
	//contadores
  	int i;
  	int j;
	//matriz de datos 
	int **mat=malloc(n_col*sizeof(int*)); 
	for(i=0;i<n_col;i++)
	{
		mat[i]=malloc(n_fil*sizeof(int));
	}
	FILE *file;
	// abrir el archivo
  	file=fopen("map_data.txt","r");
	for(i=0; i<n_col;i++)
	{
		for(j=0;j<n_fil;j++) 
		{
		//Llenar la matriz con los datos
		fscanf(file,"%d",&mat[i][j]);       		
		}  		
	}
	fclose(file);
	// semilla diferente dependiendo del tiempo hh:mm:ss del pc
	srand(time(NULL));
	// llamar las funciones
	numerosx(n_col);
	numerosy(n_fil);
	R(mat);

}
// declaracion numeros aleatorios x
int numerosx(int n_col)
{	
	int numero=rand()%(n_col+1);
	return numero;	
}
// declaracion numeros aleatorios en y
int numerosy(int n_fil)
{	
	int numero=rand()%(n_fil+1);
	return numero;
}	
// declaracion funcion que calcula el r maximo
int R(int **mat)
{	
	int rmax= (n_fil/2);
	for(int r=1; r<rmax;r++)
	{
		int m= pow(2,0.5)*r/2;
		for(int i=0;i<=m;i++)
		{
			for(int j=0; j<=m;j++)
			{
				if(mat[numerosx(n_col)+i+1][j]!=1 || mat[numerosx(n_col)+i+1][j]==NULL && mat[numerosx(n_col)-i-1][j]!=1 || mat[numerosx(n_col)-i-1][j]==NULL && mat[i][numerosy(n_fil)+j+1]!=1 || mat[i][numerosy(n_fil)+j+1]==NULL && mat[i][numerosy(n_fil)-j-1]!=1 || mat[i][numerosy(n_fil)-j-1]==NULL && mat[numerosx(n_col)+i][numerosy(n_fil)+j]!=1 && mat[numerosx(n_col)-i][numerosy(n_fil)-j]!=1 && mat[numerosx(n_col)+i][numerosy(n_fil)-j]!=1 && mat[numerosx(n_col)-i][numerosy(n_fil)+j]!=1)
					{
					continue;
					}
				else
					{
					return r;
					printf("%d\n",r);
					}
			}		
		}
	}
}
// Segmentation fault (core dumped) :(
