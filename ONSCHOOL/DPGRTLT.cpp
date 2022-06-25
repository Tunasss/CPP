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

const ll INF = INT_MAX;
const ll N = 1001;
ll n, m, x, y, a[N][N], f[N][N];

ll dp(ll i, ll j){
	if (i > n || j > m || i < 0 || j < 0) 
		return 0;
	if (f[i][j] != INF) 
		return f[i][j];
	f[i][j] = max(dp(i, j - 1) - a[i][j], dp(i - 1, j) - a[i][j]);
	return f[i][j];
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    cin >> n >> m;
    cin >> x >> y;
    for (ll i = 1; i <= n; i++){
    	for (ll j = 1; j <= m; j++){
    		cin >> a[i][j];
    		f[i][j] = INF;
    	}
    }
    f[x][y] = a[x][y];
    if (dp(n,m) < 0){
    	cout << "N";
    }
    else cout << "Y " << dp(n,m);
    
    return 0;
}
