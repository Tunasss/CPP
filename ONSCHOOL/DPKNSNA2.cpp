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

const ll N = 501;
const ll M = 1e6 + 1;

ll n, m;
ll f[M];
ii dp[N];

bool cmp(ii a, ii b) {
    return a.nd < b.nd;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> m >> n;
    FOR(i,1,n) {
        ll v, w;
        cin >> v >> w;
        dp[i] = {v, w};
    }

    sort(dp + 1, dp + 1 + n, cmp);

    FOR(i,1,m) {
        FOR(j,1,n) {
            if (i - dp[j].nd < 0)
                break;
            f[i] = max(f[i], f[i - dp[j].nd] + dp[j].st);
        }
    }
    cout << f[m];
    return 0;
}
