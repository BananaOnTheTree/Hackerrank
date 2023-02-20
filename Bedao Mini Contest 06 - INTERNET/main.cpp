#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define FORU(i , a , b) for(int i = a ; i <= b ; i++)
#define FORD(i , a , b) for(int i = a ; i >= b ; i--)
using namespace std;
const int MAX = 1e6 + 10, MOD = 727355608;
void unset(int &t, int pos)
{
    t &= (~(1ll << (pos - 1)));
}
void onset(int &t, int pos)
{
    t |= (1ll << (pos - 1));
}
int getbit(int i,int k)
{
    return (k >> (i - 1)) % 2;
}
void minimize(int &x, int y)
{
    x = min(x, y);
}
void maximize(int &x, int y)
{
    x = max(x, y);
}
int ADD(int x, int y)
{
    return (x + y) % MOD;
}
int MINUS(int x, int y)
{
    x %= MOD, y %= MOD;
    if (x < y) x += MOD;
    return (x - y) % MOD;
}
//========================================================================0========================================================================//
int numOdd = 0, a, b, c, s;
int pow(int y)
{
    if (!y) return 1;
    if (y == 1) return 4;
    int ret = pow(y / 2);
    ret = ret * ret % MOD;
    if (y % 2) ret = ret * 4 % MOD;
    return ret;
}
void solve()
{
    vector <pii> v;
    v.push_back({1, a});
    v.push_back({2, b});
    v.push_back({3, c});
    int res = 0, tmp = a + b + c;
    int half = s / 2, j = 2;
    numOdd = (a % 2) + (b % 2) + (c % 2);
    if ((numOdd > 1) || (a + b + c > s) || (tmp == 1))
    {
        cout << "Bedao!";
        return;
    }
    else if (!tmp)
    {
        if (!s) cout << "0";
        else cout << "Bedao!";
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        if (v[i].se % 2)
        {
            if (s % 2 == 0)
            {
                cout << "Bedao!";
                return;
            }
            tmp--;
            res = ADD(res, (i + 1) * pow(half));
        }
        v[i].se /= 2;
    }
    tmp /= 2;
    for (half = half - 1; half >= 0; half--)
    {
        if (tmp == 1 && half) continue;
        tmp--;
        while (!v[j].se) j--;
        v[j].se--;
        res = ADD(res, (j + 1) * ADD(pow(s - 1 - half), pow(half)) % MOD);
    }
    cout << res;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("t.inp", "r", stdin);
    cin >> s >> a >> b >> c;
    solve();
    return 0;
}
