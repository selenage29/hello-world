#include <iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int h[n];
    int c[m];
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    for(int j = 0; j < m; j++){
        cin >> c[j];
    }
    for(int k = 0; k < m; k++){
        int b = 0;
        for (int i = 0; i < n; i++){
            if (h[i]>=c[k]){
                h[i]+=c[k]-b;
                b=c[k];
                break;
            }
            if (h[i]<=b){
                continue;
            }
            int temp = h[i];
            h[i]+=h[i]-b;
            b=temp;
        }
    }
    for (int i = 0; i < n; i++){
        cout << h[i] << endl;
    }
}