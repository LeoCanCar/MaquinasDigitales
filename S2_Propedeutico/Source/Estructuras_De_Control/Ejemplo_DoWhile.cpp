#include <iostream>
using namespace std;

int main(){
    int numero;
    do{
        cout << "Ingresa un numero entre 0 y 10: ";
        cin >> numero;
    } while (numero >= 0 && numero<= 10);

    cout << "El numero: " << numero << "no esta entre 0 y 10";
    
    return 0;
}
