#include <iostream>
#include <fstream>

using namespace std;

int main() {
    system("cls");
    int vector[] = {1, 5, 3, 4},a;
    ifstream arcivo("prueba6.txt");
    switch (arcivo.good())
    {
    case true:
        cout<<"yessssss";
        arcivo.close();
        exit(1);
        break;
    
    default:
        ofstream archivo("prueba6.txt");
        cout<<"todo lo que joan ha hecho + llenarlo";
        break;
    }
    cout<<"cliente";
}
