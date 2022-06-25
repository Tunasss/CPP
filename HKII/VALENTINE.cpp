#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;
#define file "VALENTINE"
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

const ll N = 1e6 + 5;

ll n, m, u, v; 
ll arr[N], r[N];
ll f[N], c[N];
stack<ll> s;

ll cal(ll x1, ll y1, ll x2, ll y2){
    return (x1 * y2 * 1LL) - (y1 * x2 * 1LL);
}

void init(){
    for (ll i = n - 1; i >= 1; i--){
        while(s.size() >= 2) {
            ll node1 = s.top(); 
            s.pop();
            ll node2 = s.top();
            s.push(node1);

            if (cal(node1 - node2, arr[node1] - arr[node2], i - node1, arr[i] - arr[node1]) < 0) s.pop();

            else break;
        }
        r[i] = s.top();
        s.push(i);
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".INP","r",stdin);
    freopen(file".OUT","w",stdout);

    cin >> n >> m;

    s.push(n);
    r[n] = n;

    FOR(i,1,n) {
        cin >> arr[i];
    }
    
    init();

    while(m--) {
        cin >> u >> v;
        ll s1 = 1, s2 = 1;
        while(true) {
            f[u] += s1;
            f[v] += s2;
            if (u == v || (u == n && v == n)) break;
            if (u == n) s1 = 0;
            if (v == n) s2 = 0;
            u = r[u];
            v = r[v];
        }
    }
    FOR(i,1,n) cout << f[i] << ' ';
    return 0;
}
