#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <windows.h>

#include "Categorias.h"
#include "Preguntas.h"
#include "RespuestasOpcionales.h"

using namespace std;

//Prototipos de Funcion
void Encabezado();
void CargarCategorias();
void CargarPreguntas();
void CargarRespuestas();

void MostrarListaCategorias();
void MostrarListaComodines();
void MostrarListaPreguntas();
void MostrarListaRespuestas();
void MostrarNivel();

void ConstruirPregunta(int);
bool ValidarRespuesta(int, int);

void UtilizarComodin(int);
void ComodinCincuentaCincuenta();
void ComodinPublico();
void ComodinPasarPregunta();
	
//void ValidarRespuesta();

void gotoxy(int x, int y);

//Variables Globales
int validarPos[4] = {-1,-1,-1,-1};
int validarComodin = 1;
int numPregunta = 1;
int nivel = 1;
int comodin;
int dineroGanado = 0;
vector <Categorias*> listaCategoria;
vector <Preguntas *> preguntas;
vector <RespuestasOpcionales *> respuestas;
string opcionRespuestas[4];
string comodines[3][2] = {
			{"50/50", "0",},
			{"PUBLICO", "0"},
			{"SALTAR PREGUNTA","0"}
};

int main() {
	//Variables
	int opRespuesta;
	//Semilla para generar datos aleatorios.
   	srand( time( NULL ) );
	//Cargamos los datos del juego
	CargarCategorias();
	CargarPreguntas();
	CargarRespuestas();
	
	Encabezado();
	MostrarNivel();
	ConstruirPregunta(numPregunta);
	MostrarListaComodines();
	
	while(true){
		
		//Consultamos sobre el Comodin
		if(validarComodin <= 3){
			gotoxy(2,12);
			cout << ">> Desea utilizar algun comodin: [1] [2] [3] [-1 NO]: ";
			cin >> comodin;
			if(comodin == 1 || comodin == 2 || comodin == 3){
				UtilizarComodin(comodin);
				validarComodin++;
			}
			gotoxy(2,13);
			cout << "-------------------------------------------------------------";
			
		}
		
		cout << "\nQue opcion elije: ";
		cin >> opRespuesta;
		
		while(true){ //Controla los valores de las opciones
			if(opRespuesta <= 4 && opRespuesta >= 1){
				break;
			}else{
				cout << "Que opcion elije: ";
				cin >> opRespuesta;
			}
		}	
		
		//Validamos la Respuesta
		if( !(ValidarRespuesta(numPregunta, opRespuesta))){
			system("cls");
			Encabezado();
			gotoxy(4,2);
			cout << "| Lo siento, respuesta incorrecta." << endl;
			gotoxy(4,3);	
			cout << "| Te quedas con: $. " << dineroGanado << endl;
			gotoxy(4,4);
			cout << "| En el nivel: " << preguntas[numPregunta] -> GetNivelPregunta() << endl << endl;
			system("pause");
			return 0;
			
		}else{
			cout << "\n\tEXCELENTE!! - Muy bien contestado." << endl << endl;
			cout << "\tAhora vamos con la siguiente pregunta." << endl << endl;
			system("pause");
		}
		
		//Controla el fin del juego		
		if(numPregunta == 10 && comodines[2][1] == "0" || numPregunta == 11 && comodines[2][1] != "0" ){
			system("cls");
			Encabezado();
			gotoxy(4,4);
			Encabezado();			
			cout << "Felicidades ahora usted es Millonario!" << endl;
			break;
		}
		
		//Llama una pregunta de los datos cargados
		numPregunta++;
		system("cls");
		Encabezado();
		MostrarNivel();
		ConstruirPregunta(numPregunta);
		MostrarListaComodines();

	}
	
	system("pause");
	return 0;
}

void Encabezado(){
	gotoxy(4,0);
	cout <<" $ $ --> QUIERES SER MILLONARIO <-- $ $ " << endl;
	gotoxy(4,1);
	cout <<" ---------------------------------------" << endl;

}

void CargarCategorias(){
	
	int const tam = 4; // Tamanio de las categorias a guardar
	string listaCategorias[tam] = { //Listamos las Categorias
		"Nombres de Personas", 
		"Paises",
		"Objetos",
		"Ambiente"
	};
	
	//Cargamos la Categoria al objeto
	for(int x = 1; x <= tam; x++){
		//Cargar Objeto;
		Categorias * newCategoria = new Categorias(x, listaCategorias[x-1]);
		//Prueba de Carga
		listaCategoria.push_back(newCategoria);
	}
}

void CargarPreguntas(){

	int tam = 12; // Tamanio del arrelo a guardar
	
	string listaPreguntas[tam][2] = { //Listamos las preguntas principales
		//Nombres
		{"¿Quien pinto con cadaveres humanos? ", "Theodore Gericault"},
		{"¿Quien escribio 'The great Gatsby'?", "F. Fitzgerald"},
		{"¿Quien calculo primero el peso de la Tierra?", "Henry Cavendish"},
		//Paises
		{"¿Donde nacio Juan Carlos I?", "Italia"},
		{"¿Donde se encuentra la cueva de Rouffignac?", "Francia"},
		{"¿De donde es el poeta Mahmud darwish?", "Al-Birwa"},
		//Objetos
		{"¿Por que no hay planetas cuadrados?", "La gravedad"},
		{"¿Que es una tormenta de viento de gas alrededor de un agujero negro?", "Huracan estelar" },
		{"¿Cual es el apodo del Leicester City?", "Los Zorros"},
		//Ambiente
		{"¿Por que una naranja y un limon huelen distinto?", "Espectro IR"},
		{"Si plantaras las semilla de 'Quercus Robur', ¿que creceria?", "Arboles"},
		{"¿Que unidad cientifica lleva el nombre de un noble italiano?", "Voltio"}
	};
	
	//Contador de categoria.
	int cat=1, temp=0;
	
	//Cargamos la Categoria al objeto
	for(int x = 0; x < tam; x++){
		//Cargar Objeto
		Preguntas * newPreguntas = new Preguntas(cat, cat, listaPreguntas[x][0], listaPreguntas[x][1]);
		//Prueba de Carga
		preguntas.push_back(newPreguntas);
		
		//Controlar las cargas de preguntas, de 3 en 3
		temp++;
		if(temp == 3){cat++; temp=0;}
	}
}

void CargarRespuestas(){
	
	int const tam = 60; // Tamanio de las respuestas a guardar
	string listaRespuestas[tam] = { //Listamos las respuestas
		"Sigmund Freud", 	"Daniel Kahneman", 		"Stephen King",
		"Michael Jordan", 	"Charlotte Hornets",	"Pablo Neruda",
		"Stephen Hawking",	"Marquesa de Merteuil", "Homero", 
		"Teseo",			"Antony Durken",		"Leon Tolstoi",
		"Charles Darwin",	"Charls Town",			"Terry Pratchet",
		
		"Grecia", 			"Roma",					"Atenas",
		"Egipto",			"Esparta",				"Rusia",
		"U.S.A",			"Escocia",				"Suecia",
		"Arabia Saudita",	"Turquia",				"Japon",
		"Alabama",			"Venecia",				"Mexico",
		
		"Los Atomos", 		"La Atmosfera", 	"Espectro Climatico",
		"Huracan Negro", 	"Colosus IR", 		"Tormenta Estelar", 
		"El Propano", 		"El oxigeno", 		"Leicesters",	
		"Los Tigres", 		"Panteras",		 	"Los Jaguares",
		"Alcones de L.C.",	"Cromo",			"Melanina",
	
		"Plantas",			"Flores", 			"Frutos Secos",
		"ADN",				"Metafragma",		"Hidrogeno",
		"Litio", 			"Berilio",			"Silicio",
		"Faccion CR", 		"Bromuro",			"Pasto",
		"Granos",			"Suculentas",		"Zinc"
	};
	
	//Contador de categoria.
	int cat=1, temp=0;
	
	//Cargamos la Categoria al objeto
	for(int x = 1; x <= tam; x++){
		//Cargar Objeto;
		RespuestasOpcionales * newRespuestas = new RespuestasOpcionales(cat, listaRespuestas[x-1]);
		//Prueba de Carga
		respuestas.push_back(newRespuestas);
		
		//Controlar las cargas de respuestas, de 6 en 6
		temp++;
		if(temp == 15){cat++; temp=0;}
	}
}

void MostrarListaCategorias(){
	//Puede Mostrar la lista de categorias Cargadas
	for(unsigned i = 0; i < listaCategoria.size(); i++){
		listaCategoria[i] -> MostrarCategoria();
		cout << endl;
	}
}

void MostrarListaComodines(){
	int posX = 4, posY = 10;
	
	gotoxy(posX, posY-2);
	cout << endl << "  ";
	for(int i = 0; i < 60; i++){
		cout << "-";	
	}
	for(int x=0; x < 3; x++){
		if(comodines[x][1] == "0"){
			gotoxy(posX, posY);
			cout << "[ ] " <<comodines[x][0];
			posX += 17;
		}else{
			gotoxy(posX, posY);
			cout << "[X] " <<comodines[x][0];
			posX += 17;
		}
	}
	
	cout << endl << "  ";
	for(int i = 0; i < 60; i++){
		cout << "-";	
	}
}

void MostrarListaPreguntas(){
	//Puede Mostrar la lista de preguntas Cargadas
	for(int i = 0; i < preguntas.size(); i++){
		preguntas[i] -> MostrarPregunta();
		cout << endl;
	}
}

void MostrarListaRespuestas(){
	//Puede Mostrar la lista de preguntas Cargadas
	for(int i = 0; i < respuestas.size(); i++){
		respuestas[i] -> MostrarRespuestaOpcional();
		cout << endl;
	}
}

void MostrarNivel(){
	int x = 90, y =3;
	if(comodines[2][1]	 != "1"){
		gotoxy(x+17, (y + 12) - numPregunta); cout << "<-- [x]";
	}else{
		gotoxy(x+17, (y + 13) - numPregunta); cout << "<-- [x]";
	}
				
	if(numPregunta ==  4){dineroGanado = 1000;}
	if(numPregunta ==  7){dineroGanado = 500000;}
	if(numPregunta == 10){dineroGanado = 1000000;}
	if(numPregunta == 12){dineroGanado = 100000000;}
	
	//Nivel 4
	gotoxy(x-3,y- 2); cout << "| VALOR DE LAS PREGUNTAS: " << endl;
	gotoxy(x-3,y- 1); cout << "| ----------------------- " << endl;
	gotoxy(x,y+ 1); cout << "$.100,000,000.00"<<endl;
	gotoxy(x,y+ 2); cout << "$. 50,000,000.00"<<endl;
	//Nivel 3
	gotoxy(x,y+ 3); cout << "$. 10,000,000.00"<<endl;
	gotoxy(x,y+ 4); cout << "$.  1,000,000.00"<<endl;
	gotoxy(x,y+ 5); cout << "$.    900,000.00"<<endl;
	//Nivel 2
	gotoxy(x,y+ 6); cout << "$.    500,000.00"<<endl;
	gotoxy(x,y+ 7); cout << "$.    100,000.00"<<endl;
	gotoxy(x,y+ 8); cout << "$.     10,000.00"<<endl;
	//Nivel 1
	gotoxy(x,y+ 9); cout << "$.      1,000.00"<<endl;
	gotoxy(x,y+10); cout << "$.        900.00"<<endl;
	gotoxy(x,y+11); cout << "$.        500.00"<<endl;
}

void ConstruirPregunta(int nPregunta){	
	//Cargamos las repuestas
    opcionRespuestas[0] = preguntas[nPregunta-1] -> GetRespuesta(); //Tomo la respuesta correcta
    int posRespuesta, pos = 0;
    bool respuestaCorrecta = true;
    validarPos[0] = -1; validarPos[1] = -1; validarPos[2] = -1; validarPos[3] = -1;
    //Luego Guardamos el resto de las respuestas.
    int numRespuestas = 0;
    for(int x=0; x < 4; x++){
    	bool validar = true;
    	while(validar){
    		numRespuestas = (rand() % 60 + 1);
	    	if(respuestas[numRespuestas-1] -> GetNCategoria() == preguntas[nPregunta-1] -> GetNCategoria()){
	    		posRespuesta = (rand() % 4 + 1);//Genero posicion aleatoria
	    		
				if(posRespuesta == validarPos[0] || posRespuesta == validarPos[1] || posRespuesta == validarPos[2] || posRespuesta == validarPos[3]){ //Valido si no se repite
					validar = true; //Si ya esta cargada que continue el programa
				}else {
					if(respuestaCorrecta){
		    			opcionRespuestas[posRespuesta-1] = preguntas[nPregunta-1] -> GetRespuesta(); //Tomo la respuesta correcta
		    			validarPos[pos] = posRespuesta; //guarda la posicion par no repetirla
						pos +=1;
						respuestaCorrecta = false;
						break;
					}
					validarPos[pos] = posRespuesta; 
					pos +=1;
		    		opcionRespuestas[posRespuesta-1] = respuestas[numRespuestas-1] -> GetRespuestaOpcional();   	
		    		validar = false;
		    	}
			}	
		}
	}

	//Imprime las preguntas con su respuesta
    gotoxy(2,3); //Posicion de la pregunta
    int posX = 4, posY = 5; //Posicion de las respuestas
    
	cout << ">> " << preguntas[nPregunta-1] -> GetPregunta() << endl; //Mandamos a imprimir la pregunta
	for(int i=1; i <= 4; i++){ //Imprime las respuestas
		gotoxy(posX,posY);
		
		cout << i << ") " <<  opcionRespuestas[i-1]; //Imprime las respuestas de forma aleatoria
		posX += 25;
		if(i % 2 == 0){
			cout << endl;
			posY += 2;
			posX = 4;
		}
	}
}

//Validar pregunta
bool ValidarRespuesta(int nPregunta, int opRespuesta){
	if(preguntas[nPregunta-1] -> GetRespuesta() == opcionRespuestas[opRespuesta-1]){
		return true;
	}else{
		return false;
	}
}

//Utiliza algun comodin
void UtilizarComodin(int nComodin){
	bool validar = true;
	
	if(comodines[0][1] == "0" || comodines[1][1] == "0" || comodines[2][1] == "0"){
		do{
			switch(nComodin){
				case 1:
					if(comodines[0][1] == "0"){
						ComodinCincuentaCincuenta();
						validar = false;
						break;	
					}
					nComodin = -1;
					break;
				case 2:
					if(comodines[1][1] == "0"){
						ComodinPublico();
						validar = false;
						break;	
					}
					nComodin = -1;
					break;
				case 3:
					if(comodines[2][1] == "0"){
						ComodinPasarPregunta();
						validar = false;
						break;	
					}
					nComodin = -1;
					break;
					break;
				default:
					gotoxy(4, 13);
					cout << "Numero de Comodin, no disponible.";
					cin >> nComodin;
			}
		}while(validar);
	}else{
		gotoxy(4, 13);
		cout << "Lo siento ya utilizaste todos tus comodines" << endl;
		system("pause");
	}
	

}

void ComodinCincuentaCincuenta(){
	//Imprime las preguntas con su respuesta
    int posX = 4, posY = 5; //Posicion de las respuestas
	int mitad = 1;
    	
	for(int i = 0; i < 4; i++){
		gotoxy(posX,posY);
		if(opcionRespuestas[i] == preguntas[numPregunta-1] -> GetRespuesta()){
			i++;
		} if(mitad <= 2){
			opcionRespuestas[i] = "                           ";	
			mitad++;
		}
	}

	for(int i=1; i <= 4; i++){ //Imprime las respuestas
		gotoxy(posX,posY);
		cout << i << ") " <<  opcionRespuestas[i-1]; //Imprime las respuestas de forma aleatoria
		posX += 25;
		if(i % 2 == 0){
			cout << endl;
			posY += 2;
			posX = 4;
		}
	}
	comodines[0][1]	 = "1";
	MostrarListaComodines();
}

void ComodinPublico(){
	comodines[1][1]	 = "1";
	int calcularPorcentaje = 100;
	int porcentajeRespuesta;
	gotoxy(55, 1);
	cout << "| Estadisticas del Publico: " << endl;
	gotoxy(55, 2);
	cout << "| ------------------------ " << endl;
	for(int x=0; x < 3; x++){
		porcentajeRespuesta = (rand() % calcularPorcentaje + 1);
		calcularPorcentaje -= porcentajeRespuesta;	
		gotoxy(55, 3+x);
		cout <<"| "<< opcionRespuestas[x] << " : "<< porcentajeRespuesta << " % " << endl;
	}
	gotoxy(55, 6);
	cout << "| "<< opcionRespuestas[3] << " : "<< calcularPorcentaje << " % " << endl;
}

void ComodinPasarPregunta(){
	system("cls");
	numPregunta++;
	comodines[2][1]	 = "1";
	validarComodin++;
	main();
}


//Ubica las posiciones en pantalla
void gotoxy (int x, int y)
{
    COORD coord; // coordinates
    coord.X = x; coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // moves to the coordinates
}

