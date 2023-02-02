/*
    
    Andres Martinez
    Diego Vargas
    Kevin Navarro
    
    8/11/22
    Practica de Analisis Lexico 07
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
bool validarExpAr(const string& );
bool validarExpRel(const string& );
bool validare1(const string& );
bool validare2(const string& );
bool validare3(const string& );
bool validare4(const string& );
bool validare5(const string& );
bool validare6(const string& );
bool validare7(const string& );
bool validare8(const string& );
bool validare9(const string& );
bool validare10(const string& );

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
    while (getline(cin,input)) {
        if ( input == "ESC" || input == "Esc" || input == "esc" ) {
            break;
        }
		else{
			fflush(stdin);
			contenedor.push_back( input );
		}
    }
	
	//comparamos la cadena del final al principio del vector
    sort( contenedor.begin() , contenedor.end() );  
	system("cls");
	if(remove("ra.txt")==0) 
        printf("El archivo de salida fue reescrito \n");
    else
        printf("Creando archivo de salida\n");
	
	ofstream salida;
	string NombreSalida="ra.txt";
	salida.open(NombreSalida.c_str(),ios::out); //Creamos el archivo
	salida <<"Resultado de Analisis "<<endl;
	
	
	
	if(remove("tabla-simb.txt")==0) 
        printf("La tabla de simbolos fue reescrita \n");
    else
        printf("Creando tabla de simbolos\n");
        Sleep(10);
	
	ofstream tabla;
	string NombreTabla="tabla-simb.txt";
	tabla.open(NombreTabla.c_str(),ios::out);
	tabla<<"Registro de Simbolos"<<endl;
	
	
	if(remove("Manejo-err.txt")==0) 
        printf("El registro de errores fue reescrito \n");
    else
        printf("Creando registro de errores\n");
        Sleep(10);
        
	ofstream manejo;
	string NombreManejo="Manejo-err.txt";
	manejo.open(NombreManejo.c_str(),ios::out);
	manejo<<"Errores Detectados"<<endl;
	
	
	
    //recorremenos el vector
    for ( int i = 0; i < contenedor.size(); ++i ) {
    	
    	cout << "\n\n\n";
    	
		fflush(stdin);
		 if (validarLetra(contenedor[i])){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Blanco
                cout << " letra :";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Azul
                cout << " " << contenedor[i];
                salida <<"Letra: "<< contenedor[i]<<endl;
            } 
            else if (validarNumero(contenedor[i])){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Blanco
                cout << " digito :";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Azul
                cout << " " << contenedor[i]<<endl;
                salida <<"Digito: "<< contenedor[i]<<endl;
            }else if (validarOperadorMatematico(contenedor[i])){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Blanco
                cout << " o_aritmetico :";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Azul
                cout << " " << contenedor[i]<<endl;
                salida <<"o_aritmetico: "<< contenedor[i]<<endl;
                tabla<<"o_aritmetico: "<<contenedor[i]<<endl;
            }else if (validarEspecial(contenedor[i])){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Blanco
                cout << " especial :";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Azul
                cout << " " << contenedor[i]<<endl;
                salida <<"Especial: "<< contenedor[i]<<endl;
            }else if (validarOperadorRelacional(contenedor[i])){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Blanco
                cout << " o_relacion :";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Azul
                cout << " " << contenedor[i]<<endl;
                salida <<"o_relacion: "<< contenedor[i]<<endl;
                tabla<<"o_relacion: "<<contenedor[i]<<endl;
            }else if (validarPalabraReservada(contenedor[i])){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Blanco
                cout << " p_reservada :";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Azul
                cout << " " << contenedor[i]<<endl;
                salida <<"p_reservada: "<< contenedor[i]<<endl;
            }else if (validarTipoVariable(contenedor[i])){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Blanco
                cout << " variable :";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Azul
                cout << " " << contenedor[i]<<endl;
                salida <<"Variable: "<< contenedor[i]<<endl;
                tabla<<"variable: "<<contenedor[i]<<endl;
            }else if (validarExpRel(contenedor[i])){

						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Blanco
                cout << " exp_rel :";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Azul
                cout << " " << contenedor[i]<<endl;
                salida <<"exp_rel: "<< contenedor[i]<<endl;
			}else if (validarExpAr(contenedor[i])){
                    
					
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Blanco
               			cout << " exp_ar :";
               			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Azul
                		cout << " " << contenedor[i]<<endl;
                		salida <<"exp_ar: "<< contenedor[i]<<endl;
		
			}else if(validare1(contenedor[i])){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //Rojo
                        cout << " ERROR E1 DETECTADO (MAYUSCULA): ";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                		cout << " " << contenedor[i]<<endl;
                		manejo<<"ERROR E1 DETECTADO (MAYUSCULA): "<<contenedor[i]<<endl;
				
			}else if(validare2(contenedor[i])){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //Rojo
                        cout << " ERROR E2 DETECTADO (SIMBOLOS NO RECONOCIDOS): ";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                		cout << " " << contenedor[i]<<endl;
                		manejo<<"ERROR E2 DETECTADO (SIMBOLOS NO RECONOCIDOS): "<<contenedor[i]<<endl;
			}else if(validare3(contenedor[i])){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //Rojo
                        cout << " ERROR E3 DETECTADO (Dos o mas digitos ingresados al mismo tiempo):";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                		cout << " " << contenedor[i]<<endl;
                		manejo<<"ERRROR E3 DETECTADO (Dos o mas digitos ingresados al mismo tiempo): "<<contenedor[i]<<endl;
			}else if(validare4(contenedor[i])){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //Rojo
                      cout << " ERROR E4 DETECTADO (Dos o mas letras ingresadas al mismo tiempo):";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                		cout << " " << contenedor[i]<<endl;
                		manejo<<"ERRROR E4 DETECTADO (Dos o mas letras ingresadas al mismo tiempo): "<<contenedor[i]<<endl;
			}else if(validare5(contenedor[i])){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //Rojo
                        cout << " ERROR E5 DETECTADO (Dos o mas caracteres especiales ingresados al mismo tiempo):";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                		cout << " " << contenedor[i]<<endl;
                		manejo<<"ERRROR E5 DETECTADO (Dos o mas caracteres especiales ingresados al mismo tiempo): "<<contenedor[i]<<endl;
			}else if(validare6(contenedor[i])){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //Rojo
                       cout << " ERROR E6 DETECTADO (Dos o mas operadores relacionales ingresados al mismo tiempo):";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                		cout << " " << contenedor[i]<<endl;
                		manejo<<"ERRROR E6 DETECTADO (Dos o mas operadodres relacionales ingresados al mismo tiempo): "<<contenedor[i]<<endl;
			}else if(validare7(contenedor[i])){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //Rojo
                       cout << " ERROR E7 DETECTADO (Dos o mas operadores aritmeticos ingresados al mismo tiempo):";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                		cout << " " << contenedor[i]<<endl;
                		manejo<<"ERRROR E7 DETECTADO (Dos o mas operadores aritmeticos  ingresados al mismo tiempo): "<<contenedor[i]<<endl;
			}else if(validare8(contenedor[i])){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //Rojo
                        cout << " ERROR E8 DETECTADO (Variable sin letra Mayuscula al principio): ";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                		cout << " " << contenedor[i]<<endl;
                		manejo<<"ERRROR E8 DETECTADO (Varibale sin letra Mayuscula al principio): "<<contenedor[i]<<endl;
			}else if(validare9(contenedor[i])){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //Rojo
                        cout << " ERROR E9 DETECTADO (Variable sin digito en la segunda posicion): ";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                		cout << " " << contenedor[i]<<endl;
                		manejo<<"ERROR E9 DETECTADO (VARIABLE sin digito en la segunda posicion):" <<contenedor[i]<<endl;
			}else if(validare10(contenedor[i])){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //Rojo
                        cout << " ERROR E10 DETECTADO (Variable sin punto al final): ";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                		cout << " " << contenedor[i]<<endl;
                		manejo<<"ERROR E10 DETECTADO (Variable sin punto al final): "<<contenedor[i]<<endl;
			}
			
			else{
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                cout << " NO ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //rojo
                cout << "VALIDO\n";
                salida <<"No valido: "<< contenedor[i]<<endl;
                manejo<<"No valido: "<<contenedor[i]<<endl;
            }
	 			
    }
	    
	    fflush(stdin);
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	     cout<<"\nFIN. \n\n Ingrese otra opcion del menu para continuar o ingrese ESC para salir.\n\n";//aviso
	    
	     system("pause");
	     system("cls");
	     contenedor.clear();
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



bool validarTipoVariable(const string& contenedor){

    regex tipoVariable{"([A-Z][0-9]([a-z0-9]){1,8}\\.)"};
    return regex_match(contenedor,tipoVariable);



}

bool validarExpAr(const string& contenedor){

    regex lexar1{"((([A-Z][0-9]([a-z0-9]){1,8}\\.)|(\\d))\\s([+|-|*|/])\\s(([A-Z][0-9]([a-z0-9]){1,8}\\.)*|(\\d)*))\\."};
    return regex_match(contenedor,lexar1);



}

bool validarExpRel(const string& contenedor){

    regex lexrel1{"((([A-Z][0-9]([a-z0-9]){1,8}\\.)|(\\d))\\s([<|>|=|/])\\s(([A-Z][0-9]([a-z0-9]){1,8}\\.)*|(\\d)*))\\."};
    return regex_match(contenedor,lexrel1);



}

bool validare1(const string& contenedor){
	regex e1{"([A-Z]+)"};
	return regex_match(contenedor,e1);
};
bool validare2(const string& contenedor){
	regex e2{"(([$%&'@^´])+)"};
	return regex_match(contenedor,e2);
};
bool validare3(const string& contenedor){
	regex e3{"(\\d(\\d)+)"};
	return regex_match(contenedor,e3);
};
bool validare4(const string& contenedor){
	regex e4{"(\\w(\\w)+)"};
	return regex_match(contenedor,e4);
};
bool validare5(const string& contenedor){
	regex e5{"(([.|,|;|(|)|_|!])(([.|,|;|(|)|_|!]))+)"};
	return regex_match(contenedor,e5);
};
bool validare6(const string& contenedor){
	regex e6{"(([<|>|=|/])([<|>|=|/])+)"};
	return regex_match(contenedor,e6);
};
bool validare7(const string& contenedor){
	regex e7{"(([+|-|*|/])([+|-|*|/])+)"};
	return regex_match(contenedor,e7);
};
bool validare8(const string& contenedor){
	regex e8{"([a-z][0-9]([a-z0-9]){1,8}\\.)"};
	return regex_match(contenedor,e8);
};
bool validare9(const string& contenedor){
	regex e9{"([A-Z][\\D]?([a-z0-9]){1,8}\\.)"};
	return regex_match(contenedor,e9);
};
bool validare10(const string& contenedor){
	regex e10{"([A-Z][0-9]([a-z0-9]){1,8})"};
	return regex_match(contenedor,e10);
};

void lectura(){
	using namespace std;
	regex lextra{"([a-z])"};
regex lexmero{"([0-9])"};
regex lexpecial{"([.|,|;|(|)|_|!])"};
regex lexmetico{"([+|-|*|/])"};
regex lexcion{"([<|>|=|/])"};
regex lexservada{"(si|no|repite|ir|mientras|para|hacer|esto|resultado|termina|inicio|principal|todo|con)"};
regex lexicador{"([A-Z][0-9]([a-z0-9]){1,8}\\.)"};	
regex lexar{"((([A-Z][0-9]([a-z0-9]){1,8}\\.)|(\\d))\\s([+|-|*|/])\\s(([A-Z][0-9]([a-z0-9]){1,8}\\.)*|(\\d)*))\\."};
regex lexrel{"((([A-Z][0-9]([a-z0-9]){1,8}\\.)|(\\d))\\s([<|>|=|/])\\s(([A-Z][0-9]([a-z0-9]){1,8}\\.)*|(\\d)*))\\."};
//reconocer ERRORES
regex e1{"([A-Z]+)"};
regex e2{"(([$%&'@^´])+)"};
regex e3{"(\\d(\\d)+)"};
regex e4{"(\\w(\\w)+)"};
regex e5{"(([.|,|;|(|)|_|!])(([.|,|;|(|)|_|!]))+)"};
regex e6{"(([<|>|=|/])([<|>|=|/])+)"};
regex e7{"(([+|-|*|/])([+|-|*|/])+)"};
regex e8{"([a-z][0-9]([a-z0-9]){1,8}\\.)"};
regex e9{"([A-Z][\\D]?([a-z0-9]){1,8}\\.)"};
regex e10{"([A-Z][0-9]([a-z0-9]){1,8})"};
//	
	
	
	
	ifstream archivo;
	string nombreArchivo,texto;
	
	
	cout<<"\n Digite el nombre o la ubicacion del archivo o fichero: ";
	getline(cin,nombreArchivo);
	
	archivo.open(nombreArchivo.c_str(),ios::in); //Abrimos el archivo en modo lectura
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	if(remove("ra.txt")==0) 
        printf("El archivo de salida fue reescrito \n");
    else
        printf("Creando archivo de salida\n");
        Sleep(10);
	
	ofstream salida;
	string NombreSalida="ra.txt";
	salida.open(NombreSalida.c_str(),ios::out); //Creamos el archivo
	salida <<"Resultado de Analisis "<<endl;
	
	if(remove("Manejo-err.txt")==0) 
        printf("El registro de errores fue reescrito \n");
    else
        printf("Creando registro de errores\n");
        Sleep(10);
        
	ofstream manejo;
	string NombreManejo="Manejo-err.txt";
	manejo.open(NombreManejo.c_str(),ios::out);
	manejo<<"Errores Detectados"<<endl;
	
		if(remove("tabla-simb.txt")==0) 
        printf("La tabla de simbolos fue reescrita \n");
    else
        printf("Creando tabla de simbolos\n");
        Sleep(10);
	
	ofstream tabla;
	string NombreTabla="tabla-simb.txt";
	tabla.open(NombreTabla.c_str(),ios::out);
	tabla<<"Registro de Simbolos"<<endl;
	
	while(!archivo.eof()){ //mientras no sea final del archivo
		getline(archivo,texto);
		
		
            fflush(stdin);	//Se hace un vaciado de la memoria para que no contenga basura
            /*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
            
            
            
			if (regex_match(texto,lextra))  //Verifica si el Caracter es una letra. (de a-z o A-Z)
            {

                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Azul
                cout << " letra : ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Verde
                cout << texto <<endl;
                salida <<"Letra: "<< texto<<endl;

            } else if (regex_match(texto,lexmero))    //Verifica si el Caracter es un número. (de 0-9)
                {
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Azul
                cout << " digito : ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Verde
                cout << texto <<endl;
                salida <<"Digito: "<< texto<<endl;
                
                } else if (regex_match(texto,lexpecial)) //Verifica si el Caracter es un Caracter Especial. ( . , ; ( ) - _ ! )
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Azul
                		cout << " especial : ";
               			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Verde
                		cout << texto<<endl ;
                		salida <<"Especial: " <<texto<<endl;
                		
                    } else if (regex_match(texto,lexmetico))   
                        //Verifica si el Caracter es un Operador Aritmetico. ( =  + - * / )
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Azul
                		cout << " o_aritmetico : ";
                		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Verde
               			cout << texto<<endl;
               			salida <<"o_aritemtico: " <<texto<<endl;
               			tabla<<"o_aritmetico: "<<texto<<endl;
                    } else if (regex_match(texto,lexcion))   
                        //Verifica si el Caracter es un Operador de Relacion. ( < > = )
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Azul
                		cout << " o_relacion : ";
               			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Verde
                		cout << texto<<endl;
                		salida <<"o_relacion: "<< texto<<endl;
                		tabla<<"o_relacion: "<<texto<<endl;
                		
                    }else if (regex_match(texto,lexservada))    
                    //Verifica si el Es una Palabra Reservada.
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Azul
                		cout << " p_reservada : ";
               			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Verde
               			cout << texto<<endl;
               			salida <<"p_reservada: " <<texto<<endl;
               			
                    }
					else if (regex_match(texto,lexicador))
                    {
                      
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Azul
                					cout << " variable : ";
                					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Verde
                					cout << texto<<endl;
                                    salida <<"variable: " <<texto<<endl;
                                    tabla<<"variable: "<<texto<<endl;
                            
                    }
                        else if (regex_match(texto,lexrel)){
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                        cout << " exp_rel ";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                		cout << " " << texto<<endl;
                		salida <<"exp_rel: "<< texto<<endl;
					}


                       else if (regex_match(texto,lexar)){
                    
					
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                        cout << " exp_ar ";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                		cout << " " << texto<<endl;
                    	salida <<"exp_ar: "<< texto<<endl;
                    	
					}
					//ERRORES
                   else if(regex_match(texto,e1)){
                   	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //Rojo
                        cout << " ERROR E1 DETECTADO (MAYUSCULA): ";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                		cout << " " << texto<<endl;
                		manejo<<"ERROR E1 DETECTADO (MAYUSCULA): "<<texto<<endl;
				   }					
				   else if(regex_match(texto,e2)){
                   	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //Rojo
                        cout << " ERROR E2 DETECTADO (SIMBOLOS NO RECONOCIDOS): ";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                		cout << " " << texto<<endl;
                		manejo<<"ERROR E2 DETECTADO (SIMBOLOS NO RECONOCIDOS): "<<texto<<endl;
				   }
				   else if(regex_match(texto,e3)){
                   	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //Rojo
                        cout << " ERROR E3 DETECTADO (Dos o mas digitos ingresados al mismo tiempo):";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                		cout << " " << texto<<endl;
                		manejo<<"ERRROR E3 DETECTADO (Dos o mas digitos ingresados al mismo tiempo): "<<texto<<endl;
				   }
				   else if(regex_match(texto,e4)){
                   	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //Rojo
                      cout << " ERROR E4 DETECTADO (Dos o mas letras ingresadas al mismo tiempo):";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                		cout << " " << texto<<endl;
                		manejo<<"ERRROR E4 DETECTADO (Dos o mas letras ingresadas al mismo tiempo): "<<texto<<endl;
                		
				   }
				   else if(regex_match(texto,e5)){
                   	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //Rojo
                        cout << " ERROR E5 DETECTADO (Dos o mas caracteres especiales ingresados al mismo tiempo):";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                		cout << " " << texto<<endl;
                		manejo<<"ERRROR E5 DETECTADO (Dos o mas caracteres especiales ingresados al mismo tiempo): "<<texto<<endl;
				   }
				   else if(regex_match(texto,e6)){
                   	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //Rojo
                       cout << " ERROR E6 DETECTADO (Dos o mas operadores relacionales ingresados al mismo tiempo):";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                		cout << " " << texto<<endl;
                		manejo<<"ERRROR E6 DETECTADO (Dos o mas operadodres relacionales ingresados al mismo tiempo): "<<texto<<endl;
				   }
				   else if(regex_match(texto,e7)){
                   	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //Rojo
                       cout << " ERROR E7 DETECTADO (Dos o mas operadores aritmeticos ingresados al mismo tiempo):";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                		cout << " " << texto<<endl;
                		manejo<<"ERRROR E7 DETECTADO (Dos o mas operadores aritmeticos  ingresados al mismo tiempo): "<<texto<<endl;
				   }
				   else if(regex_match(texto,e8)){
                   	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //Rojo
                        cout << " ERROR E8 DETECTADO (Variable sin letra Mayuscula al principio): ";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                		cout << " " << texto<<endl;
                		manejo<<"ERRROR E8 DETECTADO (Varibale sin letra Mayuscula al principio): "<<texto<<endl;
				   }
				   else if(regex_match(texto,e9)){
                   	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //Rojo
                        cout << " ERROR E9 DETECTADO (Variable sin digito en la segunda posicion): ";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                		cout << " " << texto<<endl;
                		manejo<<"ERROR E9 DETECTADO (VARIABLE sin digito en la segunda posicion):" <<texto<<endl;
				   }
				   else if(regex_match(texto,e10)){
                   	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //Rojo
                        cout << " ERROR E10 DETECTADO (Variable sin punto al final): ";
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                		cout << " " << texto<<endl;
                		manejo<<"ERROR E10 DETECTADO (Variable sin punto al final): "<<texto<<endl;
				   }
					//

            else     //Si el caracter es invalido, entonces se ejecuta este bloque de instruccion.
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << texto;
                cout << " NO ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //rojo
                cout << "VALIDO\n";
                salida <<"NO VALIDO: "<< texto<<endl;
                manejo<<"NO VALIDO: "<<texto<<endl;
            }
            /*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
        
		
		
		
	}
	
	archivo.close(); //Cerramos el archivo
	
}
