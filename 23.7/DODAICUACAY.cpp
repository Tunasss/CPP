#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
//( ͡° ͜ʖ ͡°)
//Tunass

//I. Định nghĩa các kiểu dữ liệu
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;

//II. Định nghĩa các từ hay dùng (snippet)
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


//III. Định nghĩa các MAX của kiểu dữ liệu
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;

//IV. Định nghĩa hàm Debug
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;

//IV. Định nghĩa hàm sinh số Random từ L đến R
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

vector<ll> graph[200005];
ll danhdau[200005];

ll maxx = INT_MIN, maxx_node = 0;

void DFS(ll v, ll d)
{
    danhdau[v] = 1;

    // if (d > maxx) {
    //     maxx = d;
    //     maxx_node = v;
    // }

    for (ll u : graph[v])
        if (!danhdau[u])
            DFS(u, d + 1);
}

int a[N], in[N], out[N], dp[N];

void dfs1(int u, int par){
    in[u] = 0;
    for(int v:g[u]){
        if (v == par) continue;
        dfs1(v, u);
        in[u] = max(in[u], 1+in[v]);
    }
}

void dfs2(int u, int par){
    ll mx1 = -1, mx2 = -1;
    
    for(int v: g[u]){
        if(v == par) continue;

        if(in[v] >= mx1){
        mx2 = mx1, mx1 = in[v];
    }
        else if(in[v] > mx2) mx2 = in[v];
    }

    for(int v:g[u]){
        if (v == par) continue;
        int use = mx1;
        
        if(mx1 == in[v]) 
            use = mx2;
        
        out[v] = max(1 + out[u], 2 + use);
        
        dfs2(v, u);
    }
}

//V. Chương trình chính
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    ll a,b,n;
    cin >> n;

    for (ll i = 1; i <= n - 1; i++) {
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    maxx = INT_MIN;
    DFS(1, 0);

    //Phai resset de co the thuc hien lan chay BFS thu 2
    for (ll i = 1; i <= n; i++) danhdau[i] = 0; 
    
    maxx = INT_MIN;
    DFS(maxx_node, 0);
    
    cout << maxx;

    return 0;
    // cerr << "\nTime: " << clock() / double(CLOCKS_PER_SEC) << " sec.\n";
}
