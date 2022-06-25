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

const ll N = 101;
const ll M = 1e3  * 101;
ll n, m, sum = 0, res = 0;
ll w[N], v[N], dp[N][M] = {};

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n >> m;
    FOR(i,1,n){
    	cin >> w[i] >> v[i];
        sum += v[i];
    }

    FOR(j,1,sum) dp[0][j] = INT_MAX;

    FOR(i,1,n){
        FOR(j,1,sum){
            dp[i][j] = dp[i - 1][j];
            if (j - v[i] >= 0){
                dp[i][j] = min(dp[i - 1][j - v[i]] + w[i], dp[i][j]);
            }
        } 
    }

    FOR(j,1,sum){
        if (dp[n][j] <= m)
            res = max(res, j);
    }
    cout << res;
    
    return 0;
}
