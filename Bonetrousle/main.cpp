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
ll res[MAX], n, t, k, b, MIN_VAL, MAX_VAL, flag;
void input()
{
    flag = 0;
    cin >> n >> k >> b;
    ll tmp = n;
    for (ll i = 1; i <= b; i++)
    {
        res[i] = i;
        if (tmp > 0) tmp -= (k - i + 1);
    }
    MIN_VAL = (b + 1) * b / 2;
    MAX_VAL = (k + (k - b + 1)) * b / 2;
    if (MIN_VAL > n || tmp > 0) flag = 1;
}
void solve()
{
    if (flag)
    {
        cout << "-1\n";
        return;
    }
    ll remain = n - MIN_VAL;
    ll jump = k - b;
    if (jump)
    {
        ll step = remain / jump;
        remain %= jump;
        for (ll i = 1; i <= step; i++) res[b - i + 1] += jump;
        res[b - step] += remain;
    }
    for (ll i = 1; i <= b; i++) cout << res[i] << " ";
    cout << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("t.inp", "r", stdin);
    cin >> t;
    while (t--)
    {
        input();
        solve();
    }
    return 0;
}
