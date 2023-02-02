/*
    Kevin Navarro
    Andres Martinez
    Diego Vargas
    18/10/22
    Practica de Analisis Lexico 04
*/

#include <iostream>
#include <vector>
#include <windows.h>
#include <clocale>
#include <regex>
#include <conio.h>
#include<fstream>



#define F1  -59
#define F2  -60
#define ESC 27
using namespace std;


bool validarLetra(const string& ); 
bool validarNumero(const string& ); 
bool validarOperadorMatematico(const string& ); 
bool validarEspecial(const string& ); 
bool validarOperadorRelacional(const string& ); 
bool validarPalabraReservada(const string& ); 
bool validarMayuscula(const string& ); 
bool validarTipoVariable(const string& ); 
void lectura();

int main(){
		setlocale(LC_CTYPE, "Spanish");
    string input;
    int key = 0;//se define que key vale 0
    vector< string > contenedor;
    bool mayus = false, digito = false, dot = false; 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); //Morado 	Se definen colores 
        
        cout << "\n\n\n\t\t\t\t      A N A L I S I S  L E X I C O\n";	//Nombre del programa ("nombre de la practica")
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
        cout<< "\n\n\t\t\t\t\t F1-Leer desde archivo\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
        cout<< "\n\n\t\t\t\t\t F2-Ingresar desde consola\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
        cout<< "\n\n\t\t\t\t\t ESC-Salir\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
        cout<< "\n\n\n\n  Ingresa la opcion a ejecutar: ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
            while(key != ESC)//mientras que la tecla ingresada sea diferente a ESC se ejecutara lo siguiente
    {
        key = getch();//se obtiene el valor ingresado de key
        if(key == 0)
            key = -getch();
        switch(key)//inicio de switch con el valor de key
        {
        case F1: { //inicio del primer case
           SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout<< "\n\n\t\t\t\tLeer desde archivo\n\n";
            lectura();
			system("pause");//se pausa el programa hasta que se ingrese otra tecla
	    system("cls");//se limpia la pantalla
	 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);   
    cout<<"\nFIN. Ingrese otra opcion del menu para continuar o ingrese ESC para salir.\n";//aviso
    
    cout << "\n\n\n\t\t\t\t      A N A L I S I S  L E X I C O\n";	//Nombre del programa ("nombre de la practica")
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
        cout<< "\n\n\t\t\t\t\t F1-Leer desde archivo\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
        cout<< "\n\n\t\t\t\t\t F2-Ingresar desde consola\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
        cout<< "\n\n\t\t\t\t\t ESC-Salir\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
        cout<< "\n\n\n\n  Ingresa la opcion a ejecutar: ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
        
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	    
	    
		}
            break;//fin de primer case
        case F2://inicio de segundo case F2
        	{
        		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        		cout<< "\n\n\t\t\t\tLeer desde consola:\n\n";
         
        		system("pause");//se pausa el programa hasta que se ingrese otra tecla
	    system("cls");//se limpia la pantalla
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
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
    //recorremenos el vector
    for ( int i = 0; i < contenedor.size(); ++i ) {
    	
    	cout << "\n\n\n";
		
		 if (validarLetra(contenedor[i])){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es letra ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y esta ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDA \n";
            } 
            else if (validarNumero(contenedor[i])){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es un digito ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y esta ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDO \n";
            }else if (validarOperadorMatematico(contenedor[i])){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es un operador matematico ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y esta ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDO \n";
            }else if (validarEspecial(contenedor[i])){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es un caracter especial ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y esta ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDO \n";
            }else if (validarOperadorRelacional(contenedor[i])){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es un operador relacional ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y esta ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDO \n";
            }else if (validarPalabraReservada(contenedor[i])){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es una palabra reservada ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y esta ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDA \n";
            }else if (validarTipoVariable(contenedor[i])){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es una variable ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y esta ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDA \n";
            }else if (validarMayuscula(contenedor[i])){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es una MAYUSCULA ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y esta ";
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
	    
	    
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	     cout<<"\nFIN. \n\n Ingrese otra opcion del menu para continuar o ingrese ESC para salir.\n\n";//aviso
	    
	     system("pause");
	     system("cls");
	     
	     cout << "\n\n\n\t\t\t\t      A N A L I S I S  L E X I C O\n";	//Nombre del programa ("nombre de la practica")
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
        cout<< "\n\n\t\t\t\t\t F1-Leer desde archivo\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
        cout<< "\n\n\t\t\t\t\t F2-Ingresar desde consola\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
        cout<< "\n\n\t\t\t\t\t ESC-Salir\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
        cout<< "\n\n\n\n  Ingresa la opcion a ejecutar: ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
	     
	    
			}
          
            break;//fin del segundo case
        
       
		    
        default://default por si no se ingresa ninguna opcion del menu
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //Rojo
            cout<< "\n\n\t\t\t\tNo se selecciono ninguna opcion del menu:\n";
        
			
            break;//fin de default
 
        }//fin de switch
    }//fin de while
    return 0;
//fin de main
        
}

bool validarLetra(const string& contenedor){
    
    regex vall("([a-z])");
    return regex_match(contenedor,vall);   

}

bool validarNumero(const string& contenedor){

    regex numero{"([0-9])"};
    return regex_match(contenedor,numero);

}

bool validarOperadorMatematico(const string& contenedor){

    regex operadorMatematico{"([+|-|*|/])"};
     return regex_match(contenedor,operadorMatematico);
}

bool validarEspecial(const string& contenedor){

    
    regex especial{"([.,;()_!])"};
    return regex_match(contenedor,especial);
}

bool validarOperadorRelacional(const string& contenedor){

    regex operadorRelacional{"([<>=])"};
    return regex_match(contenedor,operadorRelacional);
}

bool validarPalabraReservada(const string& contenedor){

    regex palabraReservada{"(si|no|repite|ir|mientras|para|hacer|esto|resultado|termina|inicio|principal|todo|con)"};
    return regex_match(contenedor, palabraReservada);
} 

bool validarMayuscula(const string& contenedor){

    regex mayuscula{"([A-Z])"};
    return regex_match(contenedor, mayuscula);

}

bool validarTipoVariable(const string& contenedor){

    regex tipoVariable{"([A-Z][0-9]([a-z0-9]){1,8}\\.)"};
    return regex_match(contenedor,tipoVariable);



}
void lectura(){
	using namespace std;
	regex lextra{"([a-z])"};
regex lexmero{"([0-9])"};
regex lexpecial{"([.|,|;|(|)|_|!])"};
regex lexmetico{"([+|-|*|/])"};
regex lexcion{"([<|>|=|/])"};
regex lexservada{"(si|no|repite|ir|mientras|para|hacer|esto|resultado|termina|inicio|principal|todo|con)"};
regex lexicador{"([A-Z][0-9]([a-z0-9]){1,8}\\.)"};	
	
	
	
	
	ifstream archivo;
	string nombreArchivo,texto;
	
	
	cout<<"\n Digite el nombre o la ubicacion del archivo o fichero: ";
	getline(cin,nombreArchivo);
	
	archivo.open(nombreArchivo.c_str(),ios::in); //Abrimos el archivo en modo lectura
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	while(!archivo.eof()){ //mientras no sea final del archivo
		getline(archivo,texto);
		
		
            fflush(stdin);	//Se hace un vaciado de la memoria para que no contenga basura
            /*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
            if (regex_match(texto,lextra))  //Verifica si el Caracter es una letra. (de a-z o A-Z)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << texto;
                 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es letra ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y esta ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDA \n";

            } else if (regex_match(texto,lexmero))    //Verifica si el Caracter es un número. (de 0-9)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                    cout << " " << texto;
                     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " Es un digito ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y esta ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDO \n"; 
                } else if (regex_match(texto,lexpecial)) //Verifica si el Caracter es un Caracter Especial. ( . , ; ( ) - _ ! )
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                        cout << " " << texto;
                       SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " Es un caracter especial ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y esta ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDO \n";
                    } else if (regex_match(texto,lexmetico))   
                        //Verifica si el Caracter es un Operador Aritmetico. ( =  + - * / )
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                        cout << " " << texto;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " Es un operador matematico ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y esta ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDO \n";
                    } else if (regex_match(texto,lexcion))   
                        //Verifica si el Caracter es un Operador de Relacion. ( < > = )
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                        cout << " " << texto;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es un operador relacional ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y esta";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDO \n";
                    }else if (regex_match(texto,lexservada))    
                    //Verifica si el Es una Palabra Reservada.
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                        cout << " " << texto;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es una palabra reservada ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y esta ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDA \n";
                    }
					else if (regex_match(texto,lexicador))
                    {
                      
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                                    cout << " " << texto;
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es una variable ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y esta ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDA \n";
                              
                            
                    }

            else     //Si el caracter es invalido, entonces se ejecuta este bloque de instruccion.
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << texto;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //Rojo
                printf(" NO ");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                printf("esta ");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); //Gris
                printf("RECONOCIDO\n");
            }
            /*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
        
		
		
		
	}
	
	archivo.close(); //Cerramos el archivo
}

