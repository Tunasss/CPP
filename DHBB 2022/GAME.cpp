#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define file "GAME"
#define FOR(i,x,y) for(ll i = x; i <= y; ++i)
#define el cout << '\n';
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;

const ll N = 1e5 + 5;

ll n, a[N], r;

struct P{
	ll d;
	ll L;
	ll R;
};

struct cmp{
	bool operator() (P x, P y){
		if (x.d == y.d){
			return (x.R - x.L) < (y.R - y.L);
		}
		return x.d < y.d;
	}
};	

priority_queue<P, vector<P>, cmp> num;

void DBG(){
	cerr << "\n############\n";
	FOR(i,1,n) cerr << a[i] << ' ';
	cerr << "\n############\n\n";
}

void update(ll L, ll R){
	for (ll i = L; i <= R; i++){
		a[i] -= 1;
	}

	// DBG();

	for (ll i = L; i <= R; i++) {
		if (a[i] != 0) {
			ll dem = 0;
			ll j = i;
			for (; j <= n; j++) {
				if (a[j] == 1) dem++;
				if (a[j] == 0) break;
			}
			num.push({dem, i, j - 1});
			i = j;
		}
	}
}


signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	// freopen(file".INP","r",stdin);
	// freopen(file".OUT","w",stdout);

	cin >> n >> r;
	for (ll i = 1; i <= n; i++) cin >> a[i];

	for (ll i = 1; i <= n; i++) {
		if (a[i] != 0) {
			ll dem = 0;
			ll j = i;
			for (; j <= n; j++) {
				if (a[j] == 1) dem++;
				if (a[j] == 0) break;
			}
			num.push({dem, i, j - 1});
			i = j;
		}
	}

	ll res = 0;

	while(r--){
		P x = num.top();
		// dbg(x.d), dbg(x.L), dbge(x.R);
		num.pop();
		update(x.L, x.R);
	}		

	FOR(i,1,n) res += (a[i] == 0);
	cout << res;
	return 0;
}
