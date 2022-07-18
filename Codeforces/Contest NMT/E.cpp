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
#define FOR(i,x,y) for(ll i = x; i <= y; ++i)
#define FOS(i,x,y) for(ll i = x; i >= y; --i)
#define EACH(i,x) for (auto &(i) : (x))
#define el cout << '\n';
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

const ll N = 111;
 
ll n, k, a[N];

struct Matrix {

int rowSize = N - 1;
int columnSize = N - 1;
int m[N][N] = {};

Matrix operator * (Matrix b) {
    Matrix C;
    for (int i = 1; i <= rowSize; ++i) {
        for (int j = 1; j <= b.columnSize; ++j) {
            C.m[i][j] = 0;
            for (int k = 1; k <= columnSize; ++k) {
                C.m[i][j] = (C.m[i][j] + 1LL * m[i][k] * b.m[k][j] % MOD) % MOD;
            }
        }
    }
    C.rowSize = rowSize;
    C.columnSize = b.columnSize;
    return C;
}

};
 
Matrix Pow(Matrix a, ll n) {
    if (n == 1) return a;
    if (n & 1) return Pow(a,n - 1) * a;
    Matrix tmp = Pow(a, n / 2);
    return tmp * tmp;
}

void print(Matrix X){
    cout << "+-";
    FOR(i,1,X.columnSize) cout << " - ";
    cout << "-+\n";

    for (int i = 1; i <= X.rowSize; ++i) {
        cout << "|  ";
        for (int j = 1; j <= X.columnSize; ++j) {
         cout << X.m[i][j] << "  ";
        }
        cout << "|\n";
    }
    
    cout << "+-";
    FOR(i,1,X.columnSize) cout << " - ";
    cout << "-+\n";
}

ll power(ll a, ll b){
    if (b == 0) return 1;
    ll ans = power(a, b / 2);
    if (b & 1) return ans * ans % MOD * a % MOD;
    return ans * ans % MOD;
}

// ll checker(ll x){
//     ll f[x + 5];
//     f[0] = f[1] = 0;

//     FOR(i,2,x){
//         f[i] = (f[i - 1] % MOD + f[i - 2] % MOD) % MOD;
//         f[i] %= MOD;
//         FOR(j,0,n){
//             f[i] += a[j] * power(i,j);
//             f[i] %= MOD;
//         }
//     }

//     return f[x];
// }

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    
    Matrix base, D;
    cin >> n >> k;
    if (k <= 1){
        cout << 0;
        el;
        return 0;
    }
    FOR(i,0,n) cin >> a[i];

    D.rowSize = n + 3;
    D.columnSize = n + 3;

    D.m[1][1] = 1;

    FOR(i,2,n + 1){
        FOR(j,1,n + 1){
            D.m[i][j] = D.m[i - 1][j - 1] + D.m[i - 1][j];
            D.m[i][j] %= MOD;
        }
    }

    FOR(i,0,n){
        D.m[n + 2][i + 1] = a[i];
    }

    D.m[n + 3][n + 2] = D.m[n + 2][n + 2] = D.m[n + 2][n + 3] = 1;
    // print(D);

    base.rowSize = n + 3;
    base.columnSize = 1;

    FOR(i,0,n){
        base.m[i + 1][1] = power(2, i);
    }

    Matrix ans = Pow(D,k - 1) * base;

    ll res = ans.m[n + 2][1];

    cout << res % MOD;
    el;

    return 0;
}