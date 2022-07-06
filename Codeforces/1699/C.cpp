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

const ll N = 1e5 + 5;

void solve(){
	ll n;
	cin >> n;

	ll a[n];
	map<ll, ll> index; 
	ll L, R;

	for(ll i = 0; i < n; i++){
		cin >> a[i];
		if (a[i] == 0) L = R = i;
		index[a[i]] = i;
	}
	ll ans = 1;

	for(ll i = 1; i < n; i++){
		if (L > index[i]) L = index[i];
		else if (index[i] > R) R = index[i];
		else {
			(ans *= (R - L + 1 - i)) %= MOD;
		}
	}
	cout << ans << '\n'; 
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