#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define file "SQUARE"

const ll N = 1e6;
 
ll lpf[N + 5];
ll cnt[N + 5];
 
void sieve(ll n) {
    memset(lpf, -1, sizeof(lpf));
 
    for (ll i = 2; i * i <= n; ++i) {
        if (lpf[i] == -1) {
            for (ll j = i * i; j <= n; j += i)
                if (lpf[j] == -1) lpf[j] = i;
        }
    }
    for (ll i = 2; i <= n; ++i)
        if (lpf[i] == -1)
            lpf[i] = i;
}
 
ll get(ll x) {
    ll res = 1;
    while (x > 1) {
        ll p = lpf[x], cnt = 0;
        while (x % p == 0) {
            x /= p;
            ++cnt;
        }
 
        if (cnt & 1) res *= p;
    }
    return res;
}
 
 
ll nC3(ll n) {
    return (n * (n - 1) * (n - 2) / 6);
}
ll nC2(ll n) {
    return n * (n - 1) / 2;
}
 
signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen(file".INP","r",stdin);
    // freopen(file".OUT","w",stdout);
 
    sieve(N);
    ll n;
    cin >> n;
    memset(cnt, 0, sizeof(cnt));
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        ++cnt[get(x)];
    }
 
    ll ans = nC3(cnt[1]);
    for (ll i = 2; i <= N; ++i) {
        ans += 1LL * nC2(cnt[i]) * cnt[1];
    }
    cout << ans << '\n';
 
    return 0;
}