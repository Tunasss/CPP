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

const int N = 5005;
 
string s;
int n, dp[N][N], ans[N];

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> s;
    n = (int) s.size();
    
    for (int len = 1; len <= n; len++) {
        for (int l = 0; l < n - len + 1; l++) {
            int r = l + len;
            
            if (len == 1) {
                dp[l][r] = 1;
                continue;
            } else if (len == 2) {
                dp[l][r] = (s[l] == s[r - 1] ? 2 : 0);
                continue;
            }
            
            if (s[l] != s[r - 1] || !dp[l + 1][r - 1]) {
                continue;
            }
            
            dp[l][r] = 1;
            int m = (l + r) / 2;
            
            if (len & 1) {
                if (dp[l][m] && dp[m + 1][r]) {
                    dp[l][r] = dp[l][m] + 1;
                }
            } else {
                if (dp[l][m] && dp[m][r]) {
                    dp[l][r] = dp[l][m] + 1;
                }
            }
        }
    }
    
    for (int len = 1; len <= n; len++) {
        for (int l = 0; l < n - len + 1; l++) {
            ans[dp[l][l + len]]++;
        }
    }
    
    for (int i = n - 1; i >= 1; i--) {
        ans[i] += ans[i + 1];
    }
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    
    
    return 0;
}