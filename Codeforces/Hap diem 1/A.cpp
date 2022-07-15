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
#define FOR(i,x,y) for(ll i = x; i <= y; ++i)
#define FOS(i,x,y) for(ll i = x; i >= y; --i)
#define EACH(i,x) for (auto &(i) : (x))
#define el cout << '\n';
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

using namespace std;
const int N = 1e6 + 5;
 
ll a[N];
ll n, h;
 
bool check(ll x) {
	ll sum = 0;
	for (int i = 0; i < n - 1; i++) {
		sum += min(a[i + 1] - a[i], x);
		if (sum >= h) return true;
	}
	sum += x;
	if (sum >= h) return true;
	return false;
}
 
void solve() {
	cin >> n >> h;
	for (int i = 0; i < n; i++) cin >> a[i];
	ll L = 1, R = h;

	while(L < R) {
		ll M = (L + R) / 2;
		if (check(M)) R = M;
		else L = M + 1;
	}

	cout << L;el;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    ll t = 1;
    if (true) cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}