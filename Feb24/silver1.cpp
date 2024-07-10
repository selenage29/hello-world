//Target Practice II
//13/15
#include <iostream>
#include <algorithm>

using ll = long long;
using namespace std;

ll xr[40000];
ll yb[40000];
ll yt [40000];
ll s[160000];

ll max_search(ll l, ll u, ll less, int N){
    ll a;
    if(l%2==u%2){
        a = (l+u)/2;
    }else{
        a = (l+u+1)/2;
    }
    double s2[N];
    for(int i = 0; i < N; i++){
        s2[i] = (yt[i]*1.0-a)/(xr[i]*1.0);
    }
    sort(s2, s2+N);
    bool yes = false;
    for(int i = 0 ; i< N; i++){
        if(s2[i]>s[less-N+i]){
            return max_search(a+1, u, less, N);
        }
        if(s2[i]==s[less-N+i]){
            yes = true;
        }
    }
    if (yes){
        return a;
    }
    return max_search(l, a-1, less, N);
}

ll min_search(ll l, ll u, ll less, int N){
    ll a;
    if(l%2==u%2){
        a = (l+u)/2;
    }else{
        a = (l+u+1)/2;
    }
    double s2[N];
    for(int i = 0; i < N; i++){
        s2[i] = (yb[i]*1.0-a)/(xr[i]*1.0);
    }
    sort(s2, s2+N);
    bool yes = false;
    for(int i = 0 ; i< N; i++){
        if(s2[i]<s[less+i]){
            return min_search(l, a-1, less, N);
        }
        if(s2[i]==s[less+i]){
            yes = true;
        }
    }
    if(yes){
        return a;
    }
    return min_search(a+1, u, less, N);
}

void solve(){
    int n;
    ll xl;
    cin >> n >> xl;
    ll y[2*n];
    ll maxy=0;
    ll miny = 1000000000;
    for(int i = 0; i < n; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        yb[i]=a;
        yt[i]=b;
        xr[i]=c;//s
        y[2*i]=yb[i];
        y[2*i+1]=yt[i];
        maxy = max(maxy, yt[i]);
        miny = min(miny, yb[i]);
    }
    int less=0;
    for(int i = 0; i < 4*n; i++){
        cin >> s[i];
        if(s[i]<0){
            less++;
        }
    }
    if(less<n || less>3*n){
        cout << "-1" << endl;
        return;
    }
    sort(s, s+4*n);
    ll s1[2*n];
    for(int i = 0; i < less-n; i++){
        s1[i] = s[i];
    }
    for(int i = less-n; i<2*n; i++){
        s1[i] = s[i+2*n];
    }
    sort(y, y+2*n);
    ll M=-1000000000000000000, m=1000000000000000000;
    for(int i = 0; i < n; i++){
        ll a = y[i]-s1[i]*xl;
        ll b = y[2*n-1-i]-s1[2*n-1-i]*xl;
        M = max(M, a);
        M = max(M, b);
        m = min(m, a);
        m = min(m, b);
    }
    
    M = max(M, max_search(maxy, 1000000000000000000, less, n));
    m = min(m, min_search(-1000000000000000000, miny, less, n));
    cout << M-m << endl;
    return;
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}