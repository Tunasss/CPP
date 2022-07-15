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
using namespace std;
 
ll n, k, a[N], b[N];

struct Matrix {

int rowSize = N - 1;
int columnSize = N - 1;
int m[N][N];

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
 
 
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n >> k;
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,n) cin >> b[i];

    if (k < n) {
        cout << a[k] << '\n';
        return 0;
    }

    Matrix base, D;

    D.rowSize = n;
    D.columnSize = n;

    for (int i = 2; i <= n; ++i) {
        D.m[i - 1][i] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        D.m[n][i] = b[n - i + 1];
    }
    // print(D);

    base.rowSize = n;
    base.columnSize = 1;

    for (int i = 1; i <= n; ++i) {
        base.m[i][1] = a[i];
    }
    // print(base);

	Matrix ans = Pow(D, k - n + 1) * base;
	cout << ans.m[n][1] << '\n';
}