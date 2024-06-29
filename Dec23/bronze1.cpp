//Candy Cane Feast
//
#include <iostream>

using namespace std;

int main(){
    int32_t n, m;
    cin >> n >> m;
    long long h[n];
    long long c[m];
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    for(int i = 0; i < m; i++){
        cin >> c[i];
    }
    for(int k = 0; k < m; k++){
        long long b = 0;
        for (int i = 0; i < n; i++){
            if (h[i]>=c[k]){
                h[i]+=c[k]-b;
                break;
            }
            if (h[i]<=b){
                continue;
            }
            long long temp = h[i];
            h[i]+=h[i]-b;
            b=temp;
        }
    }
    for (int i = 0; i < n; i++){
        cout << h[i] << endl;
    }
}