#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int,int> ii;

ll const INF = LLONG_MAX;
int const N = 1e5 + 5;
vector<ii> graph[N];
ll dis[N];
int n, m, s = 1;

void BFS(){
	for (int i = 1; i <= n; i++) dis[i] = INF;
	dis[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> myque;
	myque.push({s,0});

	while (!myque.empty()){
		int v = myque.top().first; 
		ll wv = myque.top().second;
		myque.pop();

		if (dis[v] < -wv) continue;
		for (auto pu : graph[v]){
			int u = pu.first; ll w = pu.second;
			if (dis[u] > dis[v] + w){
				dis[u] = dis[v] + w;
				myque.push({u, dis[u]});
			}
		}
	}
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int v, u, w;
		cin >> v >> u >> w;
		graph[v].push_back({u,w});
	}
	BFS();

	for (int i = 1; i <= n; i++){
		cout << dis[i] << " ";
	}
	return 0;
}