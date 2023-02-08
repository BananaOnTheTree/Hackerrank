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
    //x %= MOD, y %= MOD;
    if (x < y) x += MOD;
    return (x - y);
}
//========================================================================0========================================================================//
ll dp[MAX][4], n, res, cur[MAX];
vector <ll> adj[MAX];
bool HAVE_LEAF[MAX];
void input()
{
    cin >> n;
    for (ll i = 1; i < n; i++)
    {
        dp[i][0] = dp[i][1] = dp[i][2] = dp[i][3] = 1;
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dp[n][0] = dp[n][1] = dp[n][2] = dp[n][3] = 1;
}
void dfs(ll u, ll p)
{
    bool have_leaf = 0;
    dp[u][0] = dp[u][1] = dp[u][2] = dp[u][3] = 1;
    for (ll v : adj[u])
    {
        if (v != p)
        {
            if (adj[v].size() == 1)
            {
                have_leaf = 1;
            }
            else
            {
                dfs(v, u);
                dp[u][0] = dp[u][0] * (dp[v][0] + dp[v][1] + dp[v][2]) % MOD;
                dp[u][1] = dp[u][1] * (dp[v][0] + dp[v][1] + dp[v][3]) % MOD;
                dp[u][2] = dp[u][2] * dp[v][1] % MOD;
                dp[u][3] = dp[u][3] * dp[v][0] % MOD;
            }
        }
    }
    if (have_leaf)
    {
        dp[u][2] = dp[u][3] = 0;
    }
    dp[u][0] = MINUS(dp[u][0], dp[u][2]);
    dp[u][1] = MINUS(dp[u][1], dp[u][3]);
}
void DFS()
{
    stack <ll> st;
    st.push(1);
    while (st.size())
    {
        bool haveDFS = 0;
        ll par = -1;
        ll u = st.top();
        st.pop();
        if (st.size()) par = st.top();
        st.push(u);
        ll k = adj[u].size() - 1;
        while (cur[u] <= k)
        {
            ll v = adj[u][cur[u]];
            if (v != par)
            {
                if (adj[v].size() == 1)
                {
                    HAVE_LEAF[u] = 1;
                }
                else
                {
                    st.push(v);
                    haveDFS = 1;
                }
            }
            cur[u]++;
            if (haveDFS) break;
        }
        if (!haveDFS)
        {
            st.pop();
            if (HAVE_LEAF[u])
            {
                dp[u][2] = dp[u][3] = 0;
            }
            dp[u][0] = MINUS(dp[u][0], dp[u][2]);
            dp[u][1] = MINUS(dp[u][1], dp[u][3]);
            if (par != -1)
            {
                dp[par][0] = dp[par][0] * (ADD(dp[u][0], ADD(dp[u][1], dp[u][2]))) % MOD;
                dp[par][1] = dp[par][1] * (ADD(dp[u][0], ADD(dp[u][1], dp[u][3]))) % MOD;
                dp[par][2] = dp[par][2] * dp[u][1] % MOD;
                dp[par][3] = dp[par][3] * dp[u][0] % MOD;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("t.inp", "r", stdin);
    freopen("t.out", "w", stdout);
    input();
    DFS();
    res = dp[1][1] + dp[1][0];
    cout << res % MOD;
    return 0;
}
