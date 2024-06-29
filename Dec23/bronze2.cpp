//Cowntact Tracing 2
//
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    string end;
    cin >> end;
    vector<int> block;
    int cur = 0;
    for(int i = 0; i < n; i++){
        if(end[i]=='0'&&cur!=0){
                block.push_back(cur);
                cur = 0;
        }else if(end[i]=='1'){
            cur++;
        }
    }
    if(cur!=0){
        block.push_back(cur);
    }
    int bs=block.size();
    int m = 300000;
    int ans = 0;
    for(int i = 0; i < bs; i++){
        if(end[0]='1'&&i==0){
            m=min(m, block[0]-1);
            continue;
        }
        if(end[n-1]=='1'&&i==bs-1){
            m=min(m, block[bs-1]-1);
            continue;
        }
        if(block[i]%2==0){
            m=min(m, block[i]/2-1);
        }else{
            m=min(m,(block[i]-1)/2);
        }
    }
    int i;
    for( i = 0; i < bs; i++){
        if(block[i]<=2*m+1&&(i==0||i==bs-1)){
            ans+=1;
            continue;
        }
        if(block[i]>2*m+1){
            if(block[i]%(2*m+1)==0){
                ans+=block[i]/(2*m+1);
            }else{
                ans+=block[i]/(2*m+1)+1;
            }
        }else if(block[i]%2==0){
            ans+=2;
        }else{
            ans+=1;
        }
    }
    cout << ans << endl;
}