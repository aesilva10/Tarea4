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
int R(int **mat, int x, int y);
double montecarlo(int **mat);
int inx(int x);
int iny(int x);
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
	int x,y;	
	inx(x);
	iny(x);	
	R(mat,x,y);
	montecarlo(mat);

}
//numeros aleatorios x
int numerosx(int n_col)
{	
	int numero=rand()%(n_col);
	return numero;	
}
//numeros aleatorios en y
int numerosy(int n_fil)
{	
	int numero=rand()%(n_fil);
	return numero;
}	

// funcion que calcula el r maximo
int R(int **mat, int x, int y)
{	
	int *rad=malloc(744*sizeof(int));
	int rmax= n_fil/2;
	for(int r=2; r<rmax;r++)
	{
		int m=r/pow(2,0.5);
		for(int i=0;i<m;i++)
		{
			for(int j=0; j<m;j++)
			{
				if(mat[inx(x+i)][iny(j)]!=1 && mat[inx(x-i)][iny(j)]!=1 && mat[inx(i)][iny(y+j)]!=1 && mat[inx(i)][iny(y-j)]!=1 && mat[inx(x+i)][iny(y+j)]!=1 && mat[inx(x-i)][iny(y-j)]!=1 && mat[inx(x+i)][iny(y-j)]!=1 && mat[inx(x-i)][iny(y+j)]!=1 && mat[inx(x)][iny(y)]!=1)
					{								
					continue;										
					}
					else
					{
					return r;					
					break;
					}
			}
		}
	}
}
int inx(int x)
{	
	if(x<0)
	{
		return x+n_col;
	}	
	if(x>n_col)
	{
		return x-n_col;
	}
	if(x<=n_col && x>=0)
	{
		return x;
	}
}
int iny(int x)
{	
	if(x<0)
	{
		return x+n_fil;
	}	
	if(x>n_fil)
	{
		return x-n_fil;
	}
	if(x<=n_fil && x>=0)
	{
		return x;
	}
}
double montecarlo(int **mat)
{
	double x_new, x_last, y_new, y_last,r_new, r_last, alpha;
	double delta=0.5;
	x_last=numerosx(n_col)-1;
	y_last=numerosy(n_col)-1;
	r_last=R(mat,x_last,y_last);
	for(int i=0;i<n_col;i++)
	{
	x_new=x_last + (numerosx(n_col)-1)*delta;
	y_new=y_last + (numerosy(n_fil)-1)*delta;
	r_new=R(mat,x_new,y_new);
	alpha=r_new/r_last;
		if(alpha>1)
		{
			alpha=1;	
		}
		if(alpha>numerosx(1))
		{
			x_new=x_last;
			y_new=y_last;
			r_new=r_last;	
		}
	printtf("%f %f %f\n", x_last,y_last,r_last);
	}
}












	






