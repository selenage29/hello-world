//Potion Farming
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct r {
bool leaf;
int deg;
int parent;
int level;
int done;
int cap;
bool assigned;
};

r room[100001];
vector<int> v[100001];

void assign(int a){
    for(int i = 0; i < v[a].size(); i++){
        if(v[a][i]==room[a].parent){
            continue;
        }
        room[v[a][i]].parent = a;
        room[v[a][i]].level = room[a].level+1;
        if(!room[v[a][i]].leaf){
            assign(v[a][i]);
        }
    }
    return;
}

void assign2(int a){
    int ans = 0;
    for(int i = 0; i < v[a].size(); i++){
        if(v[a][i]==room[a].parent){
            continue;
        }
        if(!room[v[a][i]].assigned){
            assign2(v[a][i]);
        }
        ans+=room[v[a][i]].cap;
    }
    room[a].assigned = true;
    room[a].cap = ans;
    return;
}

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second>b.second){
        return true;
    }else{
        return false;
    }
}

int main(){
    int n;
    cin >> n;
    int p[n];
    for(int i = 0; i < n; i++){
        cin >> p[i];
        room[i+1].deg=0;
        room[i+1].done = 0;
        room[i+1].assigned = false;
    }
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        room[a].deg++;
        room[b].deg++;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int t=0;
    room[1].leaf = false;
    for(int i = 2; i <= n; i++){
        if(room[i].deg==1){
            t++;
            room[i].leaf = true;
            room[i].cap = 1;
            room[i].assigned = true;
        }else{
            room[i].leaf = false;
        }
    }
    room[1].level=1;
    room[1].parent = 0;
    assign(1);
    assign2(1);
    pair<int, int> potion[t];
    for(int i = 0; i < t; i++){
        potion[i].first = p[i];
        potion[i].second = room[p[i]].level;
    }
    sort(potion, potion+t, compare);
    int ans = 0;
    for(int i = 0; i < t; i++){
        if(room[potion[i].first].done>=room[potion[i].first].cap){
            continue;
        }
        int k = potion[i].first;
        bool works = true;
        while(room[k].parent!=0){
            room[k].done++;
            if(room[k].done>room[k].cap){
                works = false;
            }
            k=room[k].parent;
        }
        if(works){
            ans++;
        }
    }
    cout << ans << endl;
}