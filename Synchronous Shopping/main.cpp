#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define piii pair <ll, pii>
#define fi first
#define se second
#define FORU(i , a , b) for(ll i = a ; i <= b ; i++)
#define FORD(i , a , b) for(ll i = a ; i >= b ; i--)
using namespace std;
const ll MAX = 1e3 + 500, MOD = 1e9 + 7;
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
ll n, m, k, d[MAX][MAX], fish[MAX], limit;
vector <pii> adj[MAX];
void input()
{
    cin >> n >> m >> k;
    limit = (1 << k) - 1;
    for (ll i = 1; i <= n; i++)
    {
        ll ti, tmp;
        cin >> ti;
        while (ti--)
        {
            cin >> tmp;
            onset(fish[i], tmp);
        }
    }
    for (ll i = 1; i <= m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
}
void dijkstra()
{
    for (ll i = 0; i <= limit; i++)
    {
        for (ll j = 0; j <= n; j++) d[j][i] = MOD;
    }
    d[1][fish[1]] = 0;
    priority_queue <piii, vector <piii>, greater <piii>> q;
    q.push({0, {1, fish[1]}});
    while (q.size())
    {
        ll u = q.top().se.fi, du = q.top().fi, mask = q.top().se.se;
        q.pop();
        if (du != d[u][mask]) continue;
        for (pii tmp : adj[u])
        {
            ll v = tmp.fi, uv = tmp.se;
            ll newMask = mask | fish[v];
            if (d[v][newMask] > du + uv)
            {
                d[v][newMask] = du + uv;
                q.push({du + uv, {v, newMask}});
            }
        }
    }
    ll res = MOD;
    for (ll i = 0; i <= limit; i++)
    {
        for (ll j = 0; j <= limit; j++)
        {
            if ((i | j) == limit) minimize(res, max(d[n][i], d[n][j]));
        }
    }
    cout << res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("t.inp", "r", stdin);
    input();
    dijkstra();
    return 0;
}
