#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll,ll> ii;
#define pb push_back
#define FOR(i,x,y) for(ll i = x; i <= y; i++)

ll const INF = 9e9;
int const M = 250;

priority_queue<ii, vector<ii>, greater<ii>> myque;
vector<ii> graph[M];
ll n, m, w,dis[M];

bool vis[M] = {};

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    ll t;
    cin >> t;
    while(t--){
        cin >> n >> m >> w;
        FOR(i,1,n){
            graph[i].clear();
            vis[i] = false;
            dis[i] = INF;
        } 

        FOR(i,1,m){
            ll u,v,c;
            cin >> u >> v >> c;
            graph[u].pb({v,c});
            graph[v].pb({u,c});
        }

        myque = priority_queue<ii, vector<ii>, greater<ii>>();
        dis[n] = 0;
        myque.push({0,n});

        while (!myque.empty()){
            ll u = myque.top().second; 
            ll wu = myque.top().first;
            myque.pop();
            
            if (vis[u]) continue;
            vis[u] = true;

            if (wu > dis[u]) continue;
            
            for (auto pv : graph[u]){
                ll v = pv.first; 
                ll c = pv.second;

                if (dis[u] + c <= w){ // 1 time
                    if (dis[v] > dis[u] + c){
                        dis[v] = dis[u] + c;
                        myque.push({dis[v], v});
                    }
                }
                
                else { //t time
                    if (2 * c > w) continue;

                    ll t = (dis[u] + c - w) / (w - 2 * c);

                    if ((dis[u] + c - w) % (w - 2 * c) != 0) t++;

                    ll L = dis[u] + c + t * (c * 2);
                    if (dis[v] > L) {
                        dis[v] = L;
                        myque.push({L, v});
                    }
                }
            }
        }
        cout << (dis[1] >= INF ? -1 : dis[1]) << endl;
    }

    return 0;
}