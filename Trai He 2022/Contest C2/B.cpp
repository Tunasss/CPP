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
#define el cout << endl;
#define all(v) (v).begin(), (v).end()
#define FOR(i,x,y) for(ll i = x; i <= y; i++)
#define FOS(i,x,y) for(ll i = x; i >= y; i--)
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

const ll N = 500 * 4 + 5;
ll n, matA[N][N], matB[N][N], res[N][N], tmp[N][N];

void mulMatrix(ll mat1[N][N], ll mat2[N][N], ll type) {
    if (type == 0){
        FOR(i,0,n - 1){
            FOR(j, 0, n - 1){
                tmp[i][j] = 0;
                FOR(k, 0, n - 1){
                    tmp[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
    }
    
    if (type == 1){
        FOR(i,0,n - 1){
            FOR(j, 0, n - 1){
                res[i][j] = 0;
                FOR(k, 0, n - 1){
                    res[i][j] += tmp[i][k] * mat2[k][j];
                }
            }
        }
    }
}

bool c(ll matA[N][N], ll matB[N][N]){
    mulMatrix(matA, matA, 0);
    mulMatrix(tmp, matA, 1);

    FOR(i,0,n - 1){
        FOR(j, 0, n - 1){
            if (res[i][j] != matB[i][j])
                return 0;
        }
    }
    return 1;
}
void solve(){
    cin >> n;
    FOR(i,0,n - 1){
        FOR(j, 0, n - 1){
            cin >> matA[i][j];
        }
    }
    FOR(i,0,n - 1){
        FOR(j, 0, n - 1){
            cin >> matB[i][j];
        }
    }
    cout << (c(matA, matB) ? "YES" : "NO");
    el;
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
