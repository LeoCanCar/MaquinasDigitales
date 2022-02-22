#include <iostream>
using namespace std;

int myfunc(int a){
    return a+20;
}

int main(){

    cout << "Tamaño en bytes de <char>: " << sizeof(char) <<endl;
    cout << "Tamaño en bytes de <bool>: " << sizeof(bool) <<endl;
    cout << "Tamaño en bytes de <int>: " << sizeof(int) <<endl;
    cout << "Tamaño en bytes de <float>: " << sizeof(float) <<endl;
    cout << "Tamaño en bytes de <long>: " << sizeof(long) <<endl;
    cout << "Tamaño en bytes de <double>: " << sizeof(double) <<endl;

    cout << myfunc(8) << endl;

    return 0;
}
