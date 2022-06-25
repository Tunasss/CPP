#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <ll,ll> ii;
typedef pair <ll,ii> iii;
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

const ll N = 5005;

bool cmp(iii a, iii b){
    if(a.nd.st == b.nd.st) return a.st < b.st;
    return a.nd.st < b.nd.st;
}

iii a[N];
ll n;
ll dp[N];

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    ll t;
    cin >> t;
    while(t--){
    	cin >> n;
    	
	    for(ll i = 0; i < n; i++) {
	        ll x, y, z;
	        cin >> x >> y >> z;
	        a[i] = {x, {x + y, z}};
	    }
	    ll ans = 0;
	    
	    sort(a, a + n, cmp);

	    for(ll i = 0; i < n; i++) {
	        dp[i] = a[i].nd.nd;
	        for(ll j = i - 1; j >= 0;--j){
	            if(a[i].st >= a[j].nd.st){
	                dp[i] = max(dp[i], dp[j] + a[i].nd.nd);
	            }
	        }
	        ans = max(ans,dp[i]);
	    }
	    cout << ans << '\n';
    }
    return 0;
}