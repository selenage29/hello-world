//Cowmpetency

#include <iostream>

using namespace std;


void solve(){
    int n, q, C;
    cin >> n >> q >> C;
    int b[n+1], c[n];
    bool assigned[n];
    cin >> c[0];
    if(c[0]==0){
        c[0]=1;
        assigned[0]=false;
    }else{
        assigned[0]=true;
    }
    b[0]=0;
    b[n]=0;
    for (int i = 1; i < n; i++){
        b[i]=0;
        cin >> c[i];
        if(c[i]==0){
            assigned[i]=false;
            c[i]=1;
        }else{
            assigned[i]=true;
        }
    }
    for(int i = 0; i < q; i++){
        int a, h;
        cin >> a >> h;
        b[a]=h;
    }
    int cur=1;
    while(cur<=n){
        int i = cur;
        while(cur<b[i]){
            if(b[cur]!=0&&b[cur]!=b[i]){
                cout << "-1" << endl;
                return;
            }
            b[cur]=b[i];
            cur++;
        }
        cur=max(cur, i+1);
    }
    int i = 1;
    int mx_before = 0;
    int mx_after = 0;
    while(i<=n){
        mx_before = max(mx_before, c[i-1]);
        mx_after = max(mx_after, c[i-1]);
        if(b[i]==0){
            i++;
            continue;
        }
        for(int j = i; j < b[i]; j++){
            mx_after = max(mx_after, c[j-1]);
        }
        if(mx_after>mx_before){
            bool update = false;
            for(int j = i; j >0; j--){
                if(b[j]!=0&&b[j]<b[i]){
                    cout << "-1" << endl;
                    return;
                }
                if(assigned[j-1]){
                    continue;
                }
                update=true;
                c[j-1] = mx_after;
                break;
            }
            if(!update){
            cout << "-1" << endl;
            return;
            }
            mx_before = mx_after;
        }
        if(!assigned[b[i]-1]){
            c[b[i]-1]=mx_before+1;
        }
        if(c[b[i]-1]<=mx_before){
            cout << "-1" << endl;
            return;
        }
        i=b[i];
    }
    for(int i = 0; i < n; i++){
        if(c[i]>C){
            cout << "-1" << endl;
            return;
        }
    }
    for(int i = 0; i < n-1; i++){
        cout << c[i] << " ";
    }
    cout << c[n-1] << endl;
}
int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}