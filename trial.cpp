#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    for (int i = 1; i < 11; i++){
        if (i==1){
            cout << "This is the " << i << "st loop" << endl;
            continue;
        }
        if(i==2){
            cout << "This is the " << i << "nd loop" << endl;
            continue;
        }
        if(i==3){
            cout << "This is the " << i << "rd loop" << endl;
            continue;
        }
        cout << "This is the " << i << "th loop" << endl;
    }
}