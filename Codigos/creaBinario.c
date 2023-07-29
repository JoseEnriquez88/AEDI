/*Crea un archivo binario*/
#include <stdio.h>
/*PROTOTIPADO*/ 
void iniciarProceso();
void grabarArchivoAlumnos();
void finalizarProceso();
void ingresarDatosAlumno();
void grabarRegistroAlumno();
void ingresarRespuesta();

/* Declaración de un tipo de dato registro */
typedef struct { 
	int dni;
	float nota1;
	float nota2;
} tr_alumno;

tr_alumno vr_alumno; /*Declaración del registro vr_alumno tipo tr_alumno*/
FILE * vf_alumnos; /* Declaración del archivo, puntero a la zona de memoria donde se va a iniciar la transferencia*/

/*declaración de variables*/
char respuesta;

/*función principal*/
int main(){
	iniciarProceso();
	grabarArchivoAlumnos();
	finalizarProceso();
	return 0;
}

/*declaración de funciones*/

void iniciarProceso() {
	/* Se abre un archivo nuevo y se asigna a la variable archivo */
	vf_alumnos = fopen("Alumnos.dat", "ab"); /*wb modo apertura archivo que indica write binary*/
	printf( "\tArchivo de alumnos creado! \n" );
}

void grabarArchivoAlumnos() {
	ingresarRespuesta();
	while( respuesta != 'n' && respuesta != 'N' ){ /*proceso donde se ingresan los datos y se van grabando fisicamente*/ 
		ingresarDatosAlumno();
		grabarRegistroAlumno();
		ingresarRespuesta();
	}
}

void ingresarRespuesta() {
	printf( "\nDesea ingresar datos al archivo? s/n: " );
	fflush( stdin );
	scanf( "%c", &respuesta );
}

void ingresarDatosAlumno() {/*ingreso de datos por teclado*/
	printf( "\nIngrese: \n" );
	printf( "\tDNI del alumno: " );
	scanf( "%d", &vr_alumno.dni );/*se guarda en memoria ram en el espacio reservado para ese campo vr_alumno hace referencia al registro. dni hace referencia al campo*/
	printf( "\tNota 1er Parcial: " );
	scanf( "%f", &vr_alumno.nota1 );
	printf( "\tNota 2do Parcial: " );
	scanf( "%f", &vr_alumno.nota2 );
}

void grabarRegistroAlumno() {
/* Se graba fisicamente 1 registro en el archivo de Alumnos */
	fwrite( &vr_alumno, sizeof( tr_alumno ), 1, vf_alumnos );
	printf( "\tRegistro de notas de alumno insertado! \n" );
}


void finalizarProceso() {
	fclose( vf_alumnos ); /* Se cierra el archivo */
}
