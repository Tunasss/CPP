#include <bits/stdc++.h>
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

ll const INF = INT_MAX;
int const N = 1e5 + 5;

struct node{
	int v, w1, w2;
};

ll dis1[N], dis2[N], dis3[N], n, m, k;
vector <node> graph1[N], graph2[N];

//Dijkstra(start, status, distance, graph)

void Dijkstra(int st, bool check, ll dis[], vector <node> graph[]){
	for (int i = 1; i <= n; i++) dis[i] = INF;

	dis[st] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> myque;
	myque.push({0,st});

	while (!myque.empty()){
		ll v = myque.top().second; 
		ll wv = myque.top().first;
		myque.pop();

		if (dis[v] < -wv) continue;

		for (node x : graph[v]){
			int u = x.v; ll w = (check) ? (x.w1) : (x.w2);
			if (dis[u] > dis[v] + w){
				dis[u] = dis[v] + w;
				myque.push({dis[u], u});
			}
		}
	}
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		graph1[a].pb({b,c,d});
		graph2[b].pb({a,c,d});
	}

	Dijkstra(1,0,dis1,graph1);
	//Mom 1 -> n

	Dijkstra(n,0,dis2,graph2);
	//Mom n -> 1

	Dijkstra(k,1,dis3,graph2);
	//School Walk k -> node
	ll res = INF;

	for (int i = 1; i <= n; i++){
		// dbg(dis1[i]); dbg(dis2[i]); dbge(dis3[i]);
		if (dis1[i] + dis3[i] < 60){
			res = min(res, dis1[i] + dis2[i]);
		}
	}
	cout << res;

	return 0;
}