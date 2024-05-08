#include <stdio.h>
#include <string.h>
#include <ctype.h>

void iniciarProceso();
void procesarPeliculas();
void finalizarProceso();

void procesarDatosPeliculas();
void obtenerArchivo();
void obtenerPeliculasAventura();
void contCantidadPeliculas();

typedef struct
{
	int codPelicula;
	char nombrePelicula[30];
	int genero;
	int cantEntradasVendidas;
	int duracionPelicula;
} tr_peliculas;

tr_peliculas vr_peliculas;
FILE *vf_peliculas;

int vPelicula[7] = {0, 0, 0, 0, 0, 0, 0}; // declaracion del vector para recorrer la cantidad de generos de peliculas
int aventura;															// declaracion acumulador de aventuras

int main()
{
	iniciarProceso();
	procesarPeliculas();
	finalizarProceso();

	return 0;
}

void iniciarProceso()
{
	aventura = 0;

	vf_peliculas = fopen("Cinemacenter.dat", "rb");
	printf("\t\t\t***REGISTRO DE PELICULAS**\n\n");
}

void procesarPeliculas()
{
	obtenerArchivo();
	while (!feof(vf_peliculas))
	{
		procesarDatosPeliculas();
		obtenerArchivo();
	}
}

void obtenerArchivo()
{
	fread(&vr_peliculas, sizeof(tr_peliculas), 1, vf_peliculas);
}

void procesarDatosPeliculas()
{
	obtenerPeliculasAventura();
	contCantidadPeliculas();
}

void obtenerPeliculasAventura()
{
	if ((vr_peliculas.genero == 7) && (vr_peliculas.cantEntradasVendidas > 1000))
	{
		aventura++;
		printf("\nNombre pelicula\t|Duracion en minutos\t|Cantidad entradas vendidas");
		printf("\n %s \t| %d \t\t| %d", vr_peliculas.nombrePelicula, vr_peliculas.duracionPelicula, vr_peliculas.cantEntradasVendidas);
	}
}

void contCantidadPeliculas()
{
	vPelicula[vr_peliculas.codPelicula - 1]++;
}

void finalizarProceso()
{
	printf("\n\n\t\t\t***CANTIDAD ENTRADAS VENDIDAS POR GENERO**\n\n");
	printf("\nSuspenso: %d", vPelicula[0]);
	printf("\nTerror: %d", vPelicula[1]);
	printf("\nRomantica: %d", vPelicula[2]);
	printf("\nInfantil: %d", vPelicula[3]);
	printf("\nJuvenil: %d", vPelicula[4]);
	printf("\nDrama: %d", vPelicula[5]);
	printf("\nAventuras: %d\n\n", vPelicula[6]);

	int i = 0;
	int cantPeliculas = vPelicula[0];
	int cantUsuariosPeliculas = 1;

	for (i = 0; i < 7; i++)
	{
		if (vPelicula[i] < cantPeliculas)
		{
			cantPeliculas = vPelicula[i];
			cantUsuariosPeliculas = i + 1;
		}
	}

	switch (cantUsuariosPeliculas)
	{
	case 1:
		printf("\nSuspenso es el genero con menor cantidad de entradas vendidas: %d", cantPeliculas);
		break;
	case 2:
		printf("\nTerror es el genero con menor cantidad de entradas vendidas: %d", cantPeliculas);
		break;
	case 3:
		printf("\nRomantica es el genero con menor cantidad de entradas vendidas: %d", cantPeliculas);
		break;
	case 4:
		printf("\nInfantil es el genero con menor cantidad de entradas vendidas: %d", cantPeliculas);
		break;
	case 5:
		printf("\nJuvenil es el genero con menor cantidad de entradas vendidas %d", cantPeliculas);
		break;
	case 6:
		printf("\nDrama es el genero con menor cantidad de entradas vendidas: %d", cantPeliculas);
		break;
	case 7:
		printf("\nAventuras es el genero con menor cantidad de entradas vendidas: %d", cantPeliculas);
		break;
	}

	fclose(vf_peliculas);
}
