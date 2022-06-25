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

ll n, m, a, b;
bool check (ll x){
	str s = to_string(x);
	s = ' ' + s;
	for(ll i = 1; i < s.size(); i++){
		if (i % 2 != 0){
			if (s[i] == m) return false; 
		} 
		else if (i % 2 == 0){
			if (s[i] != m) return false;
		}
	}
	if (x < 10 && x != m) return true;
	return true;
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    cin >> n >> m >> a >> b;
    ll cnt = 0;
    for (ll i = a; i <= b; i++){
    	if (i % n == 0 && check(i)){
    		cnt++;
    		dbge(i);
    	}
    }
    cout << cnt;
    
    return 0;
}

