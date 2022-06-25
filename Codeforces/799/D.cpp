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

str s;
ll x;

bool check(string t){
    str p = t;
    reverse(p.begin(), p.end());
    if (t != p) return false;
    return true;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    ll t;
    cin >> t;
    while(t--){
	    cin >> s >> x;
   		ll a = (s[0] - '0') * 10 + (s[1] - '0');
    	ll b = (s[3] - '0') * 10 + (s[4] - '0');
    	map<ii,int> mymap;
    	ll res = 0;
    	while (mymap[{a, b}] == 0){
	        mymap[{a, b}] = 1;
	        b += x;
	        ll o = b / 60; 
	        b %= 60;
	        a += o; 
	        a %= 24;
	        str k = "";

	        if (a < 10) {
	            k += '0';
	            k += to_string(a);
	        } 
	        else k += to_string(a);

	        if (b < 10){
	            k += '0';
	            k += to_string(b);
	        } 
	        else k += to_string(b);
	        if (check(k)) res++;
	    }
	    cout << res << endl;
    }
    
    return 0;
}
