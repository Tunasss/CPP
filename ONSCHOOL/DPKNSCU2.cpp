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

const ll M = 505;
const ll N = 105;
ll m, n;
ll a[N], b[N];
ll s[N][M] = {};

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    while(1){
    	ll n, m;
	    cin >> m >> n;
	    if (m == 0 && n == 0) break;

	    ll a[n + 5], b[n + 5];
	    for(ll i = 1; i <= n; i++){
	        cin >> b[i] >> a[i];
	    }
	    memset(s, 0, sizeof(s));
	    for(ll i = 1; i <= n; i++){
	        for(ll j = 1; j <= m; j++){
	        	s[i][j] = max(s[i - 1][j], s[i][j - 1]);
		        if(b[i] <= j){
		            s[i][j] = max(s[i - 1][j], s[i - 1][j - b[i]] + a[i]);
		        }
		    }
		}
		ll sumC = 0, sumV = 0;

	    for (ll i = 1; i <= m; i++){
	    	if (s[n][i] > sumC){
	    		sumC = s[n][i];
				sumV = i;
	    	}
	    }

	    cout << sumV << ' ' << sumC << '\n';
    }
    return 0;
}
