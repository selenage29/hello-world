#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> cows;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int i = 0; i < min(m, b); i++){
            cows.push_back(a);
        }
    }
    sort(cows.begin(), cows.end()); 
    int ans = 0;
    int tower[m];
    for (int i = 0; i < m; i++)
    {
        tower[i] = 2147483647;
    }
    int p = 0;
    for (int i = cows.size()-1; i >= 0; i--)
    {
        if(cows[i]<=tower[p]-k){
            ans++;
            tower[p]=cows[i];
            p++;
            if (p==m){
                p=0;
            }
        }
    }
    cout << ans << endl;
}