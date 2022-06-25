#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <ll,ll> ii;
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

const ll N = 1001; 

pair <ll,ii> product[N];
ll c[N];
bool learned[N];

ll n, m, t, p, res = 0;

ll cmp (pair <int,ii> x, pair <int,ii> y){
	return x.st > y.st;
	if (x.st == y.st){
		return x.nd < y.nd;
	}
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n >> m;
    
    FOR(i,1,n) cin >> c[i];

    FOR(i,1,m){
    	cin >> t >> p;
    	ll s[p + 1];

    	FOR(i,1,p){
    		cin >> s[i];
    	}
    	if (p == 1){
    		product[i] = {t, {s[1],0}};
    	}
    	else if (p <= 2){
    		product[i] = {t, {s[1],s[2]}};
    	}
    }
    
    sort(product + 1, product + n + 1, cmp);

    ll res = 0;
    learned[0] = true;

    FOR(i,1,m){
    	ll t = product[i].st;
    	ll s1 = product[i].nd.st;
    	ll s2 = product[i].nd.nd;

    	// dbge(cal);

    	ll cost = 0;
    	if (learned[c[s1]] == false){
    		cost += c[s1];
    		if (learned[c[s2]] == false){
    			cost += c[s2];
    		}
    	}
    	if (res < res + t - cost){
    		res = res + t - cost;
    		learned[s1] = true;
    		learned[s2] = true;
    	}

    	// dbge(res);
    	// dbg(t); dbg(s1); dbge(s2);
    }
    cout << res;
    return 0;
}
