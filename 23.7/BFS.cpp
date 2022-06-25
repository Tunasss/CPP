#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define dbg(x) cout << #x << " : " << x << endl
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define inf 1000000000000000000
#define maxn 100005

ll n, m, s, d[maxn] = {inf};
ll dau[maxn] = {0};
vector<ll> edges[maxn];
vector<pair<ll, ll>> res;
queue<ll> q;
void bfs(ll source)
{
    d[source] = 0;
    q.push(source);
    dau[source] = 1;
    while (!q.empty())
    {
        ll p = q.front();
        q.pop();
        for (auto ke : edges[p])
        {
            if (dau[ke] == 1)
                continue;
            d[ke] = min(d[ke], d[p] + 1);
            q.push(ke);
            dau[ke] = 1;
        }
    }
}
int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    cin >> n >> m >> s;
    s--;
    ll i;
    for (i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    // for(i=0;i<n;i++){
    //     cout<<i+1<<"-->";
    //     for(auto v: edges[i]) cout<<v+1<<" ";
    //     cout<<'\n';
    // }
    for (i = 0; i < n; i++)
        d[i] = inf;
    bfs(s);
    for (i = 0; i < n; i++)
        res.push_back({d[i], i});
    // cout<<res.size()<<'\n';
    sort(res.begin(), res.end());
    for (auto p : res)
    {
        if (p.first == inf)
            continue;
        cout << p.second + 1 << " " << p.first << '\n';
    }
    return 0;
}