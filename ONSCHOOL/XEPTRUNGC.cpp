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

const ll N = 1e7 + 5;
ll n, m, a[N + 5], res = 0;
ll sum = 0, maxx = INT_MIN;

bool check (ll res){
	ll dem = 1, s = 0;
	FOR(i,1,n){
		if (s + a[i] > res){
			if (a[i] > res) return false;

			dem++;
			if (dem > m) return false;
			s = a[i];
		}
		else s += a[i]; 
	}
	return true;
}

void bs(ll l, ll r){
	while(l <= r){
		ll mid = (l + r)/ 2;
		if (check(mid)){
			res = mid;
			r = mid - 1;
			// dbge(res);
		}
		else l = mid + 1;
	}
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
   	cin >> n >> m;
    FOR(i,1,n){
    	cin >> a[i];
    	sum += a[i];
    	maxx = max(a[i], maxx);
    } 
    bs(maxx, sum);
    cout << res;
    return 0;
}
