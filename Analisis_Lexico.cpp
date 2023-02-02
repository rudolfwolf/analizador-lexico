/*
    Kevin Navarro
    Andres Martinez
    Diego Vargas
    02/09/22
    Práctica de Análisis Léxico 02
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <clocale>
#include <cstring>
#include <iterator>

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Spanish");
    string input;
    vector< string > contenedor;
    vector< int > int_contenedor;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); //Morado 	Se definen colores 
        
        cout << "\n\n\t\t\t\tA N Á L I S I S  L É X I C O\n";	//Nombre del programa ("nombre de la practica")
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
       
        cout << "\n\n\t\t\t     Teclea un Caracter a para Analizar\n\n"; 
        
        cout << "\n\t\t      Teclea ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //Rojo
        cout << "Esc ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
        cout << "Para Dejar";
       
        cout << " de introducir Caracteres: \n\n";
    while ( cin >> input ) {
        if ( input == "esc" || input == "Esc" || input == "esc" ) {
            break;
        }
        // introduce la cadena capturada dentro del vector
        contenedor.push_back( input );
    }
	
	//comparamos la cadena del final al principio del vector
    sort( contenedor.begin() , contenedor.end() );
	system("cls");
    cout << "\n Introdujiste:\n";
    //recorremenos el vector
    for ( int i = 0; i < contenedor.size(); ++i ) {
        if (contenedor[i] == "a" || contenedor[i] == "b" || contenedor[i] == "c" || contenedor[i] == "d" || contenedor[i] == "e" || contenedor[i] == "f" ||
				contenedor[i] == "g" || contenedor[i] == "h" || contenedor[i] == "i" || contenedor[i] == "j" || contenedor[i] == "k" || contenedor[i] == "l" ||
				contenedor[i] == "m" || contenedor[i] == "n" || contenedor[i] == "o" || contenedor[i] == "p" || contenedor[i] == "q" || contenedor[i] == "r" || 
				contenedor[i] == "s" || contenedor[i] == "t" || contenedor[i] == "u" || contenedor[i] == "v" || contenedor[i] == "w" || contenedor[i] == "x" || 
				contenedor[i] == "y" || contenedor[i] == "z"){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es letra ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y está ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDA \n";
            }else if(contenedor[i] == "<"|| contenedor[i] == ">" || contenedor[i] == "="){
    		    
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es operador relacional ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y está ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDO \n";		
			}else if(contenedor[i]=="0"|| contenedor[i]=="1"|| contenedor[i]=="2"|| contenedor[i]=="3"|| 
					 contenedor[i]=="4"|| contenedor[i]=="5"|| contenedor[i]=="6"|| contenedor[i]=="7"|| 
					 contenedor[i]=="8"|| contenedor[i]=="9"){
    		    
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco  
                cout <<" " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es dígito ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y está ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDO \n";		
	}else if(contenedor[i]=="-" || contenedor[i]=="+"|| contenedor[i]=="*" || contenedor[i]=="/"){
				
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout<< " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout<< " es operador aritmético ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout<< "y está ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout<< "RECONOCIDO \n";		
	}else if(contenedor[i]=="."|| contenedor[i]== "," || contenedor[i]==";" || contenedor[i]== "_" || contenedor[i]== "!" || 
		contenedor[i]== "["|| contenedor[i]=="]"|| contenedor[i]=="("|| contenedor[i]==")"|| contenedor[i]=="{" || contenedor[i]=="}"){
    		 	
				 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout<< " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout<< " es caracter especial ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout<< "y está ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout<< "RECONOCIDO \n";
			}else if(contenedor[i]=="si"|| contenedor[i]=="no"|| contenedor[i]=="repite"|| contenedor[i]=="ir"|| contenedor[i]=="mientras"|| contenedor[i]=="para"
					|| contenedor[i]=="hacer"|| contenedor[i]=="esto"|| contenedor[i]=="resultado"|| contenedor[i]=="termina"|| contenedor[i]=="inicio"
					|| contenedor[i]=="principal"|| contenedor[i]=="todo"|| contenedor[i]=="con"){
		
		 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout<< " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout<< " es palabra reservada ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout<< "y está ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout<< "RECONOCIDA \n";
	
			}else if (contenedor[i] == "A" || contenedor[i] == "B" || contenedor[i] == "C" || contenedor[i] == "D" || contenedor[i] == "E" || contenedor[i] == "F" ||
				contenedor[i] == "G" || contenedor[i] == "H" || contenedor[i] == "I" || contenedor[i] == "J" || contenedor[i] == "K" || contenedor[i] == "L" ||
				contenedor[i] == "M" || contenedor[i] == "N" || contenedor[i] == "O" || contenedor[i] == "P" || contenedor[i] == "Q" || contenedor[i] == "R" || 
				contenedor[i] == "S" || contenedor[i] == "T" || contenedor[i] == "U" || contenedor[i] == "V" || contenedor[i] == "W" || contenedor[i] == "X" || 
				contenedor[i] == "Y" || contenedor[i] == "Z"){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es un ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "caracter ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //rojo
                cout << " NO RECONOCIDO \n";
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

