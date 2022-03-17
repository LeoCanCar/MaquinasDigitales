#include <iostream>
#include "opVect.h"
using namespace std;

#define v_SIZE 3

int main(){

    int v1[v_SIZE] = {1,2,3}, v2[v_SIZE] = {3,1,2}, v3[v_SIZE] = {2,3,1};
    int vr[v_SIZE];

    cout << "vr = v1 + v2" << endl;
    sumVect(v1, v2, vr, v_SIZE);
    printVect(vr, v_SIZE);

    cout << "vr = v1 + v2" << endl;
    resVect(v1, v2, vr, v_SIZE);
    printVect(vr, v_SIZE);

    cout << "vr = v1 + v2" << endl;
    mulVect(v1, v2, vr, v_SIZE);
    printVect(vr, v_SIZE);

    cout << "vr = v1 + v2" << endl;
    divVect(v1, v2, vr, v_SIZE);
    printVect(vr, v_SIZE);

    return 0;

}