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

const ll N = 5e5 + 5;
ll a[N];

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    ll n,q;
    cin >> n >> q;
    FOR(i,0,n - 1) cin >> a[i];
    while(q--){
    	ll op;
    	cin >> op;
    	if (op == 1){
    		ll x, val;
    		cin >> x >> val;
    		a[x] = val;
    	}
    	if (op == 2){
    		ll L,R,val;
    		cin >> L >> R >> val;
    		ll res = LLONG_MAX; 
    		FOR(i,L,R){
    			if (a[i] >= val) res = min(res, a[i]);
    		}
    		cout << (res == LLONG_MAX ? -1 : res);
    		el;
    	}
    	if (op == 3){
    		ll L,R,val;
    		cin >> L >> R >> val;
    		ll res = -1; 
    		FOR(i,L,R){
    			if (a[i] <= val) res = max(res, a[i]);
    		}
    		cout << res;
    		el;
    	}
    }
    return 0;
}
