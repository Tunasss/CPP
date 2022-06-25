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

const ll INF = INT_MIN;
const ll N = 1005;
ll n, m, a[N][N], f[N][N];
vector <ii> res;

ll dp(ll i, ll j){
	if (i < 1 || j < 1) 
		return INF;
	if (f[i][j] != INF) 
		return f[i][j];
	f[i][j] = max(dp(i - 1, j), dp(i, j - 1)) + a[i][j];
	return f[i][j];
}

void backtrace(ll i, ll j){
	if (i <= 1 && j <= 1) return;

	if (f[i][j] == dp(i - 1, j) + a[i][j]){
		res.pb({i - 1, j});
		backtrace(i - 1, j);
	}

	else if (f[i][j] == dp(i, j - 1) + a[i][j]){
		res.pb({i, j - 1});
		backtrace(i, j - 1);
	}
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    
    cin >> n >> m;
    for (ll i = 1; i <= n; i++){
    	for (ll j = 1; j <= m; j++){
    		cin >> a[i][j];
    		f[i][j] = INF;
    	}
    }

    f[1][1] = a[1][1];
    cout << dp(n,m) << '\n';

    res.pb({n,m});
    backtrace(n,m);
    cout << res.size() << '\n';

    for (ll i = res.size() - 1; i >= 0; i--){
    	cout << res[i].st << ' ' << res[i].nd << '\n';
    }
    return 0;
}
