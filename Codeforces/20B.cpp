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
	long double a, b, c;
	cout << fixed << setprecision(15);
	cin >> a >> b >> c;
	if(a == 0 && b == 0 && c == 0) {
		cout << -1;
		return;
	}
	if(a == 0 && b == 0) {
		cout << 0 << endl;
		return; 
	}
	if(b == 0) {
		if(-c/a < 0) {
			cout << 0;
			return;
		}
		cout << 1 << endl << sqrt(-c/a);
		return;	
	}
	if(a == 0) {
		cout << 1 << endl << -c / b;
		return;
	}
	long double d = b * b - 4 * a * c;
	if(d < 0) {
		cout << 0;
		return;
	} else if(d == 0) {
		cout << 1 << endl;
		long double x1 = (-b + sqrt(d)) / (2 * a);
		cout << x1;
		return; 
	} else {
		long double x1 = (-b + sqrt(d)) / (2 * a);
		long double x2 = (-b - sqrt(d)) / (2 * a);
		cout << 2 << endl << min(x1, x2) << endl << max(x1, x2);
		return;
	}
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    ll t = 1;
    while(t--){
        solve();
    }
    
    return 0;
}