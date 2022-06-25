#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll,ll> ii;
#define pii pair<ll,ii>

#define st first
#define nd second
#define FOR(i,x,y) for(ll i = x; i <= y; i++)

const ll M = 2223;
const ll N = 30;

ll graph[M][N], wall[M][N], res = 0;
ll n, m;
bool visited[M][N];

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n >> m;
    FOR(i,1,n){
        FOR(j,1,m) cin >> graph[i][j];
        FOR(j,1,m - 1) cin >> wall[i][j];
    }
	priority_queue<pii, vector<pii>, greater<pii>> myque;

    FOR(i,1,m) myque.push({ graph[1][i], {1,i} });

    while (!myque.empty()) {
        ll w = myque.top().st;
        ll u = myque.top().nd.st;
        ll v = myque.top().nd.nd;

        myque.pop();

        if (visited[u][v]) continue;
        visited[u][v] = 1;

        if (u == n && v == m) {
            res = w;
            break;
        }

        if (u - 1 != 0)
            myque.push({ w + graph[u][v], {u-1,v} });
        if (u + 1 <= n)
            myque.push({ w + graph[u + 1][v], {u+1,v} });
        if (v - 1 != 0)
            myque.push({ w + wall[u][v - 1], {u,v-1} });
        if (v + 1 <= m)
            myque.push({ w + wall[u][v], {u,v+1} });
    }
    cout << res;
    
    return 0;
}
