/*
    Kevin Navarro
    Andres Martinez
    Diego Vargas
    02/09/22
    Pr�ctica de An�lisis L�xico 02
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <clocale>
#include <regex>

using namespace std;

regex letra{"([a-z])"};
regex numero{"([0-9])"};
regex operadorMatematico{"([+|-|*|/])"};
regex especial{"([.,;()_!])"};
regex operadorRelacional{"([<|>|=])"};
regex palabraReservada{"(si|no|repite|ir|mientras|para|hacer|esto|resultado|termina|inicio|principal|todo|con)"};
regex mayuscula{"([A-Z])"};
regex tipoVariable{"^([A-Z][*\\d]?[A-Za-z\\d]+[.])"};


int main()
{
	setlocale(LC_CTYPE, "Spanish");
    string input;
    vector< string > contenedor;
    bool mayus = false, digito = false, dot = false; 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); //Morado 	Se definen colores 
        
        cout << "\n\n\t\t\t\tA N � L I S I S  L � X I C O\n";	//Nombre del programa ("nombre de la practica")
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
	
	//comparamos la cadena del final al principio del vector
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
	
    return 0;
}

