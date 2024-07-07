//Cowlendar
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

set<long long> divisors;

void factor(double a){
    long long k = a;
    for(long long i = 1; i <= sqrt(a); i++){
        if (k%i==0){
            divisors.insert(i);
            divisors.insert(k/i);
        }
    }
    divisors.insert(a);
}

int main(){
    long long n;
    cin >> n;
    long long a[n];
    long long m=4000000000;
    for(long long i = 0; i < n; i++){
        cin >> a[i];
        m=min(m, a[i]);
    }
    long long lmax = (m-(m%4))/4;
    sort(a, a+n);
    vector<long long> d;
    d.push_back(a[0]);
    for(long long i = 1; i < n; i++){
        if(a[i]!=a[i-1]){
            d.push_back(a[i]);
        }
    }
    if(d.size()<=3){
        cout << (lmax)*(lmax+1)/2;
        return 0;
    }
    factor(d[3]-d[0]);
    factor(d[2]-d[0]);
    factor(d[1]-d[0]);
    factor(d[3]-d[1]);
    factor(d[2]-d[1]);
    factor(d[3]-d[2]);
    set<long long>::iterator itr;
    long long ans = 0;
    for (itr = divisors.begin(); itr != divisors.end(); itr++) {
        long long l = *itr;
        if (l>lmax){
            continue;
        }
        set<int> r;
        for(int i = 0; i < d.size(); i++){
            r.insert(d[i]%l);
        }
        if(r.size()<=3){
            ans+=l;
        }
    }
    cout << ans << endl;
}