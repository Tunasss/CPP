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
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

const ll N = 20;
ll c[N][N], n;
ll mem[N][1 << N];

int tsp(int i, int S){
	if (S == (1 << N) - 1) return c[i][0];
	if (mem[i][S] != -1) return mem[1][S];
	ll res = LLONG_MAX;
	FOR(j, 0, N - 1){
		if (S & (1 << j)) continue;
		res = min(res, c[i][j] + tsp(j, S | (1 << j)));
	}
	mem[i][S] = res;
	return res;
}
void backtrace(int i, int S){
	cout << i << ' ';
	if (S == (1 << N) - 1) return;
	ll res = mem[i][S];
	FOR(j, 0, N - 1){
		if (S & (1 << j)) continue;
		if (res == c[i][j] + mem[j][S | (1 << j)]){
			backtrace(j, S | (1 << j));
			break;
		}
	}
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    memset(mem, -1, sizeof mem);
    cin >> n;
    FOR(i,1,2 * n + 1){
    	FOR(j,1,2 * n + 1){
    		cin >> mem[i][j];
    	}
    }
    cout << tsp(0, 1 << 0) << '\n';
    backtrace(0, 1 << 0);
    return 0;
}
