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

const ll N = 105;
ll n;
vll a;

ll truyvet(ll x, ll cnt){
	if (cnt == 0) return 0;
	if (x % 3 == 0 && x >= 3){
		truyvet(x * 3, cnt--);

	}
	else{
		truyvet(x / 2, cnt--);
	}
}

void dequy(ll x, ll cnt){;
	if (cnt == n) return;

	if (x % 3 == 0 && x >= 3){
		if (find(a.begin(), a.end(), x / 3) - a.begin() < n) dequy(x / 3, cnt + 1);
		if (find(a.begin(), a.end(), x * 2) - a.begin() < n) dequy(x * 2, cnt + 1);
	}
	else {
		if (find(a.begin(), a.end(), x * 2) - a.begin() < n) dequy(x * 2, cnt + 1);
	}
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n;
	a.resize(n);
    FOR(i,0,n - 1){
    	cin >> a[i];
   	}
   	FOR(i,n-1,n-1){
   		dequy(a[i],0);
   		cerr << "ABCDE" << '\n';
   	}
    return 0;
}
