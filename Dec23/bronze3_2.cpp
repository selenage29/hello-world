//Farmer John Actually Farms
//9/13
//
#include <iostream>
#include <algorithm>

using namespace std;

struct p{
    long long a;
    long long b;
    int t;
};

bool compare(const p& p1, const p& p2) {
return p1.b < p2.b;
}
bool compare1(const p& p1, const p& p2) {
return p1.t < p2.t;
}

void solve(){
    int n;
    cin >> n;
    p plant[n];
    for(int i = 0; i < n; i++){
        cin >> plant[i].a;
    }
    for(int i = 0; i < n; i++){
        cin >> plant[i].b;
    }
    for(int i = 0; i < n; i++){
        cin >> plant[i].t;
    }
    if(n==1){
        cout << 0 << endl;
        return;
    }
    sort(plant, plant+n, compare);
    for(int i = 0; i < n-1; i++){
        if(plant[i].b==plant[i+1].b){
            if(plant[i].a>plant[i+1].a && plant[i].t > plant[i+1].t){
                cout << "-1" << endl;
                return;
            }
            if(plant[i].a<plant[i+1].a && plant[i].t < plant[i+1].t){
                cout << "-1" << endl;
                return;
            }
            if(plant[i].a==plant[i+1].a){
                cout << "-1" << endl;
                return;
            }
        }
    }
    sort(plant, plant+n, compare1);
    bool done = false;
    int i = 0;
    while(!done){
        int j;
        for(j = 0; j < n-1; j++){
            if(plant[j].a+plant[j].b*i<=plant[j+1].a+plant[j+1].b*i){
                break;
            }
            if(j==n-2){
                done=true;
            }
        }
        if(!done){
            i++;
        }
    }
    cout << i << endl;
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}