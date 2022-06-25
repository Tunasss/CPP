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

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    ll m, n, k, s, dem = 0;
    cin >> m >> n >> k >> s;
    ll f[m + 1][n + 1];

    for(ll i = 1; i <= m; i++){
    	for(ll j = 1; j <= n; j++){
    		f[i][j] = 0;
    	}
    }

    while(k--){
    	ll x,y,u,t;
    	cin >> x >> y >> u >> t;

    	for(ll i = x; i <= u; i++){
    		for(ll j = y; j <= t; j++){
    			f[i][j]++;
    		}
    	}

    }
    for(ll i = 1; i <= m; i++){
    	for(ll j = 1; j <= n; j++){
    		if (f[i][j] == s - 1) dem++;
    		// cout << f[i][j] << " ";
    	}
    	// cout << endl;
    }
    cout << dem;
    
    return 0;
}
