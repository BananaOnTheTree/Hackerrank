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
    x %= MOD; y %= MOD;
    return (x + y) % MOD;
}
ll MINUS(ll x, ll y)
{
    x %= MOD, y %= MOD;
    while (x < y) x += MOD;
    return (x - y) % MOD;
}
//========================================================================0========================================================================//
ll a[MAX], s[MAX], n, Time[MAX], pre1, pre2, pre3, preDP, dp[MAX];
void input()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = (a[i] + s[i - 1]) % MOD;
    }
}
void solve()
{
    dp[1] = preDP = a[1];
    Time[1] = pre3 = 1;
    pre1 = pre2 = s[1];
    for (ll i = 2; i <= n; i++)
    {
        Time[i] = (Time[i - 1] * 2) % MOD;
        ll tmp = i * s[i] % MOD * Time[i] % MOD;
        tmp = MINUS(tmp, i * pre1 % MOD);
        tmp = MINUS(tmp, s[i] * pre3);
        tmp = ADD(tmp, pre2);
        pre1 = ADD(pre1, s[i] * Time[i] % MOD);
        pre2 = ADD(pre2, i * s[i] % MOD * Time[i] % MOD);
        pre3 = ADD(pre3, i * Time[i] % MOD);
        dp[i] = ADD(preDP, tmp);
        preDP = ADD(preDP, dp[i]);
    }
    cout << dp[n];
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
