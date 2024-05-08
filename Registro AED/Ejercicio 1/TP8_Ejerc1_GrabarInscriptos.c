/*
FaCENA organiza las Jornadas Argentinas de Did�ctica de la Programaci�n (JADiPro) y necesita
conocer la composici�n y cantidad de inscriptos al evento para ajustar los detalles organizativos.
Se tiene un archivo con los datos de los participantes con el siguiente formato de registro:

Nro. Inscripci�n (int)
Apellido (char [15])
Nombre (char [15])
Categor�a (int)
Importe de inscripci�n (float)

Categor�as: 1-Docente universitario, 2-Docente secundario, 3-Estudiante

Los organizadores desean conocer:
- el total de inscriptos para cada categor�a (utilizar arreglos),
- el porcentaje que representan los estudiantes respecto del total de participantes.
- un reporte de los inscriptos al congreso indicando apellido (en may�sculas) y nombre,
	seguido de la categor�a, con el siguiente formato:

	LISTADO DE INSCRIPTOS AL CONGRESO
	PEREZ, Juan - Docente universitario
	.....
	GOMEZ, Mar�a � Estudiante

*/

#include <stdio.h>
#include <string.h>

/* Declaraci�n de tipos de datos personalizados */
typedef char tString[15];

typedef struct
{
	int nroInscripcion;
	tString apellido;
	tString nombre;
	int codCateg;
	float importeInscripcion;
} tRegInscriptos;

/* Declaraci�n de prototipos */
void iniciarProceso();
void grabarDatos();
void finalizarProceso();

void ingresarDatos();

/* Declaraci�n de variables globales */
tRegInscriptos regInscripto; // registro
FILE *archInscriptos;				 // archivo

/* Funci�n principal */
int main()
{

	iniciarProceso();
	grabarDatos();
	finalizarProceso();

	return 0;
}

/* Implementaci�n de funciones */

void iniciarProceso()
{
	/* Abrir el archivo en modo escritura */
	archInscriptos = fopen("Inscriptos.dat", "wb");
}

void grabarDatos()
{
	char opcion = 's';
	while (opcion == 's')
	{
		ingresarDatos();

		/* grabar registro en el archivo */
		fwrite(&regInscripto, sizeof(tRegInscriptos), 1, archInscriptos);

		printf("Ingresar otro ? s-n: ");
		fflush(stdin);
		scanf("%c", &opcion);
	}
}

void ingresarDatos()
{
	printf("\n*** Ingreso de datos *** \n");

	printf("Nro Inscripcion: ");
	scanf("%d", &regInscripto.nroInscripcion);

	printf("Apellidos: ");
	fflush(stdin);
	gets(regInscripto.apellido);

	printf("Nombres: ");
	fflush(stdin);
	gets(regInscripto.nombre);

	printf("Cod. Categoria (1-Docente universitario, 2-Docente secundario, 3-Estudiante): ");
	scanf("%d", &regInscripto.codCateg);

	printf("Importe de Inscripcion: ");
	scanf("%f", &regInscripto.importeInscripcion);
}

void finalizarProceso()
{
	fclose(archInscriptos);
}
