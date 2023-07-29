#include<stdio.h>

void iniciarProceso();
void procesarDatos();
void finalizarProceso();


void obtenerPeliculas();
void imprimirSiAventuraMas1000();
void mostrarPorPantalla();
void acumularEntradasPorGenero();	



typedef struct{
	int codPelicula;
	char nombrePelicula[30];
	int genero;
	int entradasVendidas;
	int duracionPeliculas;
}tr_cinemacenter;

tr_cinemacenter vr_cine;
FILE * vf_cines;

int vGeneroCantidad[7];

int main(){
	iniciarProceso();
	procesarDatos();
	mostrarPorPantalla();
	finalizarProceso();	
	
	return 0;
}

void iniciarProceso(){
	int i=0;
	for(i=0;i<7;i++){
		vGeneroCantidad[i] = 0;
	}
	
	
	vf_cines = fopen("Cinemacenter.dat", "rb");
	printf("\t\t\t**REGISTRO DE PELICULAS CINEMACENTER**\n\n");
}

void procesarDatos(){
	obtenerPeliculas();
	while(!feof(vf_cines)){
		imprimirSiAventuraMas1000();
		acumularEntradasPorGenero();
		obtenerPeliculas();
	}
}

void imprimirSiAventuraMas1000(){
	int i=0;
	if(vr_cine.genero == 7 && vr_cine.entradasVendidas > 1000){
		for(i=0;i<strlen(vr_cine.nombrePelicula);i++){
			vr_cine.nombrePelicula[i] = toupper(vr_cine.nombrePelicula[i]);
		}
		
		printf("\nNombre pelicula|\tDuracion en minutos|\tCantidad entradas vendidas.\n");
		printf("%s |\t %d min|\t %d", vr_cine.nombrePelicula, vr_cine.duracionPeliculas, vr_cine.entradasVendidas);		
	}
	
}

void acumularEntradasPorGenero(){
	vGeneroCantidad[vr_cine.genero-1] += vr_cine.entradasVendidas;
}

void mostrarPorPantalla(){
	/*printf("\nSuspenso: %d", vr_cine.genero[0]);
	printf("\nTerror: %d", vr_cine.genero[1]);
	printf("\nRomantica: %d", vr_cine.genero[2]);
	printf("\nInfantil: %d", vr_cine.genero[3]);
	printf("\nJuvenil: %d", vr_cine.genero[4]);
	printf("\nDrama: %d", vr_cine.genero[5]);
	printf("\nAventuras: %d", vr_cine.genero[6]);*/
	
	printf("\n\nSuspenso: %d", vGeneroCantidad[0]);
	printf("\nTerror: %d", vGeneroCantidad[1]);
	printf("\nRomantica: %d", vGeneroCantidad[2]);
	printf("\nInfantil: %d", vGeneroCantidad[3]);
	printf("\nJuvenil: %d", vGeneroCantidad[4]);
	printf("\nDrama: %d", vGeneroCantidad[5]);
	printf("\nAventuras: %d", vGeneroCantidad[6]);
	
	int i=0;
	int cantidad = vGeneroCantidad[0];
	int posicion = 1;
	
	for(i=0;i<7;i++){
		if(vGeneroCantidad[i] < cantidad){
			cantidad = vGeneroCantidad[i];
			posicion = i+1;
		}
	}
	
	switch(posicion){
		case 1: printf("\n\nSuspenso ");
		break;
		case 2: printf("\n\nTerror ");
		break;
		case 3: printf("\n\nRomantica ");
		break;
		case 4: printf("\n\nInfantil ");
		break;
		case 5: printf("\n\nJuvenil ");
		break;
		case 6: printf("\n\nDrama ");
		break;
		case 7: printf("\n\nAventuras ");
		break;
	}
	
	printf("es el genero con menor cantidad de entradas vendidas: %d", cantidad);
}

void obtenerPeliculas(){
	fread(&vr_cine, sizeof(tr_cinemacenter), 1, vf_cines);
}

void finalizarProceso(){
	fclose(vf_cines);
}
