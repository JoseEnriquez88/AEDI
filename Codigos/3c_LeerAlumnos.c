#include <stdio.h>
#include <string.h>

typedef char string[50];

typedef struct
{
	int dni;
	string nombre;
} tDatosAlumno;

void inicializar(char[1]);
void mostrarDatosGrabados();
void finalizar();

FILE *archivoTexto;

int main()
{
	inicializar("r");
	mostrarDatosGrabados();
	finalizar();

	return 0;
}

void inicializar(char modoApertura[1])
{
	archivoTexto = fopen("Alumnos.txt", modoApertura);
}

void mostrarDatosGrabados()
{
	tDatosAlumno alumno;

	printf("\n*** Alumnos grabados *** \n");

	fscanf(archivoTexto, "%d %[^\n]s\n", &alumno.dni, &alumno.nombre);
	while (!feof(archivoTexto))
	{
		printf("%d %s\n", alumno.dni, alumno.nombre);
		fscanf(archivoTexto, "%d %[^\n]s\n", &alumno.dni, &alumno.nombre);
	}
}

void finalizar()
{
	fclose(archivoTexto);
}
