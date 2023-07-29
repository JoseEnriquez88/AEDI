#include<stdio.h>
#include<string.h>
#include<ctype.h>

void iniciarProceso();
void grabarArchivo();
void ingresarRespuesta();
void ingresarDatosUsuarios();
void grabarRegistroUsuarios();
void finalizarProceso();

char respuesta;

typedef struct{
	int nroUsuario;
	char nombre[60];
	int codPais;
	int codPlan;
	int conDiaria;
} tr_usuarios;

tr_usuarios vr_usuarios;
FILE * vf_usuarios;

int main(){
	iniciarProceso();
	grabarArchivo();
	finalizarProceso();
	
	return 0;
}

void iniciarProceso(){
	vf_usuarios = fopen("Netflix.dat", "wb");
	printf("\t\t***ARCHIVO DE USUARIOS DE NETFLIX CREADO***\n\n");
}

void grabarArchivo(){
	ingresarRespuesta();
	while(respuesta != 'n'){
		ingresarDatosUsuarios();
		grabarRegistroUsuarios();
		ingresarRespuesta();
	}
}

void ingresarRespuesta(){
	printf("\nDesea agregar datos al archivo de usuarios? s/n: ");
	fflush(stdin);
	scanf("%c", &respuesta);
	respuesta = tolower(respuesta);
}

void ingresarDatosUsuarios(){
	printf("Digite su numero de usuario: ");
	scanf("%d", &vr_usuarios.nroUsuario);
	printf("Digite su apellido y nombre: ");
	fflush(stdin);
	scanf("%[^\n]s", &vr_usuarios.nombre);
	printf("Digite su codigo de pais:\n");
	printf("1-Argentina, 2- Brasil, 3-Uruguay, 4-Paraguay, 5-Peru, 6-Bolivia, 7-Venezuela: ");
	scanf("%d", &vr_usuarios.codPais);
	printf("Digite su codigo de plan (1-Basico, 2-Standard, 3-Premium): ");
	scanf("%d", &vr_usuarios.codPlan);
	printf("Digite las veces que se conecta en el dia: ");
	scanf("%d", &vr_usuarios.conDiaria);
}

void grabarRegistroUsuarios(){
	fwrite(&vr_usuarios, sizeof(tr_usuarios), 1, vf_usuarios);
	printf("\n\t**REGISDTRO DE USUARIOS AGREGADO**\n\n");
}

void finalizarProceso(){
	fclose(vf_usuarios);
}

