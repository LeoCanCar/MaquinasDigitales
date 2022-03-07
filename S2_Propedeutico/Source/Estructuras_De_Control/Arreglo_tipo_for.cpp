#include <iostream>
using namespace std;



int main(){

    int arr1[]= {5, 8, 6, 3, 11, 1, 9, 7};

    for(int i=0; i<8; i++){
         if (arr1[i]%2 == 0){
              cout << "Este valor es par: " << arr1[i] << endl;
         }else{
             cout << "Este valor es impar: " << arr1[i] << endl;
         }

}

return 0;
}