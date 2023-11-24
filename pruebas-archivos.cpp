#include <iostream>
#include <locale.h>
#include <limits>
#include <stdio.h>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

void lectu ();

int main (){
    ifstream archivo;
    string text;
    archivo.open("prueba.txt",ios::in);

    if(archivo.fail()){
        ofstream archivo;
        archivo.open("prueba2.txt",ios::out);
        if(archivo.fail()){
            cout<<"ya marica ya";
            exit(1);
        }
        archivo<<"yellow";
        archivo.close();
        exit(1);
    }
    while(!archivo.eof()){

        getline(archivo,text);
        cout<<text;
    }
    archivo.close();

}

void lectu(){
    ifstream archivo;
    string text;
    archivo.open("prueba.txt",ios::in);

    if(archivo.fail()){
        cout<<" no abrio";
        exit(1);
    }
    while(!archivo.eof()){

        getline(archivo,text);
        cout<<text;
    }
    archivo.close();
}
