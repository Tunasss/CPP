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
#define EACH(i,x) for(auto &(i) : (x))
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

const ll N = 1e6 + 5;
ll n, m, q;
bool vis[N], mark[N];
vll adj[N]; 
ll c[N], s[N], f[N];

void dfs(int i, int p = 0){
	vis[i] = 1;
	s[i] = c[i];
	EACH(j,adj[i]){
		if (mark[j] && !vis[j] && j != p){
			dfs(j,i);
			s[i] += f[j];
			f[i] += max(f[j],s[j]);
		}
	}
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    ll t;
    cin >> t;
    while(t--){
    	memset(f, 0, sizeof f);
    	memset(s, 0, sizeof s);

    	cin >> n >> m;
    	FOR(i,1,n) cin >> c[i];
    	FOR(i,1,m){
    		ll u,v;
    		cin >> u >> v;
    		u++, v++;
    		adj[u].pb(v);
    		adj[v].pb(u);
    	}
    	FOR(i,1,n){
    		EACH(j, adj[i]) dbg(j);
    		el;
    	}
    	cin >> q;
    	while(q--){
    		ll k;
    		cin >> k;
	    	memset(vis, 0, sizeof vis);
	    	memset(mark, 0, sizeof mark);
    		FOR(i,1,k){
    			ll tmp;
    			cin >> tmp;
    			mark[++tmp] = 1;
    		}
	    	ll res = 0;
	    	FOR(i,1,n){
	    		if (mark[i] && !vis[i]){
	    			dbge(i);
	    			dfs(i);
	    			res += max(f[i], s[i]);
	    			cerr << max(f[i], s[i]) << '\n';
	    		}
	    	}
	    	cout << res;
	    	el;
    	}
    }
    
    return 0;
}
