#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main(void){
	FILE *file;
	file=fopen("map_data.txt","r");
	int len=500;
	char line_buffer[len];
	char *split_buffer;
	int i=0;
	int j=0;
	double *data= malloc(n*sizeof(double));		
	while(fgets(line_buffer,len,file)){
		j=0;
		split_buffer=strtok(line_buffer);
		while(split_buffer !=NULL){
			if(j!=0){
				matriz[i][j-1]=atof(split_buffer);}
			split_buffer=strtok(NULL);
			j+=1;
		}
	i+=1;
	}
}
