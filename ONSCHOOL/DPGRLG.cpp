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

const ll N = 1002;
ll n, m, a[N][N];
bool d1[N][N], d2[N][N];
ll res = 0;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll t;
    cin >> t;
    while(t--){
        res = 0;
        cin >> n >> m;

        FOR(i,1,n){
            FOR(j,1,m){
                char temp;
                cin >> temp;
                a[i][j] = (temp == 'C' ? 0 : 1);
            }
        }

        memset(d1, 1, sizeof d1);
        memset(d2, 1, sizeof d2);

        for (ll i = 1; i <= n; i++){
            for (ll j = m; j >= 1; j--){
                if (!a[i][j] || !d1[i][j + 1])
                    d1[i][j] = 0;
            }
        }

        for (ll i = n; i >= 1; i--){
            for (ll j = 1; j <= m; j++){
                if (!a[i][j] || !d2[i + 1][j])
                    d2[i][j] = 0;
            }
        }

        FOR(i,1,n){
            FOR(j,1,m){
                res += d1[i][j] && d2[i][j];
            }
        }

        cout << res << '\n';
    }
    return 0;
}