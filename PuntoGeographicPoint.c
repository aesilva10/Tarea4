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
void montecarlo(int **mat);
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
	numerosx(n_col);
	numerosy(n_fil);	
	printf("%d\n",R(mat,numerosx(n_col),numerosy(n_fil)));
		
}


int numerosx(int n_col)
{		
	int M=0;
	int N=n_col;
	int numero=rand()%(N-M+1)+M;
	return numero;	
}
//numeros aleatorios en y
int numerosy(int n_fil)
{	
	int M=0;
	int N=n_fil;
	int numero=rand()%(N-M+1)+M;
	return numero;
}

//funcion que calcula el r maximo
int R(int **mat, int x, int y)
{	
	int rmax= n_fil/2;
	for(int r=1; r<rmax;r++)
	{
		float m=r/sqrt(2);
		for(int i=0;i<trunc(m);i++)
		{
			for(int j=0; j<trunc(m);j++)
			{
				if(mat[inx(x+i)][iny(j)]!=1 && mat[inx(x-i)][iny(j)]!=1 && mat[inx(i)][iny(y+j)]!=1 && mat[inx(i)][iny(y-j)]!=1 && mat[inx(x+i)][iny(y+j)]!=1 && mat[inx(x-i)][iny(y-j)]!=1 && mat[inx(x+i)][iny(y-j)]!=1 && mat[inx(x-i)][iny(y+j)]!=1 && mat[inx(x)][iny(y)]!=1)
					{								
					continue;										
					}
				else
				{					
					break;	
					return r;				
				}		
			}		
		return r;
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

void montecarlo(int **mat)
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
	return x_last,y_last,r_last;	
	printtf("Las coordenadas del punto mas alejado son: %d %d", x_last,y_last);
	}
	FILE *rtax;
    	rtax=fopen("datos.txt","w+");
	fprintf(rtax,"%f %f\n", x_last,y_last,r_last);
	fclose(rtax);
}







	







