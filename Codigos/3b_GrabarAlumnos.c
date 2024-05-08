#include <stdio.h>
#include <string.h>

typedef char string[50];

typedef struct
{
	int dni;
	string nombre;
} tDatosAlumno;

void inicializar(char[1]);
void grabarAlumnos();
void finalizar();

FILE *archivoTexto;
int contAlumnos;

int main()
{
	inicializar("w");
	grabarAlumnos();
	finalizar();
	return 0;
}

void inicializar(char modoApertura[1])
{
	contAlumnos = 0;

	/* abrir archivo segun el modo que se recibe como par�metro */
	archivoTexto = fopen("Alumnos.txt", modoApertura);
}

void grabarAlumnos()
{
	tDatosAlumno alumno;
	char opcion = 's';

	while (opcion == 's')
	{
		contAlumnos++;

		printf("Ingresar DNI: ");
		scanf("%d", &alumno.dni);

		printf("Ingresar nombre: ");
		fflush(stdin);
		gets(alumno.nombre);

		/* insertar, escribir � grabar una l�nea con formato */
		fprintf(archivoTexto, "%d %s\n", alumno.dni, alumno.nombre);

		printf("Ingresar otro? s-n: ");
		fflush(stdin);
		scanf("%c", &opcion);

		opcion = tolower(opcion);
	}
}

void finalizar()
{
	/* Cerrar el archivo */
	fclose(archivoTexto);

	/* Mostrar la cantidad de registros grabados */
	printf("\nCantidad de registros grabados: %d\n", contAlumnos);
}
