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

const ll N = 260;
ll a[N];

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    ll n,m,k;
    cin >> n >> m >> k;
    FOR(i,1,n){
    	char x;
    	cin >> x;
    	if (x == 'A') a[i] = 1;
    	else if (x == 'B') a[i] = 2;
    }

    ll res = 0;
    FOR(i,1,n - k + 1){
    	ll dem = 0;
    	for(ll j = i; j < i + m; j++){
    		if (j > n + 1) break;

    		if (dem == k){
    			res++;
    		}

    		if (a[j] == 1) {
    			dem++;
    			if (dem > k) continue;
    		}
    	}
    }
    cout << res;
    return 0;
}
