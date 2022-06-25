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

const ll N = 105;
const ll M = 10005;
ll n, m; 
vll a, b;
ll s[M][N];

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n >> m;
    a.pb(INT_MAX), b.pb(INT_MAX);
    FOR(i,1,n) {
        ll x,y,k;
        cin >> x >> y >> k;
        while(k--){
            b.pb(x);
            a.pb(y);
        }
    }
    n = a.size();
    FOR(i,1,n){
        FOR(j,1,m){
            if(b[i] <= j)
                s[i][j] = max(s[i - 1][j], s[i - 1][j - b[i]] + a[i]);
            else s[i][j] = s[i - 1][j];
        }
    }
    cout << s[n][m];
    return 0;
}