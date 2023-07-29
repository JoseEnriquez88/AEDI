#include <stdio.h>
#include <string.h>

typedef char string[50];

typedef struct {
	int dni;
	string nombre;
} tDatosAlumno;

void inicializar(char[1]);
void mostrarDatosGrabados();
void finalizar();

FILE * archivoTexto;

int main() {	
	inicializar("r");
	mostrarDatosGrabados();
	finalizar();
		
	return 0;
}

void inicializar(char modoApertura[1]) {
	/* Abrir el archivo según el modo de apertura que se recibe como parámetro */
	archivoTexto = fopen("Alumnos.txt", modoApertura);
}

void mostrarDatosGrabados() {
	tDatosAlumno alumno;
	
	printf("\n*** Alumnos grabados *** \n");	
	
	/* Leer u obtener una lína de texto según el formato especificado */
	fscanf(archivoTexto, "%d %[^\n]s\n", &alumno.dni, &alumno.nombre);
	while ( ! feof(archivoTexto) ) {  /* Recorrer el archivo mientras no se haya llegado al final */
		printf("%d %s\n", alumno.dni, alumno.nombre);
		fscanf(archivoTexto, "%d %[^\n]s\n", &alumno.dni, &alumno.nombre);	
	}	
}

void finalizar() {
	/* Cerrar el archivo */
	fclose(archivoTexto);
}
