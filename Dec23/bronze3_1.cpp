// Farmer John Actually Farms
//13/13
//
#include <iostream>
#include <algorithm>

using namespace std;

struct p
{
    long long a;
    long long b;
    int t;
};

bool compare(const p &p1, const p &p2)
{
    return p1.b < p2.b;
}
bool compare1(const p &p1, const p &p2)
{
    return p1.t < p2.t;
}

void solve()
{
    int n;
    cin >> n;
    p plant[n];
    for (int i = 0; i < n; i++)
    {
        cin >> plant[i].a;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> plant[i].b;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> plant[i].t;
    }
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    sort(plant, plant + n, compare);
    for (int i = 0; i < n - 1; i++)
    {
        if (plant[i].b == plant[i + 1].b)
        {
            if (plant[i].a > plant[i + 1].a && plant[i].t > plant[i + 1].t)
            {
                cout << "-1" << endl;
                return;
            }
            if (plant[i].a < plant[i + 1].a && plant[i].t < plant[i + 1].t)
            {
                cout << "-1" << endl;
                return;
            }
            if (plant[i].a == plant[i + 1].a)
            {
                cout << "-1" << endl;
                return;
            }
        }
    }
    sort(plant, plant + n, compare1);
    long long m = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (plant[i + 1].a < plant[i].a)
        {
            continue;
        }
        if ((plant[i + 1].a - plant[i].a + 1) % (plant[i].b - plant[i+1].b) == 0)
        {
            m = max(m, (plant[i + 1].a - plant[i].a + 1) / (plant[i].b - plant[i+1].b));
        }
        else
        {
            m = max(m, (plant[i + 1].a - plant[i].a + 1) / (plant[i].b - plant[i+1].b) + 1);
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (plant[i].a + m * plant[i].b <= plant[i + 1].a + m * plant[i + 1].b)
        {
            cout << "-1" << endl;
            return;
        }
    }
    cout << m << endl;
    return;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}