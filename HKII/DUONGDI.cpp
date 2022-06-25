#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;
#define file "DUONGDI"
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

ll const INF = LLONG_MAX;
int const N = 1e6 + 5;
vector<ii> graph[N];
bool isvisited[N];
ll dis[N], disa[N];
int n, m;

void BFS(ll s){
    for (int i = 1; i <= n; i++) dis[i] = INF;
    dis[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> myque;
    myque.push({0,s});

    while (!myque.empty()){
        int v = myque.top().second; 
        ll wv = myque.top().first;
        myque.pop();
        if (isvisited[v]) continue;
        isvisited[v] = true;

        if (dis[v] < -wv) continue;
        for (auto pu : graph[v]){
            int u = pu.first; ll w = pu.second;
            if (dis[u] > dis[v] + w){
                dis[u] = dis[v] + w;
                myque.push({dis[u], u});
            }
        }
    }
}

void DFS(ll s){
    for (int i = 1; i <= n; i++) disa[i] = INF;
    disa[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> myque;
    myque.push({0,s});

    while (!myque.empty()){
        int v = myque.top().second; 
        ll wv = myque.top().first;
        myque.pop();
        if (isvisited[v]) continue;
        isvisited[v] = true;

        if (disa[v] < -wv) continue;
        for (auto pu : graph[v]){
            int u = pu.first; ll w = pu.second;
            if (disa[u] > disa[v] + w){
                disa[u] = disa[v] + w;
                myque.push({disa[u], u});
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".INP","r",stdin);
    freopen(file".OUT","w",stdout);

    cin >> n;
    for (int i = 1; i < n; i++){
        int v, w;
        cin >> v >> w;
        graph[i + 1].push_back({v, w});
		 graph[v].push_back({i + 1, w});
    }
	BFS(1);
	ll q; cin >> q;
    for (int i = 1; i <= q; i++){
        ll a, b, c;
		cin >> a >> b >> c;
		DFS(a);
		for (int j = 0; j < N; j++){
			isvisited[j] = false;
		}
		
		dis[a] = min(dis[a], c + dis[a]);
		disa[b] = min(disa[b], c);
		cout << dis[a] + disa[b] << endl;
    }
    
    return 0;
}