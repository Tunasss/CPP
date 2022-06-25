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

const int N = 101;
const int M = 25001;
int t, n, a[N], d[M], sum = 0, res = INT_MAX;

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    ll t;
    cin >> t;
    while(t--){
    	cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
			sum += a[i];
		}
		d[0] = 1;
		for (int i = 1; i <= n; ++i) {
			for (int j = sum / 2; j > 0; --j)
				if (j - a[i] >= 0)
					d[j] += d[j - a[i]];
		}
		for (int i = 1; i <= sum / 2; ++i)
			if (d[i] != 0)
				res = min(res, abs(sum - i * 2));
		cout << res << '\n';
		memset(d, 0, sizeof d);
		sum = 0;
		res = INT_MAX;
    }
    

    return 0;
}
