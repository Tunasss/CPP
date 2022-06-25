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

ll n, r, avg, sum = 0, res = 0;
ii a[SIZE];

ll cmp(ii a, ii b){
	if (a.nd == b.nd) return a.st < b.st;
	return a.nd < b.nd;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n >> r >> avg;
    FOR(i,1,n){
    	cin >> a[i].st >> a[i].nd;
    	sum += a[i].st;
    }
    sort(a + 1, a + 1 + n, cmp);

    avg *= n;

    FOR(i,1,n){
    	if (sum >= avg) break;

    	ll diff = r - a[i].st;
    	if (diff <= 0) continue;

		if (diff < avg - sum){
			res += (a[i].nd * diff);
			sum += diff;
		}
		else{
			res += (a[i].nd * (avg - sum));
			sum += avg - sum;
		}
    }
    cout << res;

    return 0;
}