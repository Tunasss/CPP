#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;

ll Ceil(ll x, ll y)
{
    return (x + y - 1) / y;
}

const ll N = 1e7;

ll T[N], R[N];

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll m, n;
    cin >> m >> n;

    ll a[n + 1];
    ll sumA = 0, b[501] = {}, c[501] = {}, maxA = INT_MIN;

    for(ll i = 0; i < n; i++) {
        cin >> a[i];
        sumA += a[i];
        maxA = max(maxA, a[i]);
    }

    ll k = max(0ll, Ceil(m - 16 * sumA, maxA));
    b[maxA] = k;
    m -= maxA * k;

    T[0] = 0;
    for(ll i = 1; i <= m; i++) {
        T[i] = 1000;
        R[i] = -1;
    }

    for(ll j = 0; j < n; j++) {
        for(ll i = 1; i <= m; i++) {
            if(i >= a[j]){
                if (T[i - a[j]] + 1 < T[i]){
                    T[i] = 1 + T[i - a[j]];
                    R[i] = j;
                }
            }   
        }
    }

    if (R[m] == -1){
        cout << "-1";
        return 0;
    }

    ll st = m;
    while(st != 0){
        ll pos = R[st];
        b[a[pos]]++;
        st -= a[pos];
    }
    ll res = 0;

    for(ll i = 0; i < n; i++) {
        c[a[i]] = b[a[i]];
    }
    for(ll i = 0; i < n; i++) {
        res += c[a[i]];
        c[a[i]] = 0;
    }

    cout << res << '\n';

    for(ll i = 0; i < n; i++){
        cout << b[a[i]] << " ";
        b[a[i]] = 0;
    }

    return 0;
}