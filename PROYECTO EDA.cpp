#include <iostream>
#include <cstdlib>
#include <cstring>
#include <windows.h>


using namespace std;

struct paciente{
	char nombre[20];
	struct paciente *sgte;
};

struct medico{
	char nombre[20];
	char especialidad[100];
	struct medico *sgte;
	struct paciente *proximo;
	struct carga *Hist_Clin_Paciente;
	struct  disponibilidadcamas *habita;
	struct farmacia * lote;
};

struct Hist_Clin_Paciente{
	char enfemerdad[50];
	char estado[50];
	char tratamientos[50];
	struct Hist_Clin_Paciente *sgte;
};

struct disponibilidadcamas{
    char cantidad[50];
    char ubicacion[50];
    char nombre_cama[50];
    struct disponibilidadcamas *sgte;
};

struct farmacia{
	char cantidades[50];
	char codigo_medicamento[50];
	char tipo_medicamento[50];
	char estado_medicamento[50];
	struct farmacia *sgte;
};

typedef struct paciente *Paciente;
typedef struct medico *Medico;
typedef struct Hist_Clin_Paciente *Historial;
typedef struct disponibilidadcamas *Camas;
typedef struct farmacia *Medicamentos;

void insertar(Medico &lista, char nombre[], char especialidad[]){
	Medico nuevo = new (struct medico);
	strcpy(nuevo -> nombre, nombre);
	strcpy(nuevo -> especialidad, especialidad);
	nuevo -> proximo = NULL;
	nuevo -> sgte = lista;
	lista = nuevo;
}


int main(){
	
	return 0;
}
