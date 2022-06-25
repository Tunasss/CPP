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

const int maxn = 105, inf = 1e9;
int n, m, a[maxn][maxn], F[maxn][maxn];
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

struct edge {
    ll u, v, t;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
};

queue<edge> myqueue;

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n >> m;
    FOR(i,1,n) FOR(j,1,m) cin >> a[i][j];

    FOR(i,1,n) FOR(j,1,m) F[i][j] = INT_MAX;

    FOR(i,1,m) {
        F[1][i] = a[1][i];
        myqueue.push({1,i,F[1][i]});
        F[n][i] = a[n][i];
        myqueue.push({n,i,F[n][i]});
    }

    FOR(i,1,n) {
        F[i][1] = a[i][1];
        myqueue.push({i,1,F[i][1]});
        F[i][m] = a[i][m];
        myqueue.push({i,m,F[i][m]});
    }

    while (! myqueue.empty()) {
        edge x = myqueue.top();
        myqueue.pop();

        if (x.t > F[x.u][x.v]) continue;
        FOR(k,0,3) {
            int i = x.u + dx[k];
            int j = x.v + dy[k];
            if (i <= 1 || i >= n || j <= 1 || j >= m) continue;
            int c = max(F[x.u][x.v], a[i][j]);
            if (F[i][j] > c) {
                F[i][j] = c;
                myqueue.push({i, j, F[i][j]});
            }
        }
    }

    int ans = 0;
    FOR(i,1,n) FOR(j,1,m) ans += F[i][j] - a[i][j];
    cout << ans;

    return 0;
}
