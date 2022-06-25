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

const ll N = 1e6 + 1;
ll n, s, x[N], y[N];

ll d(ll a, ll b, ll c){
	return abs((x[b] - x[a]) * (y[c] - y[a]) - (y[b] - y[a]) * (x[c] - x[a]));
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n >> s;
   	FOR(i,1,n) {
   		cin >> x[i] >> y[i]; 
   	}
   	ll a = 1, b = 2, c = 3;
	while(true){
		bool check = true;
		FOR(i,1,n) {
			ll cur = d(a, b, c);
			if (cur < d(i, b, c)) check = 0, a = i;
			if (cur < d(a, i, c)) check = 0, b = i;
			if (cur < d(a, b, i)) check = 0, c = i;
		}
		if (check) break;
	}
	cout << x[b] + x[c] - x[a] << ' ' << y[b] + y[c] - y[a] << endl;
	cout << x[a] + x[c] - x[b] << ' ' << y[a] + y[c] - y[b] << endl;
	cout << x[b] + x[a] - x[c] << ' ' << y[b] + y[a] - y[c] << endl;
    
    return 0;
}