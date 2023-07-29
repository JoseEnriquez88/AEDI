#include<stdio.h>
#include<string.h>

void iniciarProceso();
void grabarArchivo();
void finalizarProceso();

void ingresarRespuesta();
void ingresarDatosPeliculas();
void grabarRegistroPeliculas();

typedef struct{
	int codPelicula;
	char nombrePelicula[30];
	int genero;
	int cantEntradasVendidas;
	int duracionPelicula;	
}tr_peliculas;

tr_peliculas vr_peliculas;
FILE * vf_peliculas;

char respuesta;


int main(){
	iniciarProceso();
	grabarArchivo();
	finalizarProceso();	
	
	return 0;
}

void iniciarProceso(){
	vf_peliculas = fopen("Cinemacenter.dat", "wb");
	printf("\t\t\t***REGISTRO DE PELICULAS CREADO**\n\n");
}

void grabarArchivo(){
	ingresarRespuesta();
	while(respuesta != 'n'){
		ingresarDatosPeliculas();
		grabarRegistroPeliculas();
		ingresarRespuesta();
	}
}

void ingresarRespuesta(){
	printf("\nDesea ingresar datos al archivo? s/n: ");
	fflush(stdin);
	respuesta = tolower(respuesta);
	scanf("%c", &respuesta);
	
}

void ingresarDatosPeliculas(){
		printf("\n1. Digite codigo de pelicula: ");
		scanf("%d", &vr_peliculas.codPelicula);
		printf("2. Digite nombre de pelicula: ");
		fflush(stdin);
		scanf("%[^\n]s", &vr_peliculas.nombrePelicula);
		printf("3. Digite codigo de genero de pelicula:\n");
		printf("1-Suspenso, 2-Terro, 3-Romantica, 4-Infantil, 5-Juvenil, 6-Drama, 7-Aventuras: ");
		scanf("%d", &vr_peliculas.genero);
		printf("4. Digite cantidad de entradas vendidas: ");
		scanf("%d", &vr_peliculas.cantEntradasVendidas);
		printf("5. Digite la duracion de la pelicula: ");
		scanf("%d", &vr_peliculas.duracionPelicula);
}

void grabarRegistroPeliculas(){
	fwrite(&vr_peliculas, sizeof(tr_peliculas), 1, vf_peliculas);
	printf("\n\n\t\t\t***REGISTRO DE PELICULA AGREGADO***\n\n");
}

void finalizarProceso(){
	fclose(vf_peliculas);
}
