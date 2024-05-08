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
- el total de inscriptos para cada categor�a (utilizar arreglos)
	* declarar un vector con 3 elementos de tipo int (1 para cada categor�a)
	* inicializar en 0 cada posici�n del vector ya que son contadores
	* incrementar cada vez que se lee un registro
	* mostrar los valores del vector al final de la iteraci�n
	* mostrar la descripci�n de las categor�as junto a los valores (crear otro vector o usar switch/if)
- el porcentaje que representan los estudiantes respecto del total de participantes.
	* realizar el c�lculo al final de la iteraci�n (una vez finalizada la recorrida de todos los registros del archivo)
	* mostrar el porcentaje
- un reporte de los inscriptos al congreso indicando apellido (en may�sculas) y nombre,
	seguido de la categor�a, con el siguiente formato:

	LISTADO DE INSCRIPTOS AL CONGRESO
	PEREZ, Juan - Docente universitario
	.....
	GOMEZ, Mar�a � Estudiante
	* para mostrar la descripci�n de la categor�a pueden usar switch/ if/ o un vector con las descripciones.
	* mostrar los datos solicitados cada vez que se lee un registro
	* para convertir el apellido a may�scular utilizar funci�n TOUPPER

*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define TITULO "LISTADO DE INSCRIPTOS AL CONGRESO"
#define TITULO2 "TOTAL DE INSCRIPTOS POR CATEGORIA"
#define LINEA "-----------------------------------------------------"
#define MAX 3

/* Declaraci�n de tipos de datos personalizados */
typedef char tString15[15];
typedef char tString50[50];

typedef struct
{
	int nroInscripcion;
	tString15 apellido;
	tString15 nombre;
	int codCateg;
	float importeInscripcion;
} tRegInscriptos;

typedef int tVectorInt[MAX];

/* Declaraci�n de prototipos */
void iniciarProceso();
void procesarInscriptos();
void finalizarProceso();

void mostrarUnInscripto();
void contarTotalCategoria();	/* generar vector */
void mostrarTotalCategoria(); /* mostrar vector */
float calcularPorcentajeEstudiantes();
void convertirApellidoMay();

/* Declaraci�n de variables globales */
tRegInscriptos regInscripto; /* registro */
FILE *archInscriptos;				 /* archivo */

/* vector para contar inscriptos por categoria */
tVectorInt inscriptosXCateg = {0, 0, 0};

/* Funci�n principal */
int main()
{
	iniciarProceso();
	procesarInscriptos();
	finalizarProceso();
	return 0;
}

/* Implementaci�n de funciones */

void iniciarProceso()
{
	/* Abrir el archivo en modo escritura */
	archInscriptos = fopen("Inscriptos.dat", "rb"); /* Se abre el archivo en "modo Lectura" */
}

void procesarInscriptos()
{

	printf("%s\n", TITULO);
	printf("%s\n", LINEA);

	fread(&regInscripto, sizeof(tRegInscriptos), 1, archInscriptos);
	while (!feof(archInscriptos) == true)
	{ /* Mientras no es el fin del archivo */

		mostrarUnInscripto();
		contarTotalCategoria();

		fread(&regInscripto, sizeof(tRegInscriptos), 1, archInscriptos);
	}
}

void mostrarUnInscripto()
{
	convertirApellidoMay();
	printf("%s, %s - ", regInscripto.apellido, regInscripto.nombre);
	switch (regInscripto.codCateg)
	{
	case 1:
		printf("Docente universitario\n");
		break;
	case 2:
		printf("Docente secundario\n");
		break;
	case 3:
		printf("Estudiante\n");
		break;
	}
}

void convertirApellidoMay()
{
	int i;
	int l;
	l = strlen(regInscripto.apellido);
	for (i = 0; i < l; i++)
	{
		regInscripto.apellido[i] = toupper(regInscripto.apellido[i]);
	}
}

void contarTotalCategoria()
{
	inscriptosXCateg[regInscripto.codCateg - 1] = inscriptosXCateg[regInscripto.codCateg - 1] + 1;
}

void finalizarProceso()
{
	fclose(archInscriptos);

	mostrarTotalCategoria();

	printf("%s\n", LINEA);
	printf("\nPorcentaje que representan los Estudiantes respecto del total de participantes: %.2f %%", calcularPorcentajeEstudiantes());
}

void mostrarTotalCategoria()
{
	int i;
	/* Mostrar por pantalla el vector generado. */
	printf("\n\t%s\n", TITULO2);
	printf("%s\n", LINEA);

	/* mostrar categorias */
	for (i = 0; i < MAX; i++)
	{
		printf("Categoria %d - ", i + 1);
		switch (i)
		{
		case 0:
			printf("Docente universitario: ");
			break;
		case 1:
			printf("Docente secundario: ");
			break;
		case 2:
			printf("Estudiante: ");
			break;
		}

		printf("%d \n", inscriptosXCateg[i]);
	}
}

float calcularPorcentajeEstudiantes()
{
	return (float)inscriptosXCateg[2] * 100 / (inscriptosXCateg[0] + inscriptosXCateg[1] + inscriptosXCateg[2]);
}
