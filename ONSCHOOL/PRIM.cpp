//Tran Anh Tuan - 10 Tin - CTL
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef pair <int,int> ii;

const ll N = 1e5 + 5;
const ll INF = 1e9;

ll res = 0, st = 1;

vector <ii> graph[N];
ll dis[N], n, m;

void PRIM() {
    priority_queue<ii, vector<ii>, greater<ii>> myque;

    for (int i = 1; i <= n; i++) dis[i] = INF;

    dis[st] = 0;
    myque.push({0, st});

    while (!myque.empty()) {
        ll v = myque.top().second;
        ll wv = myque.top().first;
        myque.pop();

        if (-wv > dis[v]) continue;

        res += dis[v];

        for (auto pu : graph[v]) {
            ll u = pu.first;
            ll w = pu.second;
            if (dis[u] > w) {
                dis[u] = w;
                myque.push({ dis[u], u });
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }
    PRIM();
    cout << res;
    return 0;
}