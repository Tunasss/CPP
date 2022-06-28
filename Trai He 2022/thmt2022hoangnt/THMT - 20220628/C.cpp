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

const ll N = 1005;
ll n, m, a[N][N];

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    ll n, m;
    cin >> n >> m;
    // FOR(i,1,n) FOR(j,1,n) cin >> a[i][j];
    FOR(i,1,m){
    	ll x1, y1, x2, y2, val;
    	cin >> x1 >> y1 >> x2 >> y2 >> val;
    	a[x1][y1] += val;
    	a[x1][y2 + 1] -= val;
    	a[x2 + 1][y1] -= val;
    	a[x2 + 1][y2 + 1] += val;
    }
	FOR(i,1,n) {
		FOR(j,1,n){
			a[i][j] += a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
		}
	}
	FOR(i,1,n) {
    	FOR(j,1,n){
    		cout << a[i][j] << ' ';
    	}
    	el;
	}
    
    
    return 0;
}
