#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define fi first
#define se second
#define FORU(i , a , b) for(ll i = a ; i <= b ; i++)
#define FORD(i , a , b) for(ll i = a ; i >= b ; i--)
using namespace std;
const ll MAX = 1e5 + 10, MOD = 1e9 + 7;
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
ll n, m, x, y, v, k;
ll diameter, dp[2][MAX], best, Poll1, Poll2;
vector <ll> adj[MAX];
void input()
{
    cin >> n >> m;
    for (ll i = 1; i < n; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
void dfs1(ll u, ll p, ll w)
{
    if (best < w)
    {
        best = w;
        Poll1 = u;
    }
    for (ll v : adj[u])
    {
        if (v == p) continue;
        dfs1(v, u, w + 1);
    }
}
void dfs2(ll u, ll p, ll w, ll type)
{
    if (best < w)
    {
        best = w;
        Poll2 = u;
    }
    dp[type][u] = w;
    for (ll v : adj[u])
    {
        if (v == p) continue;
        dfs2(v, u, w + 1, type);
    }
}
void prepare()
{
    dfs1(1, 1, 0);
    best = 0;
    dfs2(Poll1, Poll1, 0, 0);
    diameter = best;
    best = MOD;
    dfs2(Poll2, Poll2, 0, 1);
}
void solve()
{
    cin >> v >> k;
    ll res = max(dp[0][v], dp[1][v]);
    cout << res + (k - 1) * diameter << '\n';
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("t.inp", "r", stdin);
    input();
    prepare();
    while (m--) solve();
    return 0;
}
