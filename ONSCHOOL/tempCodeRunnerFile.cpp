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
const ll SIZE = 1000000;
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen(file".INP","r",stdin);
    // freopen(file".OUT","w",stdout);

    ll n;
    cin >> n;
    vector <ll> t(SIZE), r(SIZE), dp(SIZE);
    vector <bool> check(SIZE, false);
    ll maxx = 0;
    for (ll i = 1; i <= n; i++)
        cin >> t[i];
    for (ll j = 1; j <= n-1; j++)
        cin >> r[j];
    ll dem = n;
    dp[0] = 0;
    dp[1] = t[1];
    check[1] = true;
    for (ll i = 2; i <= n; i++)
    {
        if (dp[i - 2] + r[i - 1] < dp[i - 1] + t[i]){
            dp[i] = dp[i - 2] + r[i - 1];
        }
        else{
            dem--;
            check[i + 1] = true;
            dp[i] = dp[i - 1] + t[i];
        }
    }
    cout << dem << '\n';
    for (ll i = 1; i <= n; i++){
        if (check[i]) cout << i << " ";
    }
}
    