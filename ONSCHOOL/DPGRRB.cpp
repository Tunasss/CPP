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

const ll M = 1e3;
const ll N = 1e3;

ll m, n, p;
ll a[M][N], dp[M][N];

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    a[1][1] = 1;

    cin >> m >> n >> p;
    FOR(i,1,p){
        ll x,y;
        cin >> x >> y; 
        if (x == 1 && y == 1){
            cout << 0;
            return 0;
        } 
        a[x][y] = -1;
    }   
    FOR(i,1,m){
        FOR(j,1,n){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

    FOR(i,1,m){
        FOR(j,1,n){
            if (i == 1 && j == 1) continue;

            if (a[i][j] == -1) {
                a[i][j] = 0;
            }

            else a[i][j] = (a[i - 1][j] + a[i][j - 1]) % MOD;

        }
    }

    cout << a[m][n];
    return 0;
}
