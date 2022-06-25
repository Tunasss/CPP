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

const ll N = 100005; 
ll n, m;

vector<vector<ii> > ed[2];
vector<bool> vis[2];
vector<ii> c_ed[N];

ll sum[N], t_sum[N], val[N];
ll type[N];
stack<int> s;
ll cnt = 0;

int f[N];
 
ll calc(int x)
{
    ll l = 0, r = 15000;
    ll res = 0; 
    while(l <= r){
        ll mid = (l + r) / 2;
        if (sum[mid] <= x){
            res = mid;
            l = mid + 1;
        } 
        else r = mid - 1;
    }
    return x * (res + 1) - t_sum[res];
}
 
void dfs(int u, int type_ed, int type_vis)
{
    vis[type_vis][u] = 1;
    if (type_ed == 1)
        type[u] = cnt;
    for (ll i = 0; i < ed[type_ed][u].size(); i++)
    {
        ll v = ed[type_ed][u][i].st;
        if (vis[type_vis][v])
            continue;
 
        dfs(v, type_ed, type_vis);
    }
    if (type_ed == 0)
        s.push(u);
 
}
 
ll dp(ll u)
{
    if (f[u] != -1)
        return f[u];
    ll res = 0;
    for (ll i = 0; i < c_ed[u].size(); i++)
    {
        ll v = c_ed[u][i].st;
        ll w = c_ed[u][i].nd;
        res = max(res, dp(v) + w);
    }
    res += val[u];
    return f[u] = res;
}

void init(){
	memset(f, -1, sizeof(f));
 
    for (ll i = 1; i <= 15000; i++)
    {
        sum[i] = sum[i - 1] + i;
        t_sum[i] = t_sum[i - 1] + sum[i];
    }
 
    for (ll i = 0; i < 2; i++)
    {
        ed[i].resize(n + 5);
        vis[i].resize(n + 5);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n >> m;
 
    init();
 
    for (ll i = 1; i <= m; i++)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        ed[0][a].pb({b, w});
        ed[1][b].pb({a, w});
    }
 
    ll start;
    cin >> start;
 
    for (ll i = 1; i <= n; i++)
        if (!vis[0][i]){
            dfs(i, 0, 0);
        }
 
    while (!s.empty())
    {
        ll u = s.top(); s.pop();
        if (!vis[1][u])
        {
            cnt++;
            dfs(u, 1, 1);
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j < ed[0][i].size(); j++)
        {
            ll v = ed[0][i][j].st;
            ll w = ed[0][i][j].nd;
            if (type[i] == type[v])
                val[type[i]] += calc(w);
            else
                c_ed[type[i]].push_back({type[v], w});
        }
    }
    cout << dp(type[start]);
    
    return 0;
}