/*
    Diego Vargas
    Kevin Navarro
    Andres Martinez
    29/09/22
    Pr�ctica de An�lisis L�xico 04
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <locale>
#include <cstring>
#include <regex>

using namespace std;

//prototipo
void validar();




int main()
{
	setlocale(LC_CTYPE, "Spanish");
    string input;
    vector< string > contenedor;
    int a;
    bool again= false;

    cout << "\t\t\t\t       ANALIZADOR LEXICO \n\n";
    cout << "\t\t\t\t\t     MENU\n\n \t\t\t\t 1. leer desde archivo de texto \n \t\t\t\t 2. ingresar desde consola\n";
    cout << "\t\t\t\t 3. Salir \n";
    
    cin >> a;


switch (a) {
  case 1:
    
    break;
  case 2:
    validar();
    break;

  case 3:
    
    cout << "saliendo...";
    return 0;
    break;

  default:
    
    cout << " respuesta no valida ";
    
}


	
	
    return 0;
}

void validar(){

    regex letra("([a-z])");  

    regex numero{"([0-9])"};

    regex operadorMatematico{"([+-*/])"};
    
    regex especial{"([.,;()_!])"};

    regex operadorRelacional{"([<>=])"};

    regex palabraReservada{"(si|no|repite|ir|mientras|para|hacer|esto|resultado|termina|inicio|principal|todo|con)"};

    regex mayuscula{"([A-Z])"};

    regex tipoVariable{"([A-Z][0-9]([a-z0-9]){1,10}\\.)"};

    string input;

    vector< string > contenedor;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); //Morado 	Se definen colores 
        
        cout << "\n\n\t\t\t\tA N A L I S I S  L E X I C O\n";	//Nombre del programa ("nombre de la practica")
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
       
        cout << "\n\n\t\t\t     Teclea un Caracter a para Analizar\n\n"; 
        
        cout << "\n\t\t      Teclea ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //Rojo
        cout << "Esc ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
        cout << "Para Dejar";
       
        cout << " de introducir Caracteres: \n\n";
    while ( cin >> input ) {
        if ( input == "ESC" || input == "Esc" || input == "esc" ) {
            break;
        }
		else{
			contenedor.push_back( input );
		}
    }
    

    sort( contenedor.begin() , contenedor.end() );  
	system("cls");
   // cout << "\n Introdujiste:\n";
    //recorremenos el vector
    for ( int i = 0; i < contenedor.size(); ++i ) {
		
		 if (regex_match(contenedor[i],letra)){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es letra ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y est� ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDA \n";
            } 
            else if (regex_match(contenedor[i],numero)){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es un digito ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y est� ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDA \n";
            }else if (regex_match(contenedor[i],operadorMatematico)){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es un operador matemático ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y est� ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDA \n";
            }else if (regex_match(contenedor[i],especial)){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es un caracter especial ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y est� ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDA \n";
            }else if (regex_match(contenedor[i],operadorRelacional)){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es un operador relacional ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y est� ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDA \n";
            }else if (regex_match(contenedor[i],palabraReservada)){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es una palabra reservada ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y est� ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDA \n";
            }else if (regex_match(contenedor[i],tipoVariable)){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es una variable ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y est� ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDA \n";
            }else if (regex_match(contenedor[i],mayuscula)){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es un caracter/palabra ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y est� ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //rojo
                cout << "NO RECONOCIDO \n";
            }else{
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es un ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "caracter/palabra ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //rojo
                cout << " NO RECONOCIDO \n";
            }	
    }

}