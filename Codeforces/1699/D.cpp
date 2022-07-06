#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int, int> ii;
#define file "TEST"
#define st first
#define nd secondz
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

const ll N = 5e3 + 5;
const ll oo = 2e15 + 5;

bool f[N][N];

bool ok(int l, int r) {
    if (r < l) return 1;
    return (r - l + 1) % 2 == 0 && f[l][r];
}

void solve() {
    int n;
    cin >> n;

    vll a(n); 
    FOR(i,0,n - 1) cin >> a[i];

    FOR(i,0,n - 1) {
        vll cnt(N * 2, 0);
        ll mx = 0;

        FOR(j,i,n - 1) {
            cnt[a[j]]++;
            mx = max(mx, cnt[a[j]]);

            if ((j - i + 1) % 2 == 0) {
                if (mx <= (j - i + 1) / 2) {
                    f[i][j] = true;
                } 

                else{
                    f[i][j] = false;
                }
            } 

            else{
                f[i][j] = false;
            }
        }
    }

    vll dp(n, -oo);

    FOR(i,0,n - 1) if (ok(0, i - 1)) dp[i] = 1;

    FOR(i,0,n - 1) {
        FOR(j,0,i - 1) {
            if (ok(j + 1, i - 1) && a[i] == a[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    ll ans = 0;

    FOR(i,0,n - 1) if (ok(i + 1, n - 1)) ans = max(ans, dp[i]);

    cout << ans << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    ll t = 1;
    if (true) cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}