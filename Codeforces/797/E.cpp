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

const ll N = 2e5 + 5;
ll n, k, a[N], dem[N] = {};

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    ll t;
    cin >> t;
    while(t--){
    	cin >> n >> k;
    	ll res = 0;
    	FOR(i,1,n){
    		cin >> a[i];
    		res += a[i] / k;
    		dem[a[i] % k]++;
    	}
    	ll temp = (k + 1) / 2;
    	FOR(i,1,temp - 1){
    		dem[k - i] += dem[k - i + 1];
    		dem[k - i + 1] = 0;
    		ll minn = min(dem[i], dem[k - i]);
    		res += minn;
    		dem[i] = 0;
    		dem[k - i] -= minn;
    	}
    	dem[temp] += dem[temp + 1];
    	dem[temp + 1] = 0;
    	cout << res + dem[temp] / 2 << '\n';
    	dem[temp] = 0;
    }
    
    return 0;
}
