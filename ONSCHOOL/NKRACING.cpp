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

const ll N = 1e6 + 5;

struct edge {
	ll u, v, w;
};

bool cmp(edge a, edge b) {
    return a.w > b.w;
}

ll n, m, cha[N], hang[N], ans;
edge e[N];

ll find(ll u) {
    if (cha[u] != u) cha[u] = find(cha[u]);
    return cha[u];
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n >> m;
	FOR(i,1,m) {
		cin >> e[i].u >> e[i].v >> e[i].w;
		ans += e[i].w;
	}
	sort(e + 1, e + m + 1, cmp);

	FOR(i,1,n){
        cha[i] = i;
        hang[i] = 0;
    }

	FOR(i,1,m) {
		ll u = find(e[i].u);
		ll v = find(e[i].v);	
		if (u == v) continue;
		cha[v] = u;	
		ans -= e[i].w;
	}

	cout << ans;
    
    return 0;
}
