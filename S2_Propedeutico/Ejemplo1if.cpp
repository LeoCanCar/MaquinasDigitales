#include <iostream>
using namespace std;

/*int main(){    este fue mi intento de codigo
    float a;

    cin >> a;

    if (a <=0) {
        
        cout <<
    }
}*/

int main(){
    float numero;  /*creo la variable*/
    cout << "Ingresa un numero: "; /*doy la instrucción de ingresar un número*/
    cin >> numero; /*Aquí se pide ingresar el valor*/

    if (numero > 0){     /*Se inicia la función if*/
        cout << "El numero es mayor que cero" << endl;
    }else{
        numero = numero + 10;
        cout << "Se le aumentaran 10 unidades al numero ingresado" << endl;
        cout << numero << endl;
        /*O tambien se puede poner como originalmente lo puse:
        cout << "Se le aumentaran 10 unidades al numero ingresado" << endl
        cout << numero + 10 << endl;
         */
    }

    return 0;
}


