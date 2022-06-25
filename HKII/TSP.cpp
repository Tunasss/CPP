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
#define vb vector<bool>
#define all(v) (v).begin(), (v).end()
#define FOR(i,x,y) for(ll i = x; i <= y; i++)
#define FOS(i,x,y) for(ll i = x; i >= y; i--)
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

const ll N = 25;
const ll INF = INT_MAX;

ll a[N][N];
ll n, m, ans = INF;
vb vis(N, 0);
vll f(N, 0), trace(N);

void solve(ll d) {
    for (ll i = 2; i <= n; i++){
        if (!vis[i]) {
            f[d] = f[d - 1] + a[trace[d - 1]][i];
            trace[d] = i;
            if (f[d] < ans)
                if (n > d) {
                    vis[i] = 1;
                    solve(d + 1);
                    vis[i] = false;
                }
            else ans = min(ans, f[n] + a[trace[n]][1]);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n >> m;
    FOR(i,1,n){
        FOR(j,1,n){
            if (i == j)
                a[i][j] = 0;
            else
                a[i][j] = INF;
        }
    }

    while (m--) {
        ll u, v, w;
        cin >> u >> v >> w;
        a[u][v] = min(a[u][v], w);
    }
    trace[1] = 1;
    f[1] = 0;

    vis[1] = 1;
    solve(2);

    cout << ans;
    
    return 0;
}
