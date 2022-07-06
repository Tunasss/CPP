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
	ll n,m;
	cin >> n >> m;
	ll a[n + 5][m + 5];

	ll c = 1;

	for (ll i = 1; i <= n; i += 2){
		if (c){
			bool flag = 1;
			for (ll j = 1; j <= m; j += 2){
				if (flag){
					a[i][j] = 1;
					a[i][j + 1] = 0;
					a[i + 1][j] = 0;
					a[i + 1][j + 1] = 1;
					flag = 0;
				}
				else{
					a[i][j] = 0;
					a[i][j + 1] = 1;
					a[i + 1][j] = 1;
					a[i + 1][j + 1] = 0;
					flag = 1;
				}
			}
			c = 0;
		}
		else{
			bool flag = 0;
			for (ll j = 1; j <= m; j += 2){
				if (flag){
					a[i][j] = 1;
					a[i][j + 1] = 0;
					a[i + 1][j] = 0;
					a[i + 1][j + 1] = 1;
					flag = 0;
				}
				else{
					a[i][j] = 0;
					a[i][j + 1] = 1;
					a[i + 1][j] = 1;
					a[i + 1][j + 1] = 0;
					flag = 1;
				}
			}
			c = 1;
		}
		
	}

	for (ll i = 1; i <= n; i++){
		for (ll j = 1; j <= m; j++){
			cout << a[i][j] << ' ';
		}
		el;
	}
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