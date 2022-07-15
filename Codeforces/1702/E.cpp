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

const ll N = 3e5 + 5;

vll adj[N];
 
bool ok = true;
int color[N];

void dfs(int u){
	for (int v : adj[u]){
		if (color[v] == -1){
			color[v] = 1 - color[u];
			dfs(v);
		}
		else if (color[v] != 1 - color[u]){
			ok = false;
		}
	}
}
 

void solve(){
	int n;
	cin >> n;
 
	FOR(i,1,n){
		adj[i].clear();
	}
 
	vll fq(n + 1, 0);

	FOR(i,1,n){
		int u, v; 
		cin >> u >> v;

		adj[u].pb(v); 
		adj[v].pb(u);
		fq[u]++; 
		fq[v]++;
	}
 
	FOR(i,1,n){
		if (fq[i] != 2){
			cout << "NO";
			el;
			return;
		}
	}
 
	ok = true;
	FOR(i,1,n){
		color[i] = -1;
	}
 
	FOR(i,1,n){
		if (color[i] == -1){
			color[i] = 0;
			dfs(i);
		}
	}
 
	cout << (ok ? "YES" : "NO");
	el;
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