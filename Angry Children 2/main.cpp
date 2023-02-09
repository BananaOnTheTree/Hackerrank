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
ll n, k, a[MAX];
void input()
{
    cin >> n >> k;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
}
void solve()
{
    ll res = 0, tmp, sum = 0;
    for (ll i = 1; i <= k; i++)
    {
        sum += a[i];
        res += (2 * i - 1) * a[i];
    }
    res -= k * sum;
    tmp = res;
    for (ll i = k + 1; i <= n; i++)
    {
        sum -= a[i - k];
        tmp = tmp - a[i - k] - 2 * sum + (2 * k - 1) * a[i] + k * (a[i - k] - a[i]);
        sum += a[i];
        minimize(res, tmp);
    }
    cout << res;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("t.inp", "r", stdin);
    input();
    solve();
    return 0;
}
