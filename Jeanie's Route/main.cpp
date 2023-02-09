#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define fi first
#define se second
#define FORU(i , a , b) for(ll i = a ; i <= b ; i++)
#define FORD(i , a , b) for(ll i = a ; i >= b ; i--)
using namespace std;
const ll MAX = 1e6 + 10, MOD = 1e9 + 7;
void unset(ll &t, ll pos)
{
    t &= (~(1ll << (pos - 1)));
}
void onset(ll &t, ll pos)
{
    t |= (1ll << (pos - 1));
}
ll getbit(ll i,ll k)
{
    return (k >> (i - 1)) % 2;
}
void minimize(ll &x, ll y)
{
    x = min(x, y);
}
void maximize(ll &x, ll y)
{
    x = max(x, y);
}
ll ADD(ll x, ll y)
{
    return (x + y) % MOD;
}
ll MINUS(ll x, ll y)
{
    x %= MOD, y %= MOD;
    if (x < y) x += MOD;
    return (x - y) % MOD;
}
//========================================================================0========================================================================//
ll n, k, sum;
bool special[MAX];
ll vertex, best;
vector <pii> adj[MAX], edge[MAX];
void input()
{
    cin >> n >> k;
    ll u, v, w;
    for (ll i = 1; i <= k; i++)
    {
        cin >> u;
        special[u] = 1;
        vertex = u;
    }
    for (ll i = 1; i < n; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
}
bool dfs(ll u, ll p)
{
    ll ret = special[u];
    for (pii tmp : adj[u])
    {
        ll v = tmp.fi, w = tmp.se;
        if (v == p) continue;
        if (dfs(v, u))
        {
            ret = 1;
            edge[u].push_back({v, w});
            edge[v].push_back({u, w});
            sum += w;
        }
    }
    return ret;
}
void dfs2(ll u, ll p, ll meter)
{
    if (best < meter)
    {
        best = meter;
        vertex = u;
    }
    for (pii tmp : edge[u])
    {
        ll v = tmp.fi, w = tmp.se;
        if (v == p) continue;
        dfs2(v, u, meter + w);
    }
}
void solve()
{
    dfs(vertex, vertex);
    dfs2(vertex, vertex, 0);
    best = 0;
    dfs2(vertex, vertex, 0);
    cout << 2 * sum - best;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("t.inp", "r", stdin);
    input();
    solve();
    return 0;
}
