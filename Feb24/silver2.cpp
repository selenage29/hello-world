//Test Tubes
//10/21
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

void simplify(string &s){
    string l = "";
    char cur = 'x';
    for(long long i = 0; i < s.size(); i++){
        if(s[i]!=cur){
            l+=s[i];
            cur=s[i];
        }
    }
    s=l;
}

long long solve1(string &f, string &s){
    simplify(f);
    simplify(s);
    if(f.size()==1 && s.size()==1){
        return 0;
    }
    if(f.size()==1){
        if(f[0]==s[0]){
            return s.size()+1;
        }else{
            return s.size();
        }
    }
    if(s.size()==1){
        if(f[0]==s[0]){
            return f.size()+1;
        }else{
            return f.size();
        }
    }

    if(f[0]==s[0]){
        return f.size()+s.size();
    }else{
        return f.size()+s.size()-1;
    }
}

void solve2(){
    string f, s;
    cin >> f >> s;
    simplify(f);
    simplify(s);
    vector<pair<char,char>> moves;
    bool beaker = false;
    for(long long i = s.size()-1; i >= 0; i--){
        if(s[i]=='2'){
            moves.push_back(make_pair('2', '1'));
            f.push_back('2');
        }else{
            moves.push_back(make_pair('2','3'));
            beaker = true;
        }
    }
    simplify(f);
    for(long long i = f.size()-1; i >= 0; i--){
        if(f[i]=='2'){
            moves.push_back(make_pair('1', '2'));
        }else{
            moves.push_back(make_pair('1', '3'));
            beaker = true;
        }
    }
    if(beaker){
        moves.push_back(make_pair('3', '1'));
    }
    cout << moves.size() << endl;
    for(long long i = 0; i < moves.size(); i++){
        cout << moves[i].first << " " << moves[i].second << endl;
    }
}

void solve3(){
    string f, s;
    cin >> f >> s;
    long long target = solve1(f,s);
    
    vector<pair<char,char>> moves;
    if(f[f.size()-1]==s[s.size()-1]){
        if(f.size()>1){
            f.pop_back();
            moves.push_back(make_pair('1','2'));
        }else{
            s.pop_back();
            moves.push_back(make_pair('2','1'));
        }
    }
    if(f.size()==1&&s.size()==1){
        cout << moves.size() << endl;
        for(long long i = 0; i < moves.size(); i++){
            cout << moves[i].first << " " << moves[i].second << endl;
        }
        return;
    }
    if(s.size()>1){
    char cur = f[f.size()-1];
    for(long long i = s.size()-1; i > 0; i--){
        if(s[i]!=cur){
            moves.push_back(make_pair('2','3'));
        }else {
            moves.push_back(make_pair('2','1'));
        }
    }
    cur = s[s.size()-1];
    for(long long i = f.size()-1; i > 0; i--){
        if(f[i]!=cur){
            moves.push_back(make_pair('1','2'));
        }else {
            moves.push_back(make_pair('1','3'));
        }
    }
    if(f[0]==s[0]){
        moves.push_back(make_pair('1','2'));
    }
    moves.push_back(make_pair('3','1'));
    }
    if(moves.size()!=target&&false){
        moves.erase(moves.begin(),moves.end());
        char cur = s[s.size()-1];
    for(long long i = f.size()-1; i > 0; i--){
        if(f[i]==cur){
            moves.push_back(make_pair('1','2'));
        }else {
            moves.push_back(make_pair('1','3'));
        }
    }
    cur = f[f.size()-1];
    for(long long i = s.size()-1; i > 0; i--){
        if(s[i]!=cur){
            moves.push_back(make_pair('2','1'));
        }else {
            moves.push_back(make_pair('2','3'));
        }
    }
    if(f[0]==s[0]){
        moves.push_back(make_pair('2','1'));
    }
    moves.push_back(make_pair('3','2'));
    }
    cout << moves.size() << endl;
        for(long long i = 0; i < moves.size(); i++){
            cout << moves[i].first << " " << moves[i].second << endl;
        }
}

int main(){
    freopen("tt.in","r",stdin);
    freopen("tt.out","w",stdout);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n, p;
        cin >> n >> p;
        if(p==1){
            string f, s;
            cin >> f >> s;
            long long a = solve1(f, s);
            cout << a << endl;
        }else if(p==2){
            solve2();
        }else{
            solve3();
        }
    }
}