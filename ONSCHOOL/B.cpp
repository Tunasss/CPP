#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;
#define file "DIVIDE"
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

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".INP","r",stdin);
    freopen(file".OUT","w",stdout);

    ull n;
    ull a[4];
    cin >> n >> a[1] >> a[2] >> a[3];

    if (a[1] == a[2]) a[2] = LLONG_MAX;

    if (a[1] == a[3]) a[3] = LLONG_MAX;

    if (a[2] == a[3]) a[3] = LLONG_MAX;

    ull i = 1;
    set <ull> rs;
    while(true){
    	if (a[1] * i > n && a[2] * i > n && a[3] * i > n) break;

    	if (a[1] * i <= n) rs.insert(a[1] * i);

    	if (a[2] != LLONG_MAX && a[2] * i <= n) rs.insert(a[2] * i);

    	if (a[3] != LLONG_MAX && a[3] * i <= n) rs.insert(a[3] * i);

    	i++;
    }
    cout << rs.size();
    
    return 0;
}