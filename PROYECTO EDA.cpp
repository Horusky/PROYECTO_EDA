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

void ingresaPacientes(Medico lista){
	int np;
	Medico tmp = lista;
	Paciente paciente = NULL;

	while (tmp){
		cout << "\n>>> Ingrese la cantidad de pacientes para el especialista [" << tmp -> nombre << "]: ";
		cin >> np;
		cout << endl;

		for (int i = 0; i < np; i++){
			paciente = new (struct paciente);
			
			cout << " ---> Paciente Num " << i + 1 << ": ";
			cin >> paciente -> nombre;
			paciente -> sgte = tmp -> proximo;
			tmp -> proximo = paciente;
		}
		tmp = tmp -> sgte;
	}
	cout << endl;
	
	cout << "  ";
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << ">";Sleep(800);
	cout << " Paciente(s) registrado(s) correctamente.";Sleep(2000);
	cout << endl;
}

void ingreseHistorial(Medico lista){
	int np;
	Medico tmp = lista;
	Paciente tmpPaciente = NULL;
	Historial Hist_Clin_Paciente = NULL;

	while (tmp){
		Sleep(1000);
		cout << endl;
		cout << ">>> Ingrese el numero de historial medico, recuerde que su medico es [" << tmp -> nombre << "]: ";
		cin >> np;
		
		for (int i = 0; i < np; i++){
			Hist_Clin_Paciente = new (struct Hist_Clin_Paciente);

			cout << endl;
			cout << " ---> Historial [" << i + 1 << "]: La enfermedad del paciente es: ";
			cin >> Hist_Clin_Paciente -> enfemerdad;

			cout << " ---> Historial [" << i + 1 << "]: El estado del paciente es: ";
			cin >> Hist_Clin_Paciente -> estado;

			cout << " ---> Historial [" << i + 1 << "]: Los tratamientos del paciente es: ";
			cin >> Hist_Clin_Paciente -> tratamientos;
		}
		tmp = tmp -> sgte;
	}

	cout << endl;

	cout << "  ";
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << ">";Sleep(800);
	cout << " Historial(es) medico(s) registrado(s) correctamente.";Sleep(2000);
}

void RegistrarCamas(Medico lista){
    int np;
	int i = 0;
	Medico tmp = lista;
	Paciente tmpPaciente = NULL;
	Camas disponibilidadcamas = NULL;

	while (tmp){
		cout << endl;
		cout << "\n>>> Ingrese la cantidad de habitaciones para las camas disponibles, generadas para los pacientes del medico [" << i++ +1 << "]: ";
		cin >> np;
		cout << endl;

		for (int i = 0; i < np; i++){
			disponibilidadcamas = new (struct disponibilidadcamas);
			
			cout << " ---> Ingrese la cantidad de camas disponibles en la habitacion [" << i + 1 << "]: ";
			cin >> disponibilidadcamas -> cantidad;
			cout << " ---> Ingrese el piso y pasillo de la habitacion [" << i + 1 << "]: ";
			cin >> disponibilidadcamas -> ubicacion;
			cout << " ---> Ingrese un alias para la cama del paciente: ";
			cin >> disponibilidadcamas -> nombre_cama;
		}
		tmp = tmp -> sgte;
	}
	cout << endl;
	
	cout << "  ";
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << "=";Sleep(100);
	cout << ">";Sleep(800);
	cout << " Cama(s) registrada(s) correctamente.";Sleep(2000);
    
}


int main(){
	
	return 0;
}
