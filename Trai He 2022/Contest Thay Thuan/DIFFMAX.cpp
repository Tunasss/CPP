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
#define el cout << endl;
#define all(v) (v).begin(), (v).end()
#define FOR(i,x,y) for(ll i = x; i <= y; i++)
#define FOS(i,x,y) for(ll i = x; i >= y; i--)
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

const ll N = 3 * 1e5 + 5;
ll n, k, a[N], f[N], d[N];
ll res = 0;

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    ll n, k;
    cin >> n >> k;
    FOR(i,1,n) cin >> a[i];
    d[1] = 1;
    f[1] = 1;
    ll minn = a[1], maxx = a[1];
    FOR(i,2,n){
        if (abs(a[i] - minn) <= k && abs(a[i] - minn) <= k){
            d[i] = d[i - 1] + 1;
            minn = min(a[i], minn);
            maxx = max(a[i], maxx);
        }
        else {
            d[i] = 1;
            minn = min(a[i], minn);
            maxx = max(a[i], maxx);
        }
        f[i] = max(f[i - 1], d[i]);
    }
    FOR(i,1,n){
        res = max(res, d[i] + f[i - d[i]]);
    }
    cout << res;
    return 0;
}
