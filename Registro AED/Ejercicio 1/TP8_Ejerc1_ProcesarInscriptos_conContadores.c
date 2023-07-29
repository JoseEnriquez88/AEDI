/*
FaCENA organiza las Jornadas Argentinas de Didáctica de la Programación (JADiPro) y necesita
conocer la composición y cantidad de inscriptos al evento para ajustar los detalles organizativos.
Se tiene un archivo con los datos de los participantes con el siguiente formato de registro:

Nro. Inscripción (int)
Apellido (char [15])
Nombre (char [15])
Categoría (int)
Importe de inscripción (float)

Categorías: 1-Docente universitario, 2-Docente secundario, 3-Estudiante

Los organizadores desean conocer: 
- el total de inscriptos para cada categoría (utilizar arreglos)
	* declarar un vector con 3 elementos de tipo int (1 para cada categoría)
	* inicializar en 0 cada posición del vector ya que son contadores
	* incrementar cada vez que se lee un registro
	* mostrar los valores del vector al final de la iteración
	* mostrar la descripción de las categorías junto a los valores (crear otro vector o usar switch/if)
- el porcentaje que representan los estudiantes respecto del total de participantes.
	* realizar el cálculo al final de la iteración (una vez finalizada la recorrida de todos los registros del archivo)
	* mostrar el porcentaje 
- un reporte de los inscriptos al congreso indicando apellido (en mayúsculas) y nombre, 
	seguido de la categoría, con el siguiente formato:

	LISTADO DE INSCRIPTOS AL CONGRESO
	PEREZ, Juan - Docente universitario
	.....
	GOMEZ, María – Estudiante
	* para mostrar la descripción de la categoría pueden usar switch/ if/ o un vector con las descripciones. 
	* mostrar los datos solicitados cada vez que se lee un registro
	* para convertir el apellido a mayúscular utilizar función TOUPPER

*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define TITULO "LISTADO DE INSCRIPTOS AL CONGRESO"
#define TITULO2 "TOTAL DE INSCRIPTOS POR CATEGORIA"
#define LINEA "-----------------------------------------------------"
#define MAX 3

/* Declaración de tipos de datos personalizados */
typedef char tString15[15];
typedef char tString50[50];

typedef struct {
	int nroInscripcion;
	tString15 apellido;
	tString15 nombre;
	int codCateg;
	float importeInscripcion;
} tRegInscriptos;

typedef int tVectorInt[MAX];
typedef tString50 tVectorString[MAX];


/* Declaración de prototipos */
void iniciarProceso();
void procesarInscriptos();
void finalizarProceso();
	
void mostrarUnInscripto();
void contarTotalCategoria(); /* generar vector */
void mostrarTotalCategoria(); /* mostrar vector */
float calcularPorcentajeEstudiantes();
void convertirApellidoMay();

/* Declaración de variables globales */
tRegInscriptos regInscripto; /* registro */
FILE * archInscriptos; /* archivo */

/* vector para contar inscriptos por categoria */
tVectorInt inscriptosXCateg = { 0, 0, 0 }; 

/* descripcion de las categorias */
tVectorString categoriasDesc = { "Docente universitario", "Docente secundario", "Estudiante" }; 

/* Contadores para porcentaje (alternativa)*/ 
int cantidadTotalInscriptos, cantidadTotalEstudiantes;

/* Función principal */
int main() {
	iniciarProceso();
	procesarInscriptos();
	finalizarProceso();
	return 0;
}

/* Implementación de funciones */

void iniciarProceso() {
	/* Abrir el archivo en modo escritura */
	archInscriptos = fopen("Inscriptos.dat", "rb"); /* Se abre el archivo en "modo Lectura" */
}

void procesarInscriptos() {
	
	printf("%s\n", TITULO);
	printf("%s\n", LINEA);
	
	fread( &regInscripto, sizeof(tRegInscriptos), 1, archInscriptos );
	while ( !feof(archInscriptos) == true ) { /* Mientras no es el fin del archivo */
						
		mostrarUnInscripto();
		contarTotalCategoria();
		contarTotales();
		
		fread( &regInscripto, sizeof(tRegInscriptos), 1, archInscriptos );
	}
}

void mostrarUnInscripto() {
	convertirApellidoMay();
	printf("%s, %s - %s \n", regInscripto.apellido, regInscripto.nombre, categoriasDesc [regInscripto.codCateg - 1] ); 
}

void convertirApellidoMay(){
	int i; 
	int l;
	l = strlen(regInscripto.apellido);
	for (i=0; i<l; i++){
		regInscripto.apellido[i] = toupper (regInscripto.apellido [i]);
	}
}
void contarTotalCategoria() {
	inscriptosXCateg [regInscripto.codCateg -1] = inscriptosXCateg [regInscripto.codCateg -1] + 1;
}

void contarTotales(){
	cantidadTotalInscriptos ++;
	if (regInscripto.codCateg == 3) {
		cantidadTotalEstudiantes ++;
	}
}

void finalizarProceso() {
	fclose(archInscriptos);
	
	mostrarTotalCategoria();
	
	printf("%s\n", LINEA);
	printf("\nPorcentaje que representan los Estudiantes respecto del total de participantes: %.2f %%", calcularPorcentajeEstudiantes());
}

void mostrarTotalCategoria() {
	int i;
	/* Mostrar por pantalla el vector generado. */	
	printf("\n\t%s\n", TITULO2);
	printf("%s\n", LINEA);
	
	/* mostrar categorias */
	for( i=0; i<MAX; i++ ) {
		printf("%s: ", categoriasDesc[i] ); 
		printf("%d \n", inscriptosXCateg[i] );
	}
}

float calcularPorcentajeEstudiantes() {
	return (float) cantidadTotalEstudiantes * 100 / cantidadTotalInscriptos;
}








