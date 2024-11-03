//Palindrome Game
//
#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        string n;
        cin >> n;
        if(n[n.size()-1]=='0'){
            cout << 'E' << endl;
        }else{
            cout << 'B' << endl;
        }
    }
}