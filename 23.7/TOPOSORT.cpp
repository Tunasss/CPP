#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
//( ͡° ͜ʖ ͡°)
//Tunass

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

#define all(v) (v).begin(), (v).end()
#define fto(i,x,y) for(ll i = x; i <= y; i++)
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;

#define debug(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "

#define debug_end(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;

const int N = (int)1e5 + 5;
int n, m;
vector<int> d[N], topo;
int c[N];

void dfs(int i) {
    if (c[i])
        return;
    c[i] = 1;
    for (int j : d[i])
        dfs(j);
    topo.push_back(i);
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);
    

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        d[u].push_back(v);
    }

    for (int i = 1; i <= n; ++i)
        dfs(i);

    reverse(topo.begin(), topo.end());

    for (auto x : topo){
        cout << x << " "; 
    }
    return 0;
}