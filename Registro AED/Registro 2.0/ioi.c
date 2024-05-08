/*FaCENA organiza las Jornadas Argentinas de Did�ctica de la Programaci�n (JADiPro)
y necesita conocer la composici�n y cantidad de inscriptos al evento para ajustar
los detalles organizativos. Se tiene un archivo con los datos de los participantes
con el siguiente formato de registro:

	Nro. Inscripcion    Apellido  		Nombre  	 Categor�a  Importe de inscripci�n
			(int)		(char [15])		(char [15])		(int)		 (float)


Categor�as: 1-Docente universitario, 2-Docente secundario, 3-Estudiante

Los organizadores desean conocer el total de inscriptos para cada categor�a (*),
	-un arreglo para recorrer el total de inscriptos

y el porcentaje que representan los estudiantes respecto del total de participantes.
	un contador para participantes
	un contador para estudiantes
	una variable para porcentaje de estudiantes

A efectos de llevar un control, necesitan un reporte de los inscriptos al congreso
indicando apellido (en may�sculas) y nombre, seguido de la categor�a, con el siguiente formato:

LISTADO DE INSCRIPTOS AL CONGRESO
PEREZ, Juan - Docente universitario
�..
GOMEZ, Mar�a � Estudiante

(*) se solicita utilizar arreglos para resolver este requerimiento.

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void iniciarProceso();
void procesarInscriptos();
void finalizarProceso();

void obtenerTotalInscriptos();
void obtenerInscriptos();
void convertirApellidoMayusYConcatenar();
void procesarDatosInscriptos();

typedef char tString[15];

typedef struct
{
	int nroInscripcion;
	tString apellido;
	tString nombre;
	int codCateg;
	float importeInscripcion;
} tRegInscriptos;

tRegInscriptos regInscripto;
FILE *archInscriptos;

int vInscriptos[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

int docUniversitario, docSecundario, estudiante;
float porcEstudiantes;

int main()
{
	iniciarProceso();
	procesarInscriptos();
	finalizarProceso();

	return 0;
}

void iniciarProceso()
{
	docUniversitario = 0;
	docSecundario = 0;
	estudiante = 0;
	porcEstudiantes = 0;

	rchInscriptos = fopen("Inscriptos.dat", "rb");
	printf("\t\t\t**REPORTE DE INSCRIPTOS A LA JORNADA DE PROGRAMACION**\n\n");
}

void procesarInscriptos()
{
	obtenerInscriptos();
	while (!feof(archInscriptos))
	{
		procesarDatosInscriptos();
		obtenerInscriptos();
	}
}

void obtenerInscriptos()
{
	fread(&regInscripto, sizeof(tRegInscriptos), 1, archInscriptos);
}

void procesarDatosInscriptos()
{
	obtenerTotalInscriptos();
}

void obtenerTotalInscriptos()
{
	int i = 0;
	int cantInscriptos = vInscriptos[0];
	int totalInscriptos = i + 1;

	for (i = 0; i < 9; i++)
	{
		if (vInscriptos[i] > cantInscriptos)
		{
		}
	}
	if (vUsuarioPorPais[i] > cantUsuarios)
	{
		cantUsuarios = vUsuarioPorPais[i];
		paisConMasUsuario = i + 1;
	}

	void convertirApellidoMayusYConcatenar()
	{
	}

	void finalizarProceso()
	{
		fclose(archInscriptos);
	}
