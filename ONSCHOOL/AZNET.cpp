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

const ll N = 1e5 + 5;

struct edge{
	ll u,v,w;
};

ll n, m, u, v, c, A, B, x, y;
ll a[N], b[N], d[N], cha[N], hang[N];
edge e[N];

void init() {
	cin >> n >> m;
	FOR(i,1,n - 1) cin >> a[i];
	FOR(i,1,n - 1) cin >> b[i];
	FOR(i,1,m){
		cin >> e[i].u >> e[i].v >> e[i].w;
		A = B = d[i] = 0;
	}
}

void reset(){
	FOR(i,1,n) {
		cha[i] = i;
		hang[i] = 0;
	}
}

ll find(ll u) {
    if (cha[u] != u) cha[u] = find(cha[u]);
    return cha[u];
}

bool join(edge e) {
    u = find(e.u); 
    v = find(e.v);
    if (u == v) return false;
    if (hang[u] == hang[v]) hang[u]++;
    if (hang[u] < hang[v]) cha[u] = v;
    else cha[v] = u;
    return true;
}

void calculate_XY(){
	reset();
	FOR(i,1,m){
		if (e[i].w == 1) A += join(e[i]);
	}

	reset();
	FOR(i,1,m){
		if (e[i].w == 2) B += join(e[i]);
	}

	ll sum = 1e18 + 1;

	FOR(i, max(0LL,n - 1 - B), min(A, n - 1))
		if (sum > a[i] + b[n - 1 - i]) {
			sum = a[i] + b[n - 1 - i];
			x = i;
		}
	y = n - 1 - x;
}

void process(){
	FOR(i,1,m){
		if (e[i].w == 1) d[i] = join(e[i]);
	}

	reset();
	ll cnt = 0;

	FOR(i,1,m){
		if (d[i]) cnt += join(e[i]);
	}

	for (ll i = 1; i <= m && cnt < x; i++){
		if (e[i].w == 1 && !d[i]){
			cnt += (d[i] = join(e[i]));
		}
	}

	FOR(i,1,m){
		if (e[i].w == 2) d[i] = join(e[i]);
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
    	init();
    	calculate_XY();
    	process();

    	FOR(i,1,m){
			if (d[i]) cout << i << " ";
		}
    }
    
    return 0;
}
