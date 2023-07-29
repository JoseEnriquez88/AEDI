/*
a) Dado un archivo de alumnos de FACENA cuyo diseño de registro es el del ejercicio 2.a, se desea obtener un listado
de los inscriptos a la LSI, informar cuántos alumnos son y qué porcentaje representan sobre el total de alumnos inscriptos
de toda la Facultad.
*Nota: Tener en cuenta que se deberán grabar los datos antes de poder procesarlos, para lo que será necesario pensar un
lote de datos de prueba representativo.

Objetivo: obtener un listado de los inscriptos a la LSI, informar cuántos alumnos son y qué porcentaje
representan sobre el total de alumnos inscriptos de toda la Facultad.

Estretagia: 
-Crear el archivo binario.
-Mientras que haya alumnos ingresar los datos y grabar el registro del alumno.


*/

#include <stdio.h>
#include <locale.h>

void iniciarProceso();
void guardarTodosAlumnos();
void ingresarDatosAlumno();
void guardarRegistroAlumno();
void ingresarRespuesta();
void finalizarProceso();


typedef struct { /* Declaración de un tipo de dato registro */
	int dni;
	int codCarrera;
	char genero;
	int edad;
} tr_alumno;

tr_alumno vr_alumno;
FILE * vf_alumnos; /*se crea el puntero*/
char respuesta;

int main()	{
	setlocale(LC_ALL, "spanish");/*permite mostrar por pantalla los caracteres en castellano */
	iniciarProceso();
	guardarTodosAlumnos();
	finalizarProceso();
	return 0;
}

void iniciarProceso() {
	/* Se abre un archivo nuevo y se asigna a la variable archivo */
	vf_alumnos = fopen("Alumnos.dat", "ab");
	printf( "Archivo de alumnos creado! \n" );
}

void guardarTodosAlumnos() {
	ingresarRespuesta();
	while( respuesta != 'n' /*&& respuesta != 'N' */){/*se cambio con cambiar con tolower*/
		ingresarDatosAlumno();
		guardarRegistroAlumno();
		ingresarRespuesta();
	}
}
void ingresarDatosAlumno() {
	printf( "\nIngrese el DNI del alumno: " );
	scanf( "%d", &vr_alumno.dni );
	
	printf( "\nCodigos de carrera: " );
	printf( "\n18- Lic. en Sistemas de Informacion (LSI) " );
	printf( "\n19- Lic. en Cs. Biologicas " );
	printf( "\n20- Agrimensura " );
	printf( "\n28- Bioquimica " );
	printf( "\n29- Ing. Electronica " );
	printf( "\n\nIngrese el codigo de carrera: " );
	scanf( "%d", &vr_alumno.codCarrera );
	
	printf( "\nCodigos de genero: " );
	printf( "\nm- mujer" );
	printf( "\nv- varon" );
	printf( "\nx- otro" );
	printf( "\n\nIngrese el genero: ");
	fflush(stdin);
	scanf( "%c", &vr_alumno.genero );
	
	printf( "\nIngrese la edad: " );
	scanf( "%d", &vr_alumno.edad );
	fflush(stdin);
}

void guardarRegistroAlumno() {
	/* Se graba 1 registro en el archivo de Alumnos */
	fwrite( &vr_alumno, sizeof( tr_alumno ), 1, vf_alumnos );
	printf( "\nRegistro de notas de alumno insertado! \n" );
}
void ingresarRespuesta() {
	printf( "\nDesea ingresar alumnos? s/n: " );
	fflush(stdin);
	scanf( "%c", &respuesta );
	respuesta = tolower(respuesta);
}
void finalizarProceso() {
	fclose( vf_alumnos ); /* Se cierra el archivo */
}
