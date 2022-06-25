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

str s,s1,s2;
ll x,y,z;
ll dp[N][N][N] = {};

void solve(){
	cin >> x >> y >> z;
    cin >> s >> s1 >> s2;
    FOR(i,1,x){
        FOR(j,1,y){
            FOR(k,1,z){
                if(s[i - 1] == s1[j - 1] && s1[j - 1] == s2[k - 1])    {
                    dp[i][j][k] = dp[i - 1][j - 1][k- 1] + 1;
                }
                else dp[i][j][k] = max(max(dp[i - 1][j][k],dp[i][j - 1][k]),dp[i][j][k - 1]);
            }
        }
    }
    cout << dp[x][y][z] << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    ll t;
    cin >> t;
    while(t--){
    	solve();
    }
    
    return 0;
}
