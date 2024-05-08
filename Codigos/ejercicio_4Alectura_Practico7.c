/*
a) Dado un archivo de alumnos de FACENA cuyo dise�o de registro es el del ejercicio 2.a, se desea obtener un listado
de los inscriptos a la LSI, informar cu�ntos alumnos son y qu� porcentaje representan sobre el total de alumnos inscriptos
de toda la Facultad.
*Nota: Tener en cuenta que se deber�n grabar los datos antes de poder procesarlos, para lo que ser� necesario pensar un
lote de datos de prueba representativo.

Objetivo: obtener un listado de los inscriptos a la LSI, informar cu�ntos alumnos son y qu� porcentaje
representan sobre el total de alumnos inscriptos de toda la Facultad.

Estretagia:

-Iniciar la lectura del archivo binario con el modo rb.
-Procesar los alumnos.
-Mostrar los resultados obtenidos.


*/

#include <stdio.h>
#include <locale.h>

void iniciarProceso();
void procesarAlumnos();
void finalizarProceso();
void obtenerAlumno();
void procesarAlumno();
void ingresarRespuesta();

typedef struct
{ /* Declaraci�n de un tipo de dato registro */
	int dni;
	int codCarrera;
	char genero;
	int edad;
} tr_alumno;

tr_alumno vr_alumno;
FILE *vf_alumnos; /* Declaraci�n del archivo */
char respuesta;
int cantAlumnosRegistrados;
int edadMujerMenor, dniMujerMenor, contMujeres, contMujeresElectronica, cantAlumnosLSI;

int main()
{
	setlocale(LC_ALL, "spanish");
	iniciarProceso();
	procesarAlumnos();
	finalizarProceso();
	return 0;
}

void iniciarProceso()
{
	contMujeresElectronica = 0;
	cantAlumnosRegistrados = 0;
	contMujeres = 0;
	edadMujerMenor = 150; /*metodo del supuesto, suponemos que 150 es la edad del menor*/
	vf_alumnos = fopen("alumnos.dat", "rb");
	/* Imprimir titulos si corresponde */
	printf("INFORMACION DE ALUMNOS DE FACENA:\n");

	printf("\nC�digos de carrera: ");
	printf("\n18- Lic. en Sistemas de Informaci�n (LSI) ");
	printf("\n19- Lic. en Cs. Biol�gicas ");
	printf("\n20- Agrimensura ");
	printf("\n28- Bioqu�mica ");
	printf("\n29- Ing. Electronica ");

	printf("\n\nC�digos de genero: ");
	printf("\nm- mujer");
	printf("\nv- varon");
	printf("\nx- otro");

	printf("\n\nDNI\t\t|\tC�digo de carrera\t|\tGenero\t|\tEdad\t\n");
	printf("-----------------------------------------------------------------------------------\n");
}

void procesarAlumnos()
{
	obtenerAlumno();
	while (!feof(vf_alumnos))
	{
		procesarAlumno();
		obtenerAlumno();
	}
}

void procesarAlumno()
{
	printf("%d\t|\t\t%d\t\t|\t%c\t|\t%d\n", vr_alumno.dni, vr_alumno.codCarrera, vr_alumno.genero, vr_alumno.edad);
	if (vr_alumno.codCarrera == 18)
	{
		cantAlumnosLSI = cantAlumnosLSI + 1;
	}

	if (vr_alumno.genero == 'm')
	{ /*pregunta si son mujeres*/
		contMujeres++;
		if (vr_alumno.edad < 25 && vr_alumno.codCarrera == 29)
		{ /*si son mujeres menores a 25 y de la carrera Ing Electr�nica*/
			contMujeresElectronica++;
		}
		if (vr_alumno.edad < edadMujerMenor)
		{ /*busca la menor edad de las mujeres*/
			edadMujerMenor = vr_alumno.edad;
			dniMujerMenor = vr_alumno.dni;
		}
	}

	cantAlumnosRegistrados = cantAlumnosRegistrados + 1;
}

void obtenerAlumno()
{
	fread(&vr_alumno, sizeof(tr_alumno), 1, vf_alumnos);
}

void finalizarProceso()
{
	/* Se muestran los resultados */
	float porcentajeLSI = (float)cantAlumnosLSI * 100 / cantAlumnosRegistrados; /*realizar en un procedimiento separado*/
	printf("\n\nLa cantidad de alumnos de FACENA es: %d", cantAlumnosRegistrados);
	printf("\nLa cantidad de alumnos de LSI: %d", cantAlumnosLSI);
	printf("\nEl porcentaje de alumnos de LSI es: %.2f%%", porcentajeLSI);
	printf("\nEl porcentaje de mujeres menores a 25 de la carrera Ing Electr�nica es: %.2f%%", (float)contMujeresElectronica * 100 / contMujeres);
	printf("\nLa cantidad de mujeres en la Carrera Ing en Electr�nica: %d", contMujeresElectronica);
	printf("\nLa mujer con menor edad es: %d, su edad es %d", dniMujerMenor, edadMujerMenor);
	fclose(vf_alumnos); /* Se cierra el archivo */
}
