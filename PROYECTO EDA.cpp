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

void RegistrarMedicamentos(Medico lista){
    int np;
	int i = 0;
    Medico tmp = lista;
    Medicamentos farmacia = NULL;
	
    while (tmp){
		cout << "\n>>> Ingrese la cantidad de medicamentos para los pacientes del medico [" << i++ +1 << "]: ";
		cin >> np;

		for (int i = 0; i < np; i++){
			farmacia = new (struct farmacia);

			cout << endl;
			cout << " ---> El codigo del medicamento [" << i + 1 << "] es: ";
			cin >> farmacia -> codigo_medicamento;
			cout << " ---> nombre del medicamento [" << i + 1 << "] es: ";
			cin >> farmacia -> tipo_medicamento;
			cout << " ---> El estado del medicamento [" << i + 1 << "] es: ";
			cin >> farmacia -> estado_medicamento;
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
	cout << " Medicamento(s) registrado(s) correctamente.";Sleep(2000);
	cout << endl;
}

void BusquedaMedico(Medico lista, char nombre[], char especialidad[]){
	Medico tmp = lista;
	Paciente tmpPaciente = NULL;
	Historial tmpHistorial = NULL;
    Medicamentos tmpMedicamentos = NULL;
	while (tmp){
		if (!strcmp(tmp -> nombre, nombre)){
			
			int i = 0;
			Sleep(500);
			cout << " \n ---> Buscando especialista...\n";
			Sleep(2000);
		
			cout << "\n===========================================\n";
			cout << "\t  Especialista encontrado";
			cout << "\n===========================================\n";
			Sleep(3000);
		
			cout << endl;
			cout << ">>> El nombre del especialista es: " << tmp -> nombre << endl;
			tmpPaciente = tmp -> proximo;
			cout << endl;

			while (tmpPaciente){
				cout << ">>> El paciente [" << i++ + 1 << "] del medico [" << tmp -> nombre << "] es: " << tmpPaciente -> nombre << endl;
				tmpPaciente = tmpPaciente -> sgte;
			}
			cout << "\n===========================================\n";
			cout << endl;
			
			return;
		}
		tmp = tmp -> sgte;

		if (tmp == NULL){
			Sleep(500);
			cout << " \n ---> Buscando especialista...\n";
			Sleep(2000);

			cout << "\n===========================================\n";
			cout << "\t  Especialista no encontrado";
			cout << "\n===========================================\n";
			Sleep(3000);
			
			cout << endl;
			cout << " ---> No hemos podido encontrar el nombre del especialista [" << nombre << "]." << endl;
			cout << " ---> No hemos podido encontrar la especialidad(es) [" << especialidad << "]." << endl;
			cout << "\n===========================================\n";
			cout << endl;
			Sleep(1000);
			exit(0);
		}
	}
}

void imprimir(Medico lista){
	Medico tmp = lista;
	Paciente tmpPaciente = NULL;
	Historial tmpHistorial = NULL;
	Camas tmpCamas = NULL;
	Medicamentos tmpMedicamentos = NULL;

	while (tmp){

		int i = 0;

		cout << endl;
		cout << ">>> El especialista es: " << tmp -> nombre << endl;
		tmpPaciente = tmp -> proximo;
		tmpCamas = tmp -> habita;
		tmpMedicamentos = tmp -> lote;
		cout << endl;
		
		if (tmpPaciente){
			cout << ">>> El paciente [" << i++ + 1 << "] es: " << tmpPaciente -> nombre << endl;
			tmpPaciente = tmpPaciente -> sgte;
		}
		
		return;
	}
}


int main(){
	
	return 0;
}
