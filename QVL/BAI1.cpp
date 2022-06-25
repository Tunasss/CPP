#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int,int> ii;
#define file "TEST"
#define st first
#define nd second
#define pb push_back

const int sz = (int)1e5 + 5; 

#define mp make_pair
#define INF INT_MAX

int n, m, src, en; 
list<ii> adj[sz];
  
void add(int u, int v, int w)
{
    adj[u].pb(mp(v, w));
}

void DIJKSTRA(int src)
{
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    
    pq.push(mp(0, src));

    vector<int> dis(n, INF);
    dis[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (auto i : adj[u])
        {
            int v = i.st;
            int w = i.nd; 
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                pq.push(mp(dis[v], v));
            }
        }
    } 
    for (int i = 0; i < n; i++)
        cout << i << " " << dis[i] << endl;
    // cout << dis[en];
}

//V. Chương trình chính
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

	cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        add(u,v,1);
    }

    DIJKSTRA(0);
    
    return 0;
}