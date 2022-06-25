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

struct money {
	int st, nd, i;
};
const int N = 1001;
const int M = 11112;
int n, m, par[M], res[N];
money a[N];
ll d[M];
bool cmp(money a, money b) {
	return a.nd < b.nd || (a.nd == b.nd && a.st < b.st);
}
ll dp(int i) {
	if (i <= 0)
		return 0;
	if (d[i] != 0)
		return d[i];
	FOR(j, 1, n) {
		if (i - a[j].nd < 0)
			continue;
		while(a[j].nd == a[j + 1].nd)
			++j;
		if (dp(i - a[j].nd) + a[j].st > d[i]) {
			d[i] = dp(i - a[j].nd) + a[j].st;
			par[i] = i - a[j].nd;
		} 
	}
	return d[i];
}
void trace(int i) {
	if (i <= 0)
		return;
	FOR(j, 1, n) {
		if (dp(i - a[j].nd) + a[j].st == dp(i) && i - a[j].nd == par[i]) {
			++res[a[j].i];
			trace(i - a[j].nd);
			return;
		}
	}
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen(file".INP","r",stdin);
    //freopen(file".INP","w",stdout);

    cin >> n >> m;
    FOR(i, 1, n) {
    	int a, b;
    	cin >> a >> b;
    	::a[i].st = a;
    	::a[i].nd = b;
    	::a[i].i = i;
    }
    sort(a + 1, a + n + 1, cmp);
    cout << dp(m) << '\n';
    trace(m);
    FOR(i, 1, n)
    	cout << res[i] << ' ';
    return 0;
}
