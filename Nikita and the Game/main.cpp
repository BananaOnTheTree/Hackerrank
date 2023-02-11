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
ll a[MAX], n;
bool allZero;
void input()
{
    allZero = 1;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i]) allZero = 0;
        a[i] += a[i - 1];
    }
}
ll get(ll l, ll r)
{
    return a[r] - a[l - 1];
}
ll solve(ll l, ll r)
{
    ll l1 = l, r1 = r, m;
    while (l <= r)
    {
        m = (l + r) / 2;
        ll leftPart = get(l1, m);
        ll rightPart = get(m + 1, r1);
        if (leftPart == rightPart)
            return max(solve(l1, m), solve(m + 1, r1)) + 1;
        else if (leftPart < rightPart) l = m + 1;
        else r = m - 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("t.inp", "r", stdin);
    ll t;
    cin >> t;
    while (t--)
    {
        input();
        if (allZero) cout << n - 1 << '\n';
        else cout << solve(1, n) << '\n';
    }
    return 0;
}
