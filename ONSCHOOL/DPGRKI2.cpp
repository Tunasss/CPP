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
#define all(v) (v).begin(), (v)end()
#define FOR(i,x,y) for(ll i = x; i <= y; i++)
#define FOS(i,x,y) for(ll i = x; i >= y; i--)
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

const ll maxn = 1005;
ll n, m, a[maxn][maxn], d[maxn][maxn];
ll res = INT_MIN;

ll dp(int i, int j) {
	if (i > n || i <= 0 || j <= 0)
		return 0;
	if (d[i][j] != 0)
		return d[i][j];

    d[i][j] = INT_MIN;
	if (i - 1 > 0)
        d[i][j] = max(d[i][j], dp(i - 1, j - 1) + a[i][j]);
    if (i + 1 <= n)
        d[i][j] = max(d[i][j], dp(i + 1, j - 1) + a[i][j]);
    d[i][j] = max(d[i][j], dp(i, j - 1) + a[i][j]);
	return d[i][j];
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> m;

    FOR(i,1,n){
    	FOR(j,1,m){
    		cin >> a[i][j];
    	}
    }

    FOR(i,1,n){
    	res = max(res, dp(i, m));
    }

    cout << res;
    return 0;
}