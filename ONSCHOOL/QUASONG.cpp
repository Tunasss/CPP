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

const ll N = 1e6 + 5;

ll n, k, L[N], R[N]; 
ll dp[N] = {0, 1}, sum[N] = {0, 1};

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n >> k;
    FOR(i,1,k) cin >> L[i] >> R[i];

    for (ll i = 2; i <= n; i++){
        for(ll j = 1; j <= k; j++){
        	ll l = max(0LL, i - L[j]);
            ll r = max(0LL, i - R[j] - 1);
            dp[i] = (dp[i] % MOD) + (((sum[l] % MOD) - (sum[r] % MOD) + MOD) % MOD) %= MOD;
        }
        sum[i] = (sum[i - 1] + dp[i]) % MOD;
    }
    cout << dp[n];
    
    return 0;
}
