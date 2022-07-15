#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;
#define file "TABLE"
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

const ll N = 505;
ll a[N][N], sum[N][N];
ll m, n, q, x, y, u, v, w;

void update(){
	memset(sum, 0, sizeof sum);
	sum[1][1] = a[1][1];
	FOR(i,1,m){
		FOR(j,1,n){
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
		}
	}
}

ll DBG(ll x, ll y, ll u, ll v){
	ll S = 0;
	FOR(i,x,u){
		FOR(j,y,v){
			S += a[i][j];
		}
	}
	return S;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen(file".INP","r",stdin);
    // freopen(file".OUT","w",stdout);
    cin >> m >> n >> q;

    FOR(i,1,m){
    	FOR(j,1,n){
    		cin >> a[i][j];
    	}
    }
    bool check = 0;
    while(q--){
    	ll type; cin >> type;
    	if (type == 1){
    		check = 0;
    		cin >> x >> y >> u >> v >> w;
    		FOR(i,x,u){
    			FOR(j,y,v){
    				a[i][j] += w;
    			}
    		}
    	}
    	if (type == 2){
    		if (!check) {
    			// cerr << "SHESHHHHHHHH!\n";
    			update();
    		}
    		cin >> x >> y >> u >> v;

    		// ll CHECKER = DBG(x,y,u,v);
    		ll res = sum[u][v] - sum[x - 1][v] - sum[u][y - 1] + sum[x - 1][y - 1];

    		// dbg(CHECKER), dbge(res);
    		cout << res;
    		el;

    		check = 1;
    	}
    }
    return 0;
}
