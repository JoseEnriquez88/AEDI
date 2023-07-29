#include<stdio.h>
#include<ctype.h>

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
	int entradasVendidas;
	int duracionPeliculas;
}tr_cinemacenter;

tr_cinemacenter vr_cine;
FILE * vf_cines;

char respuesta;

int main(){
	iniciarProceso();
	grabarArchivo();
	finalizarProceso();	
	return 0;
}

void iniciarProceso(){
	vf_cines = fopen("Cinemacenter.dat", "wb");
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
		scanf("%d", &vr_cine.codPelicula);
		printf("2. Digite nombre de pelicula: ");
		fflush(stdin);
		scanf("%[^\n]s", &vr_cine.nombrePelicula);
		printf("3. Digite codigo de genero de pelicula:\n");
		printf("1-Suspenso, 2-Terro, 3-Romantica, 4-Infantil, 5-Juvenil, 6-Drama, 7-Aventuras: ");
		scanf("%d", &vr_cine.genero);
		printf("4. Digite cantidad de entradas vendidas: ");
		scanf("%d", &vr_cine.entradasVendidas);
		printf("5. Digite la duracion de la pelicula: ");
		scanf("%d", &vr_cine.duracionPeliculas);
}

void grabarRegistroPeliculas(){
	fwrite(&vr_cine, sizeof(tr_cinemacenter), 1, vf_cines);
	printf("\n\n\t\t\t***REGISTRO DE PELICULA AGREGADO***\n\n");
}

void finalizarProceso(){
	fclose(vf_cines);
}
