#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;
#define file "TEST"
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
#define FOS(i,x,y) for(ll i = x; i >= y; i--)
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

const ll N = 1e6;

ll res = 0;
ll a, b;
ll cnt[N + 5], f[N + 5], s[N + 5];

void init(){
    for (ll i = 2; i * i <= N; i++) if (!f[i])
        for (ll j = i; j <= N / i; j++) 
            if (!f[i * j]) f[i * j] = i;

    for (ll i = 2; i <= N; i++)
        if (!f[i]) f[i] = i;

    for (ll i = 2; i <= N; i++) {
        s[i] = 1;
        ll k = i, q = 0;
        while (f[k] != 0) {
            if (f[k] != q) {
                s[i] *= f[k];
                q = f[k];
            }
            k /= f[k];
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    init();
    
    cin >> a >> b;
    for (ll i = a; i <= b; i++) cnt[s[i]]++;
    for (ll i = 2; i <= N; i++) res += (cnt[i] * (cnt[i] - 1)) / 2;
    cout << res;
    
    return 0;
}