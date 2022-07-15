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

const ll N = 1e5 + 5;

ll dis[2][N];
bool vis[2][N];
set<ll> adj[N];

void BFS(ll s, ll t, ll id){
	queue<ll> q;
	q.push(s);
	vis[id][s] = 1;

	while(q.size() != 0){
		ll u = q.front();
		q.pop();
		for(auto v : adj[u]){
			if (vis[id][v]) continue;
			q.push(v);
			vis[id][v] = 1;
			dis[id][v] = dis[id][u] + 1;
		}
	}
}

void solve(){
	ll n, m, s, t;
	cin >> n >> m >> s >> t;
   	FOR(i,1,m){
    	ll u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
 
    BFS(s, t, 0);
    BFS(t, s, 1);
 
    int p = dis[0][t];
    ll ans = 0;

    FOR(i,1,n){
        FOR(j,i + 1,n){
            if(adj[i].find(j) != adj[i].end()){
                continue;
            }
            if(dis[0][i] + dis[1][j] + 1 >= p && dis[0][j] + dis[1][i] + 1 >= p && adj[i].find(j) == adj[i].end()){
                ans++;
            }
        }
    }
    cout << ans;
    el;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    ll T = 1;
    // if (true) cin >> t;
    while(T--){
        solve();
    }
    
    return 0;
}