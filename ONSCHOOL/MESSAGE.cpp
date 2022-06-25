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

const ll maxn = 100005;
vll g[maxn];
bool check[maxn];
vll topo_order;

void dfs(ll node){
    if (check[node]) return;
    check[node] = true;
    for (auto x : g[node]){
        dfs(x);
    }
    topo_order.pb(node);
}

void dfs2(ll node){
    if (check[node]) return;
    check[node] = true;
    for (auto x : g[node]){
        dfs2(x);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    
    ll n,m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        g[a].pb(b);
    }
    for (ll i = 1; i <= n; i++) dfs(i);
    for (ll i = 1; i <= n; i++) check[i] = false;

    reverse(topo_order.begin(), topo_order.end());
    ll dem = 0;
    
    for (auto x : topo_order) {
        if (!check[x]){
            dfs2(x);
            dem++;
        }
    }
    cout << dem;

    return 0;
}
