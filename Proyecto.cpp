#include <iostream>
#include <dos.h>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <Windows.h>
#include "Semaforo.h"
#include "Semaforo.cpp"
#include <stdio.h>
#include <stdlib.h>


using namespace std;

bool alcalde;
void pausa();
void delegartareas(string jardineros);
void asignarHerramienta(string jardineros);
void cambiarRitmo(string ritmo);
void amonestacion(int jardineros, string ritmo);
void despedir(int jardineros, int amonestaciones);
void verificar_herramientas();
void verificar_clima();

string jardineros[9] = {"Primer Jardinero", "Segundo Jardinero", "Tercer Jardinero", "Cuarto Jardinero", "Quinto Jardinero", "Sexto Jardinero", "Septimo Jardinero", "Octavo Jardinero", "Noveno Jardinero"};
string trabajo[9] = {"Podar cesped", "Podar Arboles", "Regar arboles y macetas","Barrer", "Plantar flores", "Realizar Inventario", "Recoger hojas", "Abonar plantas", "Transplantar"};
string herramienta[9] ={"Cortadora","Tijeras","Regadera","Escoba", "Pala", "Tablero y lapiz", "Rastrillo", "Carretilla", "Azada y Pala"};
string ritmod[9] = {"Lenta","Lenta","Lenta","Lenta","Lenta","Lenta","Lenta","Lenta","Lenta"};
string ritmo[9] = {"Rapida","Rapida","Rapida","Rapida","Rapida","Rapida","Rapida","Rapida","Rapida"};
int amonestaciones[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int num_random = rand();
int clima_aleatorio = rand();
Semaforo semaforo;

int main(int argc, char** argv) {
	
	
	while(true){
		for(int i = 0; i < 9999; i++){
			if(i == 3 || i == 7 || i == 11 || i == 15 || i == 19 || i == 23){ //Manejo de jornadas
				cout << "La jornada ha terminado";
				pausa();
				pausa();
				system("cls"); //Limpía la pantalla
			}
			else{
				if(i%2 == 0){
					alcalde = true;
					cout << "El alcalde delegara las tareas " << endl;
					semaforo.wait();
					cout << "Los jardineros estan proximos a llegar";
					//semaforo.wait();
					cout << endl;
					
					for(int i = 0; i < 9; i++){//Asignar tareas a jardineros 
						cout << "Al " << jardineros[i];
						cout << " se le asigna " << trabajo[i];
						cout << " con la herramienta " << herramienta[i]<<endl;
						cout<< endl;
						delegartareas(jardineros[i]);
						Sleep(1000); //Permite hacer una pausa por una determinada cantidad de segundos en la ejecucion de un programa.
						cambiarRitmo(ritmo[i]);
					
					}
					verificar_clima();
					cout<<"Realizando tareas: "<< endl;
					cout<<endl;
					for(int i = 0; i < 9; i++){//Verificacion de ritmo jardineros
						cout << "El " << jardineros[i];
						cout << " esta realizando " << trabajo[i];
						cout << " con la herramienta " << herramienta[i]<<endl;
						cout << "a velocidad " << ritmo[i] << endl;
						cout << endl;
						delegartareas(jardineros[i]);
						verificar_herramientas();
						cout << endl;
						Sleep(2000);
						cambiarRitmo(ritmo[i]);
					}
					
					cout << "Cuando el alcalde se va los jardineros comienzan a tranajar lento" << endl;
					Sleep(1000);
					cout << "El alcade se va";
					system("cls");
					
				}
				else{
					alcalde = false;//Sin el alcalde presente
					cout << "El alcalde no esta presente" << endl;
					cout << endl;
					
					verificar_clima();
					cout<<"Realizando tareas: "<< endl;
					cout << endl;
					for(int i = 0; i < 9; i++){
						
						cout << "El " << jardineros[i];
						cout << " esta realizando " << trabajo[i];
						cout << " con la herramienta " << herramienta[i]<<endl;
						cout << "a velocidad " << ritmod[i] << endl;
						cout << endl;
						delegartareas(jardineros[i]);
						verificar_herramientas();
						verificar_clima();
						cout<<endl;
						Sleep(2000);
						cambiarRitmo(ritmo[i]);
						
						
					}
					
					cout << "Cuando el alcalde se acerca comienzan a trabajar rapido" << endl;
					semaforo.wait();
					cout << endl;
					
					for(int i = 0; i < 9; i++){
						
						amonestacion(i, ritmo[i]);
						
					}
					
					semaforo.wait();
					system("cls");
				}
			}
		}
	}
	
	return 0;
}

void pausa(){
	for(int i = 0; i < 8; i++){
		cout << ".";
		Sleep(600);
	}
}

void delegartareas(string p_jardineros){//Asignacion de trabajos                       
	int p_trabajo[9] = {0,1,2,3,4,5,6,7,8};
	Semaforo semaforo;
	
	for(int i = 0; i < 9; i++){
		if(p_trabajo[i] == i){
			semaforo.semWait(p_jardineros);
		}
		else{
			cout << "Trabajo ya asignado";
		}
	}
}

void asignarHerramienta(string p_jardineros){
	int p_herramienta[9] = {0,1,2,3,4,5,6,7,8};
	Semaforo semaforo;
	
	for(int i = 0; i < 9; i++){
		if(p_herramienta[i] == i){
			semaforo.semWait(p_jardineros);
		}
		else{
			cout << "Herramienta ya asignado";
		}
	}
}

void cambiarRitmo(string p_ritmo){
	string ritmo[9] = {"Lenta", "Lenta", "Lenta", "Lenta", "Lenta","Lenta","Lenta","Lenta","Lenta"};
	
	for(int i = 0; i < 9; i++){
		if(ritmo[i] == "Lenta"){
			ritmo[i] == "Rapida";
		}
		else{
			ritmo[i] == "Lenta";
		}
	}
}

void amonestacion(int p_jardineros, string p_ritmo){
	int amonestaciones[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	if(p_ritmo == "Lenta"){
		amonestaciones[p_jardineros] += 1;
	
	}
}

void despedir(int p_jardineros, int p_amonestaciones){
	string jardineros[9] = {"Primer Jardinero", "Segundo Jardinero", "Tercer Jardinero", "Cuarto Jardinero", "Quinto Jardinero"};
	int amonestaciones[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	for(int i = 0; i < 9; i++){
		if(amonestaciones[i] == 3){
			cout << "El " << jardineros[i] << " esta despedido por acumulacion de amonestaciones";
		}
	}
}

void verificar_herramientas(){
	srand(time(NULL));
	num_random = 1 + rand()%8;
	if(num_random==1){
		system("COLOR 4F");
		cout<<"Un saboteador danio la herramienta"<< endl;
		semaforo.wait();
		cout<< endl;
		cout<<"Se ha remplazado la herramienta"<< endl;
		system("COLOR 07" );
	}
	
	else if (num_random >2){
		cout<< "El trabajo se realiza correctamente"<< endl; 
	}
	
	
}

void verificar_clima(){
	srand(time(NULL));
	clima_aleatorio = 1 + rand()%4;
	int interrupcion = rand();
	switch(clima_aleatorio){
		case 1: cout<<"Estamos en la epoca de Verano"<< endl;
		srand(time(NULL));
        interrupcion = 1+ rand()%5;
		switch (interrupcion){
			case 1: cout<<"Hay buen clima, las tareas se realizan con normalidad"<<endl;
			cout<< endl;
			break;
			case 2: system("COLOR 4F" );
			cout<<"Ha sucedido un incendio, se detienen las tareas"<<endl;
			semaforo.wait();
			cout<< endl;
			system("COLOR 07" );
			cout<<"El incendio fue controlado"<<endl;
			cout<< endl;
			break;
			case 3: system("COLOR 4F" );
			cout<<"Se ha producido un terremoto, se detienen las tareas"<<endl;
			semaforo.wait();
			cout<< endl;
			system("COLOR 07" );
			cout<<"el peligro ha pasado"<<endl;
			cout<< endl;
			break;
			case 4: system("COLOR 4F" );
			cout<<"El jardinero se ha fracturado"<<endl;
			semaforo.wait();
			cout<< endl;
			system("COLOR 07" );
			cout<<"El jardinero ya ha recibido atencion medica"<<endl;
			cout<< endl;
			break;
			case 5: system("COLOR 4F" );
			cout<<"El jardinero ha sufrido insolacion"<<endl;
			semaforo.wait();
			cout<< endl;
			system("COLOR 07" );
			cout<<"El jardinero ha tomado reposo y recuperado"<<endl;
			cout<< endl;
			break;
			default: cout<< endl;
		}
		break;
		case 2: cout<<"Estamos en la epoca de Otonio"<< endl;
		srand(time(NULL));
        interrupcion = 1+ rand()%3;
		switch(interrupcion){
			case 1: cout<<"Hay buen clima, las tareas se realizan con normalidad"<<endl;
			cout<< endl;
			break;
			case 2: system("COLOR 4F" );
			cout<<"Se ha producido un terremoto, se detienen las tareas"<<endl;
			semaforo.wait();
			cout<< endl;
			system("COLOR 07" );
			cout<<"el peligro ha pasado"<<endl;
			cout<< endl;
			break;
			case 3: system("COLOR 4F" );
			cout<<"El jardinero se ha fracturado"<<endl;
			semaforo.wait();
			cout<< endl;
			system("COLOR 07" );
			cout<<"El jardinero ya ha recibido atencion medica"<<endl;
			cout<< endl;
			break;
			default: cout<< endl;
		}
		break;
		case 3: cout<<"Estamos en la epoca de Primavera"<< endl;
		srand(time(NULL));
        interrupcion = 1+ rand()%4;
		switch (interrupcion){
        	case 1: cout<<"Hay buen clima, las tareas se realizan con normalidad"<<endl;
			cout<< endl;
			break;
			case 2: system("COLOR 4F" );
			cout<<"Se ha producido un terremoto, se detienen las tareas"<<endl;
			semaforo.wait();
			cout<< endl;
			system("COLOR 07" );
			cout<<"el peligro ha pasado"<<endl;
			cout<< endl;
			break;
			case 3: system("COLOR 4F" );
			cout<<"El jardinero se ha fracturado"<<endl;
			semaforo.wait();
			cout<< endl;
			system("COLOR 07" );
			cout<<"El jardinero ya ha recibido atencion medica"<<endl;
			cout<< endl;
			break;
			case 4: system("COLOR 4F" );
			cout<<"Se ha desencadenado una plaga de grillos"<<endl;
			semaforo.wait();
			cout<< endl;
			system("COLOR 07" );
			cout<<"Se ha controlado la plaga"<<endl;
			cout<< endl;
			break;
			default: cout<< endl;
		}
        break;
		case 4: cout<<"Estamos en la epoca de invierno"<< endl;
		srand(time(NULL));
        interrupcion = 1+ rand()%4;
		switch(interrupcion){
        	case 1: cout<<"Hay buen clima, las tareas se realizan con normalidad"<<endl;
			cout<< endl;
			break;
			case 2: system("COLOR 4F" );
			cout<<"Ha comenzado a llover, las tareas se detienen hasta que pare la lluvia"<<endl;
			semaforo.wait();
			cout<< endl;
			int intensidad=rand();
            srand(time(NULL));
			intensidad=1+rand()%2;
		    if (intensidad == 1){
			    system("COLOR 07" );
		        cout<<"ah parado la lluvia, continuan las labores"<< endl;
		    }
		    else if(intensidad == 2){
		        cout<< "Se ha producido una inundacion, esperar a que pare la lluvia "<< endl;
		        semaforo.wait();	
		        cout<<endl;
				system("COLOR 07" );
		        cout<< "ha parado de llover, se pueden reanudar las tareas  " << endl;
		        cout<< endl;
		    }
			break;
			/*case 3: system("COLOR 4F" );
			cout<<"El jardinero se ha fracturado"<<endl;
			semaforo.wait();
			cout<< endl;
			cout<<"El jardinero ya ha recibido atencion medica"<<endl;
			cout<< endl;
			break;
			case 4: system("COLOR 4F" );
			cout<<"Se ha producido un terremoto, se detienen las tareas"<<endl;
			semaforo.wait();
			cout<< endl;
			cout<<"el peligro ha pasado"<<endl;
			cout<< endl;
			break;*/
			//default: cout<< endl;
	}
	    
	/*if(clima_aleatorio==1){
		cout<<"el clima esta bueno para trabajar"<< endl;
		cout<< endl;
	}
	if(clima_aleatorio==2){
		system("COLOR 4F" );
		cout<<"ah empezado a llover!!!, se pararan las operaciones hasta que deje de llover" << endl;
		semaforo.wait();
		cout<< endl;
		srand(time(NULL));
		interrupcion = 1 + rand()%2;
		if (interrupcion == 1){
		cout<<"ah dejado de llover!, a seguir con las tareas"<< endl;
		}
		else if(interrupcion == 2){
		cout<< "Se ha producido una inundación, esperar a que pare la lluvia "<< endl;
		semaforo.wait();	
		cout<<endl;
		cout<< "ha parado de llover, se pueden reanudar las tareas  " << endl;
		cout<< endl;
		}
		system("COLOR 07" );
	}*/
	}
}
