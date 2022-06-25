#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;
#define file "VITRITOT"
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

const ll N = 1e7;
const ll M = 6e5 + 1;
ll n;
ll a[N];
vll f(N, INT_MAX);

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".INP","r",stdin);
    freopen(file".OUT","w",stdout);

    cin >> n;
    for (ll i = 1 + M; i <= n + M; i++) cin >> a[i];

    for (ll j = 1 + M; j <= n + M; j++){
        for (ll i = 1 + M; i <= j; i++){
            ll temp = a[i] + a[j] + M;
            f[temp] = min(f[temp], j);
        }
    }

    ll res = 0;
    for (ll x = 1 + M; x <= n + M; x++) {
        for (ll k = 1 + M; k < x; k++) {
            ll temp = a[x] - a[k] + M;
            if (f[temp] <= k) {
                res++;
                break;
            }
        }
    }
    cout << res;
    
    return 0;
}