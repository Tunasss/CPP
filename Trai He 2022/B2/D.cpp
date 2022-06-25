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
#define el cout << endl;
#define all(v) (v).begin(), (v).end()
#define FOR(i,x,y) for(ll i = x; i <= y; i++)
#define FOS(i,x,y) for(ll i = x; i >= y; i--)
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

const ll N = 2e6 + 5;

set<ll> G[N], s;
ll n, m, k;
ll res[N], u[N], v[N];

void dfs(ll u)
{
    if(G[u].size() < k && s.count(u))
    {
        s.erase(u);
        vector<int> t(all(G[u]));
        for(int &v : t) G[u].erase(v), G[v].erase(u);
        for(int &v : t) dfs(v);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        cin >> u[i] >> v[i];
        G[u[i]].insert(v[i]);
        G[v[i]].insert(u[i]);
    }

    for(int i = 1; i <= n; i++) s.insert(i);

    for(int i = 1; i <= n; i++) dfs(i);

    for(int i = m; i >= 1; i--) {
    	res[i] = s.size();
        if(G[u[i]].count(v[i])) G[u[i]].erase(v[i]);
        if(G[v[i]].count(u[i])) G[v[i]].erase(u[i]);
        dfs(u[i]);
        dfs(v[i]);
    }
    for(int i = 1; i <= m; i++) cout << res[i] << '\n';

    return 0;
}
