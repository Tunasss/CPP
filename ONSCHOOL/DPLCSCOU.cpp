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
const ll MOD = 25071987;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

const ll N = 5005;
ll s[N][N];
str a, b;
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> a >> b;
    ll n = a.size(), m = b.size();

    FOR(i,0,n) FOR(j,0,m) s[i][j] = 0;

   	FOR(i,1,n){
        FOR(j,1,m){
            if(a[i - 1] == b[j - 1]){
                s[i][j] = (s[i - 1][j] + s[i][j - 1] + 1) % MOD;
            }
            else{
            	s[i][j] = (s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1]) % MOD;
            }
        }
    }
    ll res = (s[n][m] % MOD + MOD) % MOD;
    cout << res;
}
