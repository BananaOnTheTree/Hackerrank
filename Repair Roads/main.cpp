#include <iostream>
#include <bits/stdc++.h>
//#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define FORU(i , a , b) for(int i = a ; i <= b ; i++)
#define FORD(i , a , b) for(int i = a ; i >= b ; i--)
using namespace std;
const int MAX = 1e6 + 10, MOD = 1e9 + 7;
void unset(int &t, int pos)
{
    t &= (~(1ll << (pos - 1)));
}
void onset(int &t, int pos)
{
    t |= (1ll << (pos - 1));
}
int getbit(int i,int k)
{
    return (k >> (i - 1)) % 2;
}
void minimize(int &x, int y)
{
    x = min(x, y);
}
void maximize(int &x, int y)
{
    x = max(x, y);
}
int ADD(int x, int y)
{
    return (x + y) % MOD;
}
int MINUS(int x, int y)
{
    x %= MOD, y %= MOD;
    if (x < y) x += MOD;
    return (x - y) % MOD;
}
//========================================================================0========================================================================//
int n, start, res;
vector <int> adj[MAX];
void input()
{
    cin >> n;
    int u, v;
    for (int i = 1; i <= n; i++) adj[i].clear();
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        u++; v++;
        //cout << u << " " << v << '\n';
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if ((int)adj[i].size() == 1) start = i;
    }
}
void dfs(int u, int p, int &res)
{
    bool direct = 0;
    for (int v : adj[u])
    {
        if (v == p) continue;
        if ((int)adj[v].size() == 1) continue;
        res += direct;
        direct = 1 - direct;
        dfs(v, u, res);
    }
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("t.inp", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        input();
        res = MOD;
        int tmp = 1;
        for (int i = 1; i <= n; i++)
        {
            dfs(i, i, tmp);
            minimize(res, tmp);
            tmp = 1;
        }
        //dfs(start, start, res);
        cout << res << '\n';
    }
    return 0;
}
