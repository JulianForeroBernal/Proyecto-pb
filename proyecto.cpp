/*
Proyecto
Autores 
Joan Duran 20232020019
Julian Forero 20232020030
*/

#include <iostream>
#include <locale.h>
#include <limits>
#include <stdio.h>
#include <string>
#include <cmath>

using namespace std;

struct LIB{
	string covu;
	int desti;
	double year;
	double mes;
	double dia;
	double sturi;
	double sejecu;
	double cturi;
	double cejecu;
	double cadma;
};

bool vanum(double& x);  //validacion si no llega a ser un número
bool vatrun(double& x); //validacion si no llega a ser un número truncado

int main(){	
    setlocale(LC_ALL, "spanish");
    double a,b,c,d,e,f,g,h,i;      //Variables aux. antes de ser las de la estructura
    
    const int maxvuelo = 1000; // Cambia este valor según tus necesidades
    LIB libro[maxvuelo];
    int contvuelo = 0;
    
    string confirmacion;
    do{
    	//Ingreso
    	fflush(stdin);
	    cout<<"Hola trabajador, a continuacion ingresa los datos de los vuelos"<<endl;
	    system("PAUSE");
	    system("cls");
	    //COD Vuelo
		cout<<"Ingresa el Codigo de vúelo: "<<endl;
		getline(cin,libro[contvuelo].covu);
		//Destino
		cout<<"Este codigo que destino tiene: Selecciona una opcion (1-2-3) "<<endl; //a
		cout<<"[1] París (Francia) "<<endl;
		cout<<"[2] Yakarta (Indonesia) "<<endl;
		cout<<"[3] El Cairo (Egipto) "<<endl;
		cin>>a;
		if (vanum(a)) {      //VALIDACION LETRA 
			while(vatrun(a) == false or a<1 or a>3){
				cout<<"Por favor ingresa un número de las opciones "<<endl;
				cin>>a;	
			}
	    } else {
	        cout << "Algo salió mal en la validación." << endl;
	    }
	    libro[contvuelo].desti=a;
	    
		//Fecha
		cout<<"Ingresa la fecha de partida "<<endl;
		system("PAUSE");
		cout<<"Año: ";       //b
		cin>>b;
		if (vanum(b)){      //VALIDACION LETRA
			while(vatrun(b) == false or b<2023 or b>2026){
				cout<<"Por favor ingresa una entrada valida "<<endl;
				cin>>b;	
			}
	    }else {
	        cout << "Algo salió mal en la validación." << endl;
	    }
		libro[contvuelo].year=b;
			
		cout<<"Mes (1-12): ";
		cin>>c;
		if (vanum(c)) {      //VALIDACION MES 
			while(vatrun(c) == false or c<1 or c>12){
			cout<<"Por favor ingresa una entrada valida 1-12 "<<endl;
				cin>>c;	
			}
			if(libro[contvuelo].year==2023){
				while(c<11){				  //Validacion de mes actual en el año
					cout<<"Por favor ingresa un valor real para este año: "<<endl;
					cin>>c;
				}
			}	
	    }else {
	        cout << "Algo salió mal en la validación." << endl;
	    }
	    libro[contvuelo].mes=c;
		
		cout<<"Día: ";                     //d
		cin>>d;							   //Validacion de días de cada mes
		if (vanum(d)) {                    //VALIDACION MES 
			while(vatrun(d) == false){
			cout<<"Por favor ingresa una entrada valida "<<endl;
				cin>>d;	
			}
			if(libro[contvuelo].mes==11 or libro[contvuelo].mes==4 or libro[contvuelo].mes==6 or libro[contvuelo].mes==9){
				while(d<1 or d>30){
					cout<<"Este mes no tiene ese día, ingresa otro de nuevo: "<<endl;
					cin>>d;
				}
			}									
			if(libro[contvuelo].mes==12 or libro[contvuelo].mes==1 or libro[contvuelo].mes==3 or libro[contvuelo].mes==5 or libro[contvuelo].mes==7 or libro[contvuelo].mes==8 or libro[contvuelo].mes==10){
				while(d<1 or d>31){
					cout<<"Este mes no tiene ese día, ingresa otro de nuevo: "<<endl;
					cin>>d;
				}
			}
			if(libro[contvuelo].mes==2){
				while(d<1 or d>28){
					cout<<"Este mes no tiene ese día, ingresa otro de nuevo: "<<endl;
					cin>>d;
				}
			}
			if(libro[contvuelo].year==2023){                //Validacion de dia en este mes y año
				if(libro[contvuelo].mes==11){
					while((d<27)){
					cout<<"Por favor ingresa un valor real para este mes: "<<endl;
					cin>>d;
					}
				}
			}		
	    }else {
	        cout << "Algo salió mal en la validación." << endl;
	    }
		libro[contvuelo].dia=d;
		
		
		
		//Cant. sillas
		cout<<"Ingresa la cantidad de sillas disponibles para clase turista:"<<endl;  //e
		cin>>e;
		if (vanum(e)) {      //VALIDACION LETRA 
			while(e<0){
				cout<<"Por favor ingresa una entrada valida "<<endl;
				cin>>e;	
			}
	    } else {
	        cout << "Algo salió mal en la validación." << endl;
	    }
	    libro[contvuelo].sturi=e;
	    
		cout<<"Ingresa la cantidad de sillas disponibles para clase ejecutiva: "<<endl; //f
		cin>>f;
		if (vanum(f)) {      //VALIDACION LETRA 
			while(f<0){
				cout<<"Por favor ingresa una entrada valida "<<endl;
				cin>>f;	
			}
	    } else {
	        cout << "Algo salió mal en la validación." << endl;
	    }
	    libro[contvuelo].sejecu=f;
	    
		//Costo sillas
		cout<<"Ingresa el costo de sillas para clase turista: "<<endl;  //g
		cin>>g;
		if (vanum(g)) {      //VALIDACION LETRA 
			while(g<0){
				cout<<"Por favor ingresa una entrada valida "<<endl;
				cin>>g;	
			}
	    } else {
	        cout << "Algo salió mal en la validación." << endl;
	    }
	    libro[contvuelo].cturi=g;
	
		cout<<"Ingresa el costo de sillas para clase ejecutiva: "<<endl; //h
		cin>>h;
		if (vanum(h)) {      //VALIDACION LETRA 
			while(h<0){
				cout<<"Por favor ingresa una entrada valida "<<endl;
				cin>>h;	
			}
	    } else {
	        cout << "Algo salió mal en la validación." << endl;
	    }
	    libro[contvuelo].cejecu=h;
	    
		//Costo maleta adicional
		cout<<"Ingresa el costo adicional de UND. Maleta adicional: "<<endl;//i
		cin>>i;
		if (vanum(i)) {      //VALIDACION LETRA 
			while(i<0){
				cout<<"Por favor ingresa una entrada valida "<<endl;
				cin>>i;	
			}
	    } else {
	        cout << "Algo salió mal en la validación." << endl;
	    }
	    libro[contvuelo].cadma=i;
	    
		contvuelo++;
		if (contvuelo < maxvuelo) {
	            cout << "¿Desea ingresar más datos? (Ingrese '1' para salir, otra entrada para continuar): ";
	            cin >> confirmacion;
	        } else {
	            cout << "Se ha alcanzado el límite máximo de vuelos.\n";
	            break;
	        }	
	}while(confirmacion != "1");
	
	return 0;
}

//FUNCIONES

bool vanum(double& x){   //Funcion para validad que no sean letras
	while(true){
		if (x && cin.peek() == '\n'){
			return true;
		}else{
			cout<<"Error, ingresa números por favor"<<endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}	
	}
}
bool vatrun(double& x){ //Funcion para validar que sean enteros
	double y;
	y=trunc(x);
	return y==x;
}