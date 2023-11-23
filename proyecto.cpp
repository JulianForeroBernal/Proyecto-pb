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
using namespace std;

struct LIB{
	string covu;
	int desti;
	double mes;
	double dia;
	double ano;
	double sturi;
	double sejecu;
	double cturi;
	double cejecu;
	double cadma;
}libro;

bool vanum(double& x);  //validacion si no llega a ser un número

int main(){	
    setlocale(LC_ALL, "spanish");
    double a,b,c,d,e,f,g;
	//Ingreso
    cout<<"Hola trabajador, a continuacion ingresa los datos de los vuelos"<<endl;
    system("PAUSE");
    system("cls");
    //COD Vuelo
	cout<<"Ingresa el Codigo de vúelo: "<<endl;
	cin>> libro.covu;
	//Destino
	cout<<"Este codigo que destino tiene: Selecciona una opcion (1-2-3) "<<endl;
	cout<<"[1] París (Francia) "<<endl;
	cout<<"[2] Yakarta (Indonesia) "<<endl;
	cout<<"[3] El Cairo (Egipto) "<<endl;
	if (vanum(a)) {      //VALIDACION LETRA
        libro.desti=a;
        while(libro.desti<1 or libro.desti>3){
		cout<<"Por favor ingresa una entrada valida 1-2-3 "<<endl;
		cin>>libro.desti;
		}
    } else {
        cout << "Algo salió mal en la validación." << endl;
    }
	//Fecha
	cout<<"Ingresa la fecha de partida "<<endl;
	system("PAUSE");
	cout<<"Año: ";
	cin>>libro.ano;
	while(libro.ano<2023 or libro.ano>2026){    //Validacion de año
		cout<<"Por favor ingresa una entrada valida "<<endl;
		cin>>libro.ano;
	}
	cout<<"Mes (1-12): ";
	cin>>libro.mes;
	while(libro.mes<1 or libro.mes>12){        //Validacion de mes
		cout<<"Por favor ingresa una entrada valida 1-12 "<<endl;
		cin>>libro.mes;
	}
	if(libro.ano==2023){
		while(libro.mes<11){				  //Validacion de mes actual en el año
			cout<<"Por favor ingresa un valor real para este año: "<<endl;
			cin>>libro.mes;
		}
	}
	cout<<"Día: ";
	cin>>libro.dia;							 //Validacion de días de cada mes
	if(libro.mes==11 or libro.mes==4 or libro.mes==6 or libro.mes==9){
		while(libro.dia<1 or libro.dia>30){
			cout<<"Este mes no tiene ese día, ingresa otro de nuevo: "<<endl;
			cin>>libro.dia;
		}
	}									
	if(libro.mes==12 or libro.mes==1 or libro.mes==3 or libro.mes==5 or libro.mes==7 or libro.mes==8 or libro.mes==10){
		while(libro.dia<1 or libro.dia>31){
			cout<<"Este mes no tiene ese día, ingresa otro de nuevo: "<<endl;
			cin>>libro.dia;
		}
	}
	if(libro.mes==2){
		while(libro.dia<1 or libro.dia>28){
			cout<<"Este mes no tiene ese día, ingresa otro de nuevo: "<<endl;
			cin>>libro.dia;
		}
	}
	if(libro.ano==2023){                //Validacion de dia en este mes y año
		if(libro.mes==11){
			while((libro.dia<27)){
			cout<<"Por favor ingresa un valor real para este mes: "<<endl;
			cin>>libro.dia;
			}
		}
	}
	
	//Cant. sillas
	cout<<"Ingresa la cantidad de sillas disponibles para clase turista: "<<endl;
	cin>>libro.sturi;
	while(libro.sturi<0 or libro.sturi>550){
		cout<<"Por favor ingresa una entrada valida "<<endl;
		cin>>libro.sturi;
		}
	cout<<"Ingresa la cantidad de sillas disponibles para clase ejecutiva: "<<endl;
	cin>>libro.sejecu;
	while(libro.sejecu<0 or libro.sejecu>550){
		cout<<"Por favor ingresa una entrada valida "<<endl;
		cin>>libro.sejecu;
		}
	//Costo sillas
	cout<<"Ingresa el costo de sillas para clase turista: "<<endl;
	cin>>libro.cturi;
	while(libro.cturi<0){
		cout<<"Por favor ingresa una entrada valida "<<endl;
		cin>>libro.cturi;
		}
	cout<<"Ingresa el costo de sillas para clase ejecutiva: "<<endl;
	cin>>libro.cejecu;
	while(libro.cejecu<0){
		cout<<"Por favor ingresa una entrada valida "<<endl;
		cin>>libro.cejecu;
		}
	//Costo maleta adicional
	cout<<"Ingresa el costo adicional de UND. Maleta adicional: "<<endl;
	cin>>libro.cadma;
	while(libro.cadma<0){
		cout<<"Por favor ingresa una entrada valida "<<endl;
		cin>>libro.cadma;
		}

}

//FUNCIONES

bool vanum(double& x){   //Funcion para validad que no sean letras
	while(true){
		if (cin>>x && cin.peek() == '\n'){
			return true;
		}else{
			cout<<"Error, ingresa números por favor"<<endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
		}	
	}
}