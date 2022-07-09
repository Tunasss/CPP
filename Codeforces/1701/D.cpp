#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int, int> ii;
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

const ll N = 5e5 + 10;

ll a[N];
vector<ii> g[N];
ll n;

void solve(){
	cin >> n;
	vll ans(n + 1);

	FOR(i, 1, n) {
		g[i].clear();
		cin >> a[i];
	}

	priority_queue<ii, vector<ii>, greater<ii>> baque;

	FOR(i, 1, n) {
		ll L = i / (a[i] + 1) + 1;
		ll R = (a[i] == 0 ? n : i / a[i]);

		g[L].pb({R, i});
	}

	FOR(i, 1, n) {
		for (auto u : g[i])
		{
			baque.push(u);
		}
		auto p = baque.top();
		baque.pop();

		ans[p.nd] = i;	
	}
	FOR(i, 1, n) cout << ans[i] << " ";

	el;
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen(file".INP","r",stdin);
	//freopen(file".OUT","w",stdout);

	ll t = 1;
	if (true) cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}