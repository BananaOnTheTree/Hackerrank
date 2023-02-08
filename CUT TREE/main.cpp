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
ll n, k;
ll dp[200][200], nxt[200][200];
vector <ll> adj[200];
void input()
{
    cin >> n >> k;
    ll u, v;
    for (ll i = 1; i < n; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void dfs(ll u, ll p)
{
    ll s = adj[u].size();
    dp[u][s] = nxt[u][s] = 1;
    for (ll v : adj[u])
    {
        if (v == p) continue;
        dfs(v, u);
        for (ll i = 0; i <= n; i++)
        {
            for (ll j = 0; j <= n; j++)
            {
                if (i + j < 2) continue;
                nxt[u][i + j - 2] += dp[u][i] * dp[v][j];
            }
        }
        for (ll i = 0; i <= n; i++)
        {
            dp[u][i] = nxt[u][i];
        }
    }
}
void solve()
{
    ll res = 1;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j <= k; j++)
        {
            //cout << i << " " << j << " " << dp[i][j] << '\n';
            res += dp[i][j];
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
    dfs(1, 1);
    solve();
    return 0;
}
