//Milk Exchange
//
#include <iostream>
#include <vector>

using namespace std;
 
int main(){
    int n, m; 
    cin >> n >> m;
    string s;
    cin >> s;
    vector<long long> a(n);
    for(long long& i: a) cin >> i;
	
    vector<bool> badL(n), badR(n);
    for(int i = 0; i < n; i++){
        if(s[i] == 'R' && s[(i + 1) % n] == 'L'){
            badL[i] = true;
            badR[(i + 1) % n] = true;
        }
    }
        
    long long ans = 0;
    for(int i = 0 ; i < n; i++){
        ans+=a[i];
    }
    for(int i = 0; i < n; i++){
        long long sum = 0;
        if(badL[i]){
            int j = (i - 1 + n) % n;
            while(s[j] == 'R'){
                sum += a[j--];
                if(j < 0) j += n;
            }
        }
        if(badR[i]){
            int j = (i + 1) % n;
            while(s[j] == 'L'){
                sum += a[j++];
                if(j >= n) j -= n;
            }
        }
        ans -= min(sum, (long long) m);
    }
    cout << ans << endl;
}