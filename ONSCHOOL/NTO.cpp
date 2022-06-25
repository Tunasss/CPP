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
const ll SIZE = 1000005;
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

bool check[SIZE];
void sang (){
  	for (ll i = 2; i <= SIZE; i++) {
    	check[i] = true;
  	} 
  	for (ll i = 2; i <= SIZE; i++) {
    	if (check[i]) {
      		for (ll j = 2 * i; j <= SIZE; j += i) {
        		check[j] = false;
      		}
    	}
  	}
}

bool nto (ll n){
	if (check[n]) return true;
	else return false;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    sang();
    ll t;
    cin >> t;
    vll dp(SIZE);
    dp[0] = 0;
    dp[1] = 0;
    for (ll i = 2; i <= SIZE; i++){
    	if (nto(i)){
    		dp[i] = dp[i - 1] + 1;
    	}
    	else dp[i] = dp[i - 1] + 0;
    }
    while(t--){
    	ll l,r;
    	cin >> l >> r;
    	cout << dp[r] - dp[l - 1]<< "\n";
    }
    
    return 0;
}
