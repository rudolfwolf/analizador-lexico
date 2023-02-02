#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <clocale>
#include <cstring>
using namespace std;

void checkpassword(string input[100]) ;

int main (){

	
	
	string input;
	setlocale(LC_CTYPE, "Spanish");
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
        cin >> input; 
    /*while ( cin >> input ) {
        if ( input == "esc" || input == "Esc" || input == "esc" ) {
            break;
        
    }*/
    checkpassword(input);
		   
	
	return 0;
}


void checkpassword(string input) 
{ 

	
	system("cls");
    cout << "\n Introdujiste:\n";      
  	
    for (int i = 0; i < 100; i++) { 
     
     if (input[i] >= "a" &&  input[i] <= "z"){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << input[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es letra ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y está ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDA \n";
            }else if(input[i] == "<"|| input[i] == ">" || input[i] == "="){
    		    
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << input[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es operador relacional ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y está ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDO \n";		
			}else if(input[i]=="0"|| input[i]=="1"|| input[i]=="2"|| input[i]=="3"|| 
					 input[i]=="4"|| input[i]=="5"|| input[i]=="6"|| input[i]=="7"|| 
					 input[i]=="8"|| input[i]=="9"){
    		    
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco  
                cout <<" " << input[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es dígito ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y está ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDO \n";		
		}else if(input[i]=="-" || input[i]=="+"|| input[i]=="*" || input[i]=="/"){
				
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout<< " " << input[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout<< " es operador aritmético ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout<< "y está ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout<< "RECONOCIDO \n";		
		}else if(input[i]=="."|| input[i]== "," || input[i]==";" || input[i]== "_" || input[i]== "!" || 
		input[i]== "["|| input[i]=="]"|| input[i]=="("|| input[i]==")"|| input[i]=="{" || input[i]=="}"){
    		 	
				 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout<< " " << input[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout<< " es caracter especial ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout<< "y está ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout<< "RECONOCIDO \n";
		}else if(input[i]= "si"|| input[i]=="no"|| input[i]=="repite"|| input[i]=="ir"|| input[i]=="mientras"|| input[i]=="para"
					|| input[i]=="hacer"|| input[i]== "esto"|| input[i]=="resultado"|| input[i]=="termina"|| input[i]=="inicio"
					|| input[i]=="principal"|| input[i]=="todo"|| input[i]=="con"){
		
		 		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout<< " " << input[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout<< " es palabra reservada ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout<< "y está ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout<< "RECONOCIDA \n";
		}else if (input[i] >= "A" &&  input[i] <= "Z"){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << input[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es un ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "caracter ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //rojo
                cout << " NO RECONOCIDO \n";
            }else{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << input[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es un ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "caracter/palabra ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //rojo
                cout << " NO RECONOCIDO \n";
		}
        
    } 
    
}
