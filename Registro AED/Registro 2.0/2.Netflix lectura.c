/*
-Detectar cuál es el país con mayor cantidad de usuarios, mostrar por pantalla la cantidad y el
nombre del país al cual pertenece.
	cantUsuariosPais; 
	if()
-Visualizar por pantalla datos de los usuarios de Brasil que tengan el plan Premium.
 if(codPais == 2 && codPlan == 3){
 	usuariosBrasil++;
 	
-Informar por pantalla la cantidad total de conexiones por día en Uruguay.
	if(codPais == 3){
		conexUruguay++;
		
-Calcular, utilizando una función con paso de parámetro, el porcentaje que representan los
usuarios del plan Básico respecto del total de planes.

ESTRATEGIA:
-void usuariosBrasilPremium();

*/



#include<stdio.h>
#include<string.h>

void iniciarProceso();
void procesarUsuario();
void obtenerPorcentaje(int, int, int);
void mostrarInforme();
void finalizarProceso();


void obtenerUsuario();
void procesarDatosUsuario();
void contCantPaises();
void obtenerUsuariosBrasil();
void obtenerConexUruguay();
void obtenerPlanes();

int conexUruguay, basico, standard, premium;

int vUsuarioPorPais[7] = {0,0,0,0,0,0,0};

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
	procesarUsuario();
	obtenerPorcentaje(basico, standard, premium);
	mostrarInforme();
	finalizarProceso();	
	
	
	return 0;
}

void iniciarProceso(){
	conexUruguay = 0;
	basico = 0;
	standard = 0;
	premium = 0;
	
	
	vf_usuarios = fopen("Netflix.dat", "rb");
	
	printf("\t\t\t***INFORME USUARIOS NETFLIX**\n\n");
}

void procesarUsuario(){
	obtenerUsuario();
	while(!feof(vf_usuarios)){
		procesarDatosUsuario();
		obtenerUsuario();
	}
}

void obtenerUsuario(){
	fread(&vr_usuarios, sizeof(tr_usuarios), 1, vf_usuarios);
}

void procesarDatosUsuario(){
	contCantPaises();
	obtenerUsuariosBrasil();
	obtenerConexUruguay();
	obtenerPlanes();
}

void contCantPaises(){
	vUsuarioPorPais[vr_usuarios.codPais-1]++;
}

void obtenerUsuariosBrasil(){
	if((vr_usuarios.codPais == 2) && (vr_usuarios.codPlan == 3)){
		printf("\nBrasil-Premium --> %d, %s \n", vr_usuarios.codPlan, vr_usuarios.nombre);
	}
}

void obtenerConexUruguay(){
	if(vr_usuarios.codPais == 3){
		conexUruguay++;
	}
}

void obtenerPlanes(){
	if(vr_usuarios.codPlan == 1){
		basico++;
	}
	if(vr_usuarios.codPlan == 2){
		standard++;
	}
	if(vr_usuarios.codPlan == 3){
		premium++;
	}
}


void obtenerPorcentaje(int pBasico, int pStandard, int pPremium){
	return ((float) pBasico  * 100 / (pBasico + pStandard + pPremium));
}

void mostrarInforme(){
	printf("\n\n\t\t\t***CANTIDAD USUARIOS POR PAIS**\n\n");
	printf("\nArgentina: %d", vUsuarioPorPais[0]);
	printf("\nBrasil: %d", vUsuarioPorPais[1]);
	printf("\nUruguay: %d", vUsuarioPorPais[2]);
	printf("\nParaguay: %d", vUsuarioPorPais[3]);
	printf("\nPeru: %d", vUsuarioPorPais[4]);
	printf("\nBolivia: %d", vUsuarioPorPais[5]);
	printf("\nVenezuela: %d\n\n", vUsuarioPorPais[6]);
	
	int i = 0;
	int cantUsuarios = vUsuarioPorPais[0];
	int paisConMasUsuario = 1;
	
	for(i=0;i<7;i++){
		if(vUsuarioPorPais[i] > cantUsuarios){
			cantUsuarios = vUsuarioPorPais[i];
			paisConMasUsuario = i + 1;
		}	
	}
	
	switch(paisConMasUsuario){
		case 1: printf("\n\nArgentina tiene la mayor cantidad de usuarios: %d", cantUsuarios);
		break;
		case 2: printf("\nBrasil tiene la mayor cantidad de usuarios: %d", cantUsuarios);
		break;
		case 3: printf("\nUruguay tiene la mayor cantidad de usuarios: %d", cantUsuarios);
		break;
		case 4: printf("\nParaguay tiene la mayor cantidad de usuarios: %d", cantUsuarios);
		break;
		case 5: printf("\nPeru tiene la mayor cantidad de usuarios: %d", cantUsuarios);
		break;
		case 6: printf("\nBolivia tiene la mayor cantidad de usuarios: %d", cantUsuarios);
		break;
		case 7: printf("\nVenezuela tiene la mayor cantidad de usuarios: %d", cantUsuarios);
		break;		
	}
	
	printf("\n\nConexiones en Uruguay: %d", conexUruguay);
	printf("\nPorcentaje plan basico: % %.2f", obtenerPorcentaje(basico, standard, premium));
}

void finalizarProceso(){
	fclose(vf_usuarios);
}

