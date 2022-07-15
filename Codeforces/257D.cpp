#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int, int> ii;
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
#define FOR(i,x,y) for(ll i = x; i <= y; ++i)
#define FOS(i,x,y) for(ll i = x; i >= y; --i)
#define EACH(i,x) for (auto &(i) : (x))
#define el cout << '\n';
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

const ll N = 1e5 + 5;

void solve() {
    ll n;
    cin >> n;
    ll a[n + 1];

    FOR(i,1,n){
        cin >> a[i];
    }
    ll sum = 0;
    str res;

    FOS(i,n,1){
        if (sum < 0){
            sum += a[i];
            res.pb('+');
        }
        else{
            sum -= a[i];
            res.pb('-');
        }
    }

    if (sum < 0){
        FOR(i,0,n - 1){
            res[i] = (res[i] == '+' ? '-' : '+');
        }
    }
    
    reverse(res.begin(), res.end());

    cout << res; el;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    ll t = 1;
    while (t--) {
        solve();
    }

    return 0;
}