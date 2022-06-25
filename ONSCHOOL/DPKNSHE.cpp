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
const ll MAX = 10001;

ll e,f,n;

ll C[N], W[N], totals[MAX];

ll dp(ll x) 
{
    if (x <= 0) return 0;
    if (totals[x] != -1) return totals[x];

    ll sum = INT_MAX;
    for (int i = 1; i <= n; i++){
        if (W[i] <= x){
            sum = min(sum, C[i] + dp(x - W[i]));
        }
    }
    totals[x] = sum;

    return sum;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    ll t;
    cin >> t;
    while(t--){
        cin >> e >> f;
        ll value = f - e;
        cin >> n;
        FOR(i,1,n) cin >> C[i] >> W[i]; 

        for (ll i = 1; i < MAX; i++) totals[i] = -1;
        totals[0] = 0;

        ll result = dp(value);
        if (result == INT_MAX)
            cout << -1 << '\n';
        else
            cout << result << endl; 
    }
}