#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;
#define file "SQUARE"
#define st first
#define nd second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define bin binary_search
#define vll vector<ll>
#define vi vector<int>
#define all(v) (v).begin(), (v).end()
#define FOR(i,x,y) for(ll i = x; i <= y; i++)
#define FOS(i,x,y) for(ll i = x; i >= y; --i)
#define EACH(i,x) for (auto &(i) : (x))
#define el cout << '\n';
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

const ll N = 2e6 + 5;

ll check[N + 1];
ll cnt[N];
 
void process(ll n) {
    memset(check, -1, sizeof(check));
 
    for (ll i = 2; i * i <= n; i++) {
        if (check[i] == -1) {
            for (ll j = i * i; j <= n; j += i)
                if (check[j] == -1) check[j] = i;
        }
    }
    for (ll i = 2; i <= n; i++)
        if (check[i] == -1)
            check[i] = i;
}
 
ll get(ll x) {
    ll res = 1;
    while (x > 1) {
        ll p = check[x], cnt = 0;
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

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen(file".INP","r",stdin);
    // freopen(file".OUT","w",stdout);
    
    process(N);
    ll n;
    cin >> n;
    memset(cnt, 0, sizeof(cnt));

    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        ++cnt[get(x)];
    }
 
    ll ans = nC3(cnt[1]);
    for (ll i = 2; i <= N; i++) {
        ans += 1LL * nC2(cnt[i]) * cnt[1];
    }
    cout << ans;

    return 0;
}