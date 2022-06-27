#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef unsigned long long ll;
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
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

const ll N = 2e6 + 5;
ll a[N], b[N], dp[N], check[N];

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen(file".INP","r",stdin);
    // freopen(file".OUT","w",stdout);

    ll n;
    cin >> n;

    for (ll i = 1; i <= n; i++)
        cin >> a[i] >> b[i];

    dp[1] = a[1];
    for (ll i = 2; i <= n; i++){
        dp[i] = min(dp[i - 1] + a[i], dp[i - 2] + b[i - 1]);
    }

    ll i = n, sum = 0;
    vll res;
    while(i > 0){
        ll test_1 = dp[i - 2] + b[i - 1];
        ll test_2 = dp[i - 1] + a[i];
        
        if (dp[i] == test_2){
            check[i] = 1;
            sum += a[i];
            i--;
            continue;
        }
        if (dp[i] == test_1){
            check[i] = 0;
            check[i - 1] = 2;
            sum += b[i - 1];
            i -= 2;
            continue;
        }
    } 
    cout << sum << '\n';
    for (ll i = 1; i <= n; i++) cout << check[i] << ' ';
    for(auto x : res) cout << x << ' ';
}
    