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
#include <fstream>
#include <cctype>
#include <cstring>
#include <iomanip>

using namespace std;


const int maxreser = 1000; // tamaño de estructura const para que no se vaya a trabar por tanta info

// ESTRUCTURA PARA LOS DATOS DE LOS VUELOS
struct LIB{ 
	string covu;    //covu es la  variable de codigo de vuelo
	double desti;   //variable de destino
	double year;    //variable de fechas
	double mes;
	double dia;
	double sturi;   //sturi pertenece a sillas turista
	double sejecu;  //sejecu pertenece a sillas ejecutivas 
	double cturi;   //costo silla turista
	double cejecu;  //costo silla ejecutiva
	double cadma;   // cadma pertenece a costo adicional de maleta
}libro[maxreser];

struct rese{ 
	string rcovu;    //covu es la  variable de codigo de vuelo
	double rdesti;   //variable de destino
	double ryear;    //variable de fechas
	double rmes;
	double rdia;
	double rcl;     //Clase
	double radul;   //Adulto 
	double rnino;   //Niño
	double rcsilla; //Costo por silla
	double radma;   // adicional de maleta
	double rcoadma;
}vuelo[maxreser];

bool vanum(double& x);  //funcion para validacion si no llega a ser un número
bool vatrun(double& x); // funcion para validacion si no llega a ser un número truncado

bool empleado(bool &joan);
bool reserva(bool &julian);



int main(){	
	setlocale(LC_ALL, "spanish");
	bool em=true;
    double a,b,c,d,e,f,g,h,i,j,k;      //Variables aux. antes de ser las de la estructura

    int contvuelo = 0;
    string confirmacion;
    int rep=1;
    
    ifstream fichero1("proyecto.txt"); // se declara fichero 1 como entrada para verificar si exite o no previamente 
    switch (fichero1.good())
    {
    case true:
        cout<<"los datos del vuelo ya existen ;)";
		fichero1.close();
        break;    
    default:
        ofstream fichero2("proyecto.txt");
        cout<<"\tHola trabajador, a continuacion ingresa los datos de los vuelos\n"<<endl;
        while(rep==1){
    		
    	    //Ingreso de datos de los vuelos
    	    fflush(stdin);
	        
		    system("PAUSE");
	        system("cls");
	        //COD Vuelo
		    cout<<"Ingresa el Codigo de vúelo: "<<endl;
		    getline(cin,libro[contvuelo].covu);
		    //Destino
		    cout<<"Este codigo que destino tiene: Selecciona una opción (1-2-3) "<<endl; //a
		    cout<<"[1] París (Francia) "<<endl;
		    cout<<"[2] Yakarta (Indonesia) "<<endl;
		    cout<<"[3] El Cairo (Egipto) "<<endl;
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
		    cout<<"\n\nIngresa la fecha de partida (puede agendar vuelos hasta el 2026)"<<endl;
		    system("PAUSE");
		    cout<<"Año: ";       //b
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
            cout<<"desea agregar otro vuelo? (presione 1 para si y cualquier otra tecla para no)";
            cin>>rep;	 
		}

        //AGREGANDO LOS DATOS DE CADA VUELO AL FICHERO
        for (int i=0;i<contvuelo;i++){
            fichero2<<libro[i].covu<<endl;
            fichero2<<libro[i].desti<<endl;
            fichero2<<libro[i].year<<endl;
            fichero2<<libro[i].mes<<endl;
            fichero2<<libro[i].dia<<endl;
            fichero2<<libro[i].sturi<<endl;
            fichero2<<libro[i].sejecu<<endl;
            fichero2<<libro[i].cturi<<endl;
            fichero2<<libro[i].cejecu<<endl;
            fichero2<<libro[i].cadma<<endl;            
        }
    } 
    
    string lugar,clase,s,codigo;
	double desti,nino,adul,cl,mal,confin;
	bool info=true;
	int contadorv = 0, x=0;
	
	while(info){
		fflush(stdin);
	    system("pause");
	    system("cls");  
	    //Destinos
	    cout<<"\n\t*********************************************************************************";
        cout<<"\n\t*BIENVENIDO AL SISTEMA DE RESERVA DE VUELOS DE AEREOLINEA EMIRATOS ARABES UNIDOS*";
        cout<<"\n\t*********************************************************************************\n";
        cout<<"\nLa aereolinea ofrece vuelos hacia: yakarta (Indonesia), Paris (Francia), El Cairo (Egipto)."<<endl; 
	    cout<<"Por favor seleccione su destino:"<<endl;
	    cout<<"[1] París (Francia) "<<endl;
		cout<<"[2] Yakarta (Indonesia) "<<endl;
	    cout<<"[3] El Cairo (Egipto) "<<endl;               
	    if (vanum(desti)) {      //VALIDACIÓN LETRA 
		    while(vatrun(desti) == false or desti<1 or desti>3){
		    	cout<<"Por favor ingresa un número de las opciones "<<endl;
				cin>>desti;	
		    }
		}else{
		    cout << "Algo salió mal en la validación." << endl;
		} 
        //Opciones de vuelo disponibles	
        system("cls"); 
		cout<<"\t***********************************************************************************"<<endl;
        cout<<"\t*                              VUELOS DISPONIBLES                                 *"<<endl;
        cout<<"\t***********************************************************************************"<<endl;
        cout<<"\t|   DESTINO   |  CODIGO DE VUELO  | AÑO DE SALIDA | MES DE SALIDA | DIA DE SALIDA |"<<endl;		
		if(desti==1){    //validaciones para definir el lugar de ida 
            lugar="Paris";
            for (int i=0;i<contvuelo;i++){
                if(libro[i].desti==1){
                    cout<<"\t    "<<libro[i].desti<<". Paris";
                    cout<<setw(12)<<"  "<<libro[i].covu;
                    cout<<setw(14)<<"  "<<libro[i].year;
                    cout<<setw(12)<<"  "<<libro[i].mes;
                    cout<<setw(15)<<"  "<<libro[i].dia<<endl;
                    cout<<"\t-----------------------------------------------------------------------------------"<<endl;
                }        
            }
		}
		if(desti==2){
            lugar="Yakarta";
		    if(desti==2){    //validaciones para definir el lugar de ida 
                for (int i=0;i<contvuelo;i++){
                    if(libro[i].desti==2){
                        cout<<"\t  "<<""<<libro[i].desti<<". Yakarta";
                        cout<<setw(11)<<"  "<<libro[i].covu;
                        cout<<setw(14)<<"  "<<libro[i].year;
                        cout<<setw(13)<<"  "<<libro[i].mes;
                        cout<<setw(13)<<"  "<<libro[i].dia<<endl;
                        cout<<"-----------------------------------------------------------------------------------"<<endl;
                    }        
                }
		    }
		}
		if(desti==3){
            lugar="El Cairo";
			if(desti==3){    //validaciones para definir el lugar de ida 
                for (int i=0;i<contvuelo;i++){
                    if(libro[i].desti==3){
                        cout<<"\t "<<" "<<libro[i].desti<<". El Cairo";
                        cout<<setw(10)<<"  "<<libro[i].covu;
                        cout<<setw(14)<<"  "<<libro[i].year;
                        cout<<setw(13)<<"  "<<libro[i].mes;
                        cout<<setw(13)<<"  "<<libro[i].dia<<endl;
                        cout<<"-----------------------------------------------------------------------------------"<<endl;
                    }        
                }
		    }
		}
        system("pause");
        int y=0;
        string cls;
        cout<<"\n\nAhora por favor ingresa el codigo del vuelo que desea tomar: ";
        cin>>codigo;
        system("cls");
        while(y<contvuelo){
            if(libro[y].covu==codigo){
                cout<<"\t*****************************************************************************"<<endl;
                cout<<"\t*                      EL VUELO QUE ELIGIO ES                               *"<<endl;
                cout<<"\t*****************************************************************************"<<endl;
                cout<<"\t|  CODIGO  |  DESTINO  |  AÑO DE SALIDA  |  MES DE SALIDA  |  DIA DE SALIDA  |"<<endl;
                cout<<"\t   "<<codigo<<setw(12)<<libro[y].desti<<setw(15)<<libro[y].year<<" "<<setw(17)<<libro[y].mes<<"  "<<setw(12)<<" "<<libro[y].dia;
                cout<<"\n\t-----------------------------------------------------------------------------\n";
                cout<<"\tpara ese vuelo hay: \nsillas en clase turista: "<<libro[y].sturi<<" con costo:"<<libro[y].cturi<<endl;
                cout<<"sillas en clase ejecutiva: "<<libro[y].sejecu<<" con costo: "<<libro[y].cejecu<<endl;
                system("pause");
                system("cls");
                cout<<"-----------------------------------------------------------------------"<<endl;
                cout<<"| Ahora por favor selecciona una opción de clase para su vuelo: (1-2) |"<<endl;
                cout<<"-----------------------------------------------------------------------"<<endl;
                cout<<"| [1] Ejecutiva |"<<endl;
                cout<<"-----------------"<<endl;
                cout<<"| [2] Turista   |"<<endl;
                cout<<"-----------------"<<endl;
                double resillas=0;
                int costotal=0, saux1,saux2;
                if (vanum(cl)) {      //VALIDACION LETRA 
                    while(vatrun(cl) == false or cl<1 or cl>2){
                    cout<<"Por favor ingresa un número de las opciones "<<endl;
                    cin>>cl;	
                    }
                } else {
                    cout << "Algo salió mal en la validación." << endl;
                }
                if(cl==1){
                    system("cls");
                    cls="ejecuitva";
                    cout<<"\n\t\t-------------------"<<endl;
                    cout<<"\t\t| CLASE EJECUTIVA |\n";
                    cout<<"\t\t-------------------"<<endl;
                    if(libro[y].sejecu<0){
                        cout<<"lastimosamente no hay sillas disponibles";
                    }else{
                        cout<<"* Ingrese cuantas sillas de clase ejecutiva desea reservar: ";
                        if (vanum(resillas)) {      //VALIDACION LETRA 
                        while(vatrun(resillas) == false){
                            cout<<"Por favor ingresa un número de las opciones "<<endl;
                            cin>>resillas;	
                        }
                        } else {
                            cout << "Algo salió mal en la validación." << endl;
                        }
                        while(resillas>libro[y].sejecu){
                            cout<<"exedio la cantidad de sillas disponibles, por favor ingrese menos";
                        }
                        libro[y].sejecu=libro[y].sejecu-resillas;
                        costotal=libro[y].cejecu*resillas;
                        vuelo[y].rcsilla=resillas;
                    }
                    //Pasajeros
                    cout<<"\n\t A continuación ingresa los pasajeros "<<endl;
                    cout<<"\n* Ingresa la cantidad de adultos: ";
                    if (vanum(adul)) {      //VALIDACION LETRA 
                        while(vatrun(adul) == false or adul<1 ){        //***FALTA VALIDACION PARA QUE NO SOBREPASE LAS SILLAS QUE HAY****
                            cout<<"Minimo debe ir un adulto, ingresa un número permitido: "<<endl;
                            cin>>adul;	
                        }
                    } else {
                        cout << "Algo salió mal en la validación." << endl;
                    }
                    saux2=resillas;
                    while(adul>saux2){
                        cout<<"este valor exede las sillas que reservo, ingreselo denuevo";
                        cin>>adul;  
                    }
                    vuelo[y].radul=adul;
                    saux1=resillas-adul;
                    if(saux1>0){
                        cout<<"\n* Ingresa la cantidad de niños: (digita 0 si no va ningun niño)"<<endl;
                        if (vanum(nino)) {      //VALIDACION LETRA 
                            while(vatrun(nino) == false or nino<0){         //***FALTA VALIDACION PARA QUE NO SOBREPASE LAS SILLAS QUE HAY****
                            cout<<"Por favor ingresa un número permitido "<<endl;
                            cin>>nino;	
                            }
                        } else {
                            cout << "Algo salió mal en la validación." << endl;
                        }
                        if(nino>0){ 
                            while(nino>saux1){
                                cout<<"exedio la cantidad de sillas que quedan ingrese el valor de nuevo";
                                cin>>nino;
                            }
                            vuelo[y].rnino=nino;
                        }    
                    }
                }
                if(cl==2){
                    system("cls");
                    cls="turista";
                    cout<<"\n\t-----------------"<<endl;
                    cout<<"\t\t| CLASE TURISTA |\n";
                    cout<<"\t\t-----------------"<<endl;
                    if(libro[y].sturi<0){
                        cout<<"lastimosamente no hay sillas disponibles";
                    }else{
                        cout<<"Ingrese cuantas sillas de clase turista desea reservar: ";
                        if (vanum(resillas)) {      //VALIDACION LETRA 
                            while(vatrun(resillas) == false){
                            cout<<"Por favor ingresa un número de las opciones "<<endl;
                            cin>>resillas;	
                            }
                        } else {
                            cout << "Algo salió mal en la validación." << endl;
                        }
                        while(resillas>libro[y].sturi){
                            cout<<"exedio la cantidad de sillas disponibles, por favor ingrese menos";
                        }
                        libro[y].sturi=libro[y].sturi-resillas;
                        costotal=libro[y].cturi*resillas;
                        vuelo[y].rcsilla=resillas;
                    }
                    //Pasajeros
                    cout<<"\n\tA continuación ingresa los pasajeros. "<<endl;
                    cout<<"* Ingresa la cantidad de adultos: ";
                    if (vanum(adul)) {      //VALIDACION LETRA 
                        while(vatrun(adul) == false or adul<1 ){        //***FALTA VALIDACION PARA QUE NO SOBREPASE LAS SILLAS QUE HAY****
                            cout<<"Minimo debe ir un adulto, ingresa un número permitido: "<<endl;
                            cin>>adul;	
                        }
                    } else {
                        cout << "Algo salió mal en la validación." << endl;
                    }
                    saux2=resillas;
                    while(adul>saux2){
                        cout<<"\neste valor exede las sillas que reservo, ingreselo denuevo";
                        cin>>adul;
                    }
                    vuelo[y].radul=adul;
                    saux1=resillas-adul;
                    if(saux1>0){
                        cout<<"\n* Ingresa la cantidad de niños: (digita 0 si no va ningun niño)"<<endl;
                        if (vanum(nino)) {      //VALIDACION LETRA 
                            while(vatrun(nino) == false or nino<0){         //***FALTA VALIDACION PARA QUE NO SOBREPASE LAS SILLAS QUE HAY****
                            cout<<"Por favor ingresa un número permitido "<<endl;
                            cin>>nino;	
                            }
                        } else {
                            cout << "Algo salió mal en la validación." << endl;
                        }
                        if(nino>0){ 
                            while(nino>saux1){
                                cout<<"exedio la cantidad de sillas que quedan ingrese el valor de nuevo";
                                cin>>nino;
                            }
                            vuelo[y].rnino=nino;
                        }
                    }

                }    
            
                //Maletas Adicionales
                cout<<"\n\t¿Desea añadir maletas adicionales? ('1':sí otro para no)"<<endl;
                cin>>s;
                if(s=="1"){
                    cout<<"* El costo por maleta adicional es "<<libro[y].cadma<<"\nCuantas maletas adicionales desea añadir: ";
                    if (vanum(mal)) {      //VALIDACIÓN LETRA 
                    while(vatrun(mal) == false or mal<0){
                        cout<<"Por favor ingresa un número valido "<<endl;
                        cin>>mal;	
                    }
                    }else{
                        cout << "Algo salió mal en la validación." << endl;
                    } 
                    costotal=costotal+(mal*libro[y].cadma);
                    vuelo[y].radma=mal;
                }
                

                //Resúmen y confirmación
                system("pause");
                system("cls");
			    cout<<"\n\n\t****SU RESERVA VA ASI:****\n";
                cout<<"----------------------------------------"<<endl;
                cout<<"Codigo de vuelo: "<<libro[y].covu<<endl;
                cout<<"----------------------------------------"<<endl;
                cout<<"Destino: "<<lugar<<endl;
                cout<<"----------------------------------------"<<endl;
                cout<<"Fecha: AA: "<<libro[y].year<<" MM: "<<libro[y].mes<<" DD: "<<libro[y].dia<<endl;
                cout<<"----------------------------------------"<<endl;
                cout<<"Clase: "<<cls<<endl;
                cout<<"----------------------------------------"<<endl;
                cout<<"Pasajeros adultos: "<<adul<<endl;
                cout<<"----------------------------------------"<<endl;
                cout<<"Pasajeros niños: "<<nino<<endl;
                cout<<"----------------------------------------"<<endl;
                cout<<"Maletas adicionales: "<<mal<<endl;
                cout<<"----------------------------------------"<<endl;
                cout<<"Costo total de la reserva: "<<costotal<<endl;
                cout<<"----------------------------------------"<<endl;
                cout<<"\n\nSeleccione una opción: (1-2) "<<endl;
                cout<<"----------------------------------------"<<endl;
                cout<<"[1] Guardar"<<endl;
                cout<<"[2] Repetir reserva"<<endl;
                if (vanum(confin)) {      //VALIDACIÓN LETRA 
                while(vatrun(confin) == false or confin<1 or confin>2){
                    cout<<"Por favor ingresa un número valido "<<endl;
                    cin>>confin;	
                }
                }else{
                    cout << "Algo salió mal en la validación." << endl;
                }                 
            }
            y++;          
        }
		if(confin == 1){
			info=false;
			system("cls");
		}
		if(confin==2){
			info=true;
			system("cls");
		}
		contadorv++;	
	} 
    int consul, respf;
    string codic;
    cout<<"Su reserva ha sido realizada!"<<endl;
    do{
        system("cls");  
        cout<<"\t*****************************************************************************"<<endl;
        cout<<"\t*                             BUSQUEDA                                      *"<<endl;
        cout<<"\t*****************************************************************************"<<endl;
        cout<<"------------------------------------------------------------------"<<endl;
        cout<<"Prseione 1 si desea consultar las sillas reservadas del vuelo"<<endl;
        cout<<"------------------------------------------------------------------"<<endl;
        cout<<"Prseione 2 si desea consultar los adultos y niños del vuelo"<<endl;
        cout<<"------------------------------------------------------------------"<<endl;
        cout<<"Prseione 3 si desea consultar las maletas adicionales del vuelo"<<endl;
        cout<<"------------------------------------------------------------------"<<endl;
        cout<<"Presione 0 si no desea consultar nada"<<endl;
        cout<<"------------------------------------------------------------------"<<endl;
        cin>>consul;
        while(consul!=1 && consul!=2 && consul!=3 && consul!=0){
            cout<<"porfavor ingrese un valor permitido";
            cin>>consul;
        }
        system("cls");
        if (consul==1){
            cout<<"\t***********************************************************************************"<<endl;
            cout<<"\t*                                VUELOS                                           *"<<endl;
            cout<<"\t***********************************************************************************"<<endl;
            cout<<"\t|   DESTINO   |  CODIGO DE VUELO  | AÑO DE SALIDA | MES DE SALIDA | DIA DE SALIDA |"<<endl;
            for (int i=0;i<contvuelo;i++){ 
                cout<<"\t    "<<libro[i].desti;
                cout<<setw(12)<<"  "<<libro[i].covu;
                cout<<setw(14)<<"  "<<libro[i].year;
                cout<<setw(12)<<"  "<<libro[i].mes;
                cout<<setw(15)<<"  "<<libro[i].dia<<endl;
                cout<<"\t-----------------------------------------------------------------------------------"<<endl;                   
            }
            cout<<"Para el destino: 1 representa Paris, 2 Yakarta y 3 El Cairo"<<endl;
            cout<<"\nPor favor digite el codigo del vuelo que desea consultar: ";
            cin>>codic;
            for(int m=0;m<contvuelo;m++){
                if(libro[m].covu==codic)
                cout<<"\n Las cantidad de sillas reservadas para el vuelo con codigo "<<codic<<" es: "<<vuelo[m].rcsilla<<endl;
            }
        }
        if (consul==2){
            cout<<"\t***********************************************************************************"<<endl;
            cout<<"\t*                                VUELOS                                           *"<<endl;
            cout<<"\t***********************************************************************************"<<endl;
            cout<<"\t|   DESTINO   |  CODIGO DE VUELO  | AÑO DE SALIDA | MES DE SALIDA | DIA DE SALIDA |"<<endl;
            for (int i=0;i<contvuelo;i++){
                cout<<"\t    "<<libro[i].desti;
                cout<<setw(12)<<"  "<<libro[i].covu;
                cout<<setw(14)<<"  "<<libro[i].year;
                cout<<setw(12)<<"  "<<libro[i].mes;
                cout<<setw(15)<<"  "<<libro[i].dia<<endl;
                cout<<"\t-----------------------------------------------------------------------------------"<<endl;
                    
            }
            cout<<"Para el destino: 1 representa Paris, 2 Yakarta y 3 El Cairo"<<endl;
            cout<<"\nPor favor digite el codigo del vuelo que desea consultar: ";
            cin>>codic;
            for(int m=0;m<contvuelo;m++){
                if(libro[m].covu==codic)
                cout<<"\n Las cantidad de adultos en el vuelo es: "<<vuelo[m].radul<<" y de niños es: "<<vuelo[m].rnino<<endl;
            }
            
        }
        if (consul==3){
            cout<<"\t***********************************************************************************"<<endl;
            cout<<"\t*                                VUELOS                                           *"<<endl;
            cout<<"\t***********************************************************************************"<<endl;
            cout<<"\t|   DESTINO   |  CODIGO DE VUELO  | AÑO DE SALIDA | MES DE SALIDA | DIA DE SALIDA |"<<endl;
            for (int i=0;i<contvuelo;i++){ 
                cout<<"\t    "<<libro[i].desti;
                cout<<setw(12)<<"  "<<libro[i].covu;
                cout<<setw(14)<<"  "<<libro[i].year;
                cout<<setw(12)<<"  "<<libro[i].mes;
                cout<<setw(15)<<"  "<<libro[i].dia<<endl;
                cout<<"\t-----------------------------------------------------------------------------------"<<endl;                   
            }
            cout<<"Para el destino: 1 representa Paris, 2 Yakarta y 3 El Cairo"<<endl;
            cout<<"\nPor favor digite el codigo del vuelo que desea consultar: ";
            cin>>codic;
            for(int m=0;m<contvuelo;m++){
                if(libro[m].covu==codic)
                cout<<"\n Las cantidad de maletas adicionales para el vuelo: "<<codic<<" es: "<<vuelo[m].radma<<endl;
            }        
        }
        if(consul==1 || consul==2 || consul==3){
            cout<<"si desea reralizar otra busqueda presione 1 si no presione otra tecla: ";
            cin>>respf;
        }
        if(consul==0){
            cout<<"\n";
            respf=2;
        }
    }while(respf==1);
    system("cls");
    cout<<"\t\t¡Gracias por usar el servicio de reserva de vuelos de la Aereolinea Emiratos Arabes Unidos!\n\t\t\t\t¡Que tengas un feliz viaje!"<<endl;
    system("pause");
	return 0;
}

//FUNCIONES VALIDACION

bool vanum(double& x){   //Funcion para validar que no sean letras
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
bool vatrun(double& x){ //Funcion para validar que sean números enteros
	double y;
	y=trunc(x);
	return y==x;
}