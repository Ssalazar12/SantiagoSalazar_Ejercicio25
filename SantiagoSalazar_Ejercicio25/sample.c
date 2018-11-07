/* Se va a generar una distribucion normal usando N, mu y sig como inputs
en donde N es el numero de muestras
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

/* --------CONSTANTES GLOBALES------------------------------- */

#define  PI 3.14159265359

/* --------VARIABLES GLOBALES------------------------------ */

float mu;
float sig;	
int N;


/* --------FUNCIONES------------------------------ */



void gauss(float *savein){
	/* Recibe pointer en donde va a guardar las muestras normales */
        int i;
        double w;
        double u1;
       	double u2;
        double x;
        
	for(i=0;i<N;i++){
		
		u1 = -1 + ((double) rand () / (double)RAND_MAX) * 2;
      	u2 = -1 + ((double) rand () / (double)RAND_MAX) * 2;
      	w = pow (u1, 2) + pow (u2, 2);
      	
		while(w>=1 || w==0){
			u1 = -1 + ((double) rand () / RAND_MAX) * 2;
      		u2 = -1 + ((double) rand () / RAND_MAX) * 2;
      		w = pow (u1, 2) + pow (u2, 2);
		}
		x=u1*sqrt(-2*log(w)/w);
		savein[i]=mu + sig*(double)x;
	}
}	

void files(float *takefrom){
	/*Crea archivos .dat con los resultados para ser procesados en python*/
	FILE *fsample;
	fsample = fopen("sample.dat", "w+"); //opens the stream
	int i;
	
	for(i=0; i<N; i++){
		fprintf(fsample, "%f \n", takefrom[i]);
	}
	
	fclose(fsample); //closes the stream
}	
	
/* --------CUERPO DEL PROGRAMA------------------------------- */
/*argc es el numero de argumentos incluyendo el comando con el que corro el programa, argv son mi para*/

int main(int argc, char *argv[]){
	float *samples;

	N=atoi(argv[1]);
	mu = atof(argv[2]);
	sig= atof(argv[3]);
	/*crea el espacio de samples con los valores dados*/
 	samples=malloc(N*sizeof(float));
	
	/* hace que el seed sea el tiempo para obtener numeros pseudo aleatorios*/
	srand(time(NULL));
   	
 

 	
 	
 	

 	gauss(samples);
 	
 	files(samples);
 	
   	return 0;  
}