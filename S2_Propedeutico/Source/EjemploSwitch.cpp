#include <iostream>
using namespace std;

int main (){
    float a; float b; int c;
    cout << "Ingrese el primer numero a operar: " << endl;
    cin >> a;
    cout << "Ingrese el sgundo numero a operar: " << endl;
    cin >> b;
    cout << "Seleccione el numero de la operacion que desea realizar con los numeros: " << endl;
    cout << "1) Suma, 2) Resta, 3) Multiplicacion, 4) Division" << endl;
    cin >> c;
    switch (c){
        case 1:
            cout << "La suma es: " << endl;
            cout << a+b;
            break;
        case 2:
            cout << "La resta es: " << endl;
            cout << a-b;
            break;
        case 3:
            cout << "La multiplicacion es: " << endl;
            cout << a*b;
            break;
        case 4:
            cout << "La division es: " << endl;
            cout << a/b;
            break;
        

    }
    return 0;

}