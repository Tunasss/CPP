#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define file "SXOR"

#define FOR(i,x,y) for(ll i = x; i <= y; ++i)
#define getbit(a, b) (((a) >> (b)) & 1)
#define count_zero(a) (__builtin_clz(a))

const ll N = 100;
ll n, m, d[N][2][2];

ll dp(ll i, ll a, ll b) {
    if (i == m) return 1;
    if (d[i][a][b] != -1) return d[i][a][b];

    ll &res = d[i][a][b];
    res = 0;

    ll maxa = ((a)? getbit(n, m - i - 1) : 1);
    ll maxb = ((b)? getbit(n, m - i - 1) : 1);

    FOR(x, 0, maxa){
        FOR(y, 0, maxb){
            if (x + y < 2){
                res += dp(i + 1, a & (x == maxa), b & (y == maxb));
            }
        }
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(file".INP","r",stdin);
    // freopen(file".OUT","w",stdout);
    
    cin >> n;
    m = 32 - count_zero(n);
    memset(d, -1, sizeof d);
    cout << dp(0, 1, 1); 

    return 0;
}