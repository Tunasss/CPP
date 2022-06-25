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

const int N = 1e3 + 3;
 
int nx, ny;
char x[N], y[N];
int dp[N][N], nxt_x[10][N], nxt_y[10][N], g[N];

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> x + 1 >> y + 1;
    nx = strlen(x + 1);
    ny = strlen(y + 1);
 
    for (int d = 0; d <= 9; ++d) {
        nxt_x[d][nx] = nx + 1;
        for (int i = nx - 1; i >= 0; --i) {
            nxt_x[d][i] = (x[i + 1] - '0' == d) ? (i + 1) : nxt_x[d][i + 1];
        }
 
        nxt_y[d][ny] = ny + 1;
        for (int i = ny - 1; i >= 0; --i) {
            nxt_y[d][i] = (y[i + 1] - '0' == d) ? (i + 1) : nxt_y[d][i + 1];
        }
    }
 
    int max_len = 0;
    for (int i = nx; i >= 1; --i) {
        int mx = 0;
        for (int j = ny; j >= 1; --j) {
            if (x[i] == y[j]) {
                dp[i][j] = mx + 1;
            }
            mx = max(mx, g[j]);
            max_len = max(max_len, dp[i][j]);
        }
        for (int j = 1; j <= ny; ++j) {
            g[j] = max(g[j], dp[i][j]);
        }
    }
 
    if (max_len == 0) {
        cout << 0 << '\n';
        cout << "LCS MAX NUMBER is NULL" << '\n';
        return 0;
    }
 
    int max_len_nz = 0;
    for (int i = 1; i <= nx; ++i) {
        for (int j = 1; j <= ny; ++j) {
            if (x[i] != '0' && y[j] != '0' && dp[i][j]) {
                max_len_nz = max(max_len_nz, dp[i][j]);
            }
        }
    }
 
    if (!max_len_nz) {
        cout << 1 << '\n';
        cout << "LCS MAX NUMBER is 0" << '\n';
        return 0;
    }
 
    cout << max_len_nz << '\n';
    cout << "LCS MAX NUMBER is ";
    int i = 0;
    int j = 0;
    while (max_len_nz) {
        bool is_first_digit = (i == 0) && (j == 0);
        for (int d = 9; d >= (is_first_digit ? 1 : 0); --d) {
            int ni = nxt_x[d][i];
            int nj = nxt_y[d][j];
            if (ni <= nx && nj <= ny && dp[ni][nj] == max_len_nz) {
                cout << d;
                max_len_nz--;
                i = ni;
                j = nj;
                break;
            }
        }
    }
    return 0;
}