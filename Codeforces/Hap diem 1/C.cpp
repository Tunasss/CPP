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

#define int long long

void solve(){
	int x1, p1, x2, p2;
    cin >> x1 >> p1 >> x2 >> p2;
    ll mp = min(p1, p2);
    p1 -= mp;
    p2 -= mp;
    if (p1 > 10) {
    	cout << '>' << '\n';
    }
    else 
    	if (p2 > 10) {
    	cout << '<' << '\n';
    }
    else {
        while(p1 > 0){
            x1 *= 10;
            p1--;
        }
        while(p2 > 0){
            x2 *= 10;
            p2--;
        }
        if (x1 > x2) {
        	cout << '>' << '\n';
        }
        if (x1 < x2) {
        	cout << '<' << '\n';
        }
        if (x1 == x2) {
        	cout << '=' << '\n';
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    ll t = 1;
    if (true) cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}