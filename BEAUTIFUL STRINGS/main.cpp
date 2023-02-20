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
string s;
ll get(ll num)
{
    return num * (num - 1) / 2;
}
void solve()
{
    ll n = s.length();
    s = s[0] + s;
    ll pre = 0, total = 0;
    vector <pair <char, ll>> ch;
    for (ll i = 1; i <= n; i++)
    {
        if (s[i] == s[i - 1]) pre++;
        else
        {
            ch.push_back({s[i - 1], pre});
            pre = 1;
        }
    }
    ch.push_back({s[n], pre});
    n = ch.size();
    pre = 0;
    for (ll i = 0; i < n; i++)
    {
        ll appear = ch[i].se;
        if (appear >= 2) total += get(appear) - 1;
        if (pre) total += appear * pre - i;
        if (i >= 2)
        {
            if (ch[i].fi == ch[i - 2].fi)
            {
                if (ch[i - 1].se == 1) total++;
            }
        }
        pre += appear;
    }
    cout << get((ll)s.length() - 1) - total;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("t.inp", "r", stdin);
    cin >> s;
    solve();
    return 0;
}
