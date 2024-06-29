//Cycle Correspondence
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a, b;
    bool used[n];
    for(int i = 0; i < n; i++){
        used[i]=false;
    }
    int count = 0;
    for (int i = 0; i < k; i++){
        int t;
        cin >> t;
        a.push_back(make_pair(t, i));
        if(used[t-1]==false){
            count++;
            used[t-1]=true;
        }
    }
    for (int i = 0; i < k; i++){
        int t;
        cin >> t;
        b.push_back(make_pair(t, i));
        if(used[t-1]==false){
            count++;
            used[t-1]=true;
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int c[k];
    for(int i = 0; i < k; i++){
        c[i] = 0;
    }
    int j = 0;
    for(int i = 0; i < k; i++){
        while(a[i].first>b[j].first){
            j++;
        }
        if(a[i].first==b[j].first){
            if(a[i].second>=b[j].second){
                c[a[i].second-b[j].second]++;
            }else{
                c[a[i].second-b[j].second+k]++;
            }
            j++;
            continue;
        }
    }
    int cc[k];
    vector<pair<int, int>> bb;
    for(int i = 0; i < k; i++){
        cc[i] = 0;
        bb.push_back(make_pair(b[i].first, k-1-b[i].second));
    }
    j = 0;
    for(int i = 0; i < k; i++){
        while(a[i].first>bb[j].first){
            j++;
        }
        if(a[i].first==bb[j].first){
            if(a[i].second>=bb[j].second){
                cc[a[i].second-bb[j].second]++;
            }else{
                cc[a[i].second-bb[j].second+k]++;
            }
            j++;
            continue;
        }
        if(j>=k){
            break;
        }
    }
    j = 0;
    int M = 0;
    for(int i = 0; i < k; i++){
        M=max(M, c[i]);
        M=max(M, cc[i]);
    }

    cout << M + n - count << endl;
}