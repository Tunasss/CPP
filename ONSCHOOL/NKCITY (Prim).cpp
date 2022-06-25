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
        ll wv = myque.top().first;
        ll v = myque.top().second;
        myque.pop();

        if (-wv > dis[v]) continue;

        res = max(res, dis[v]);

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

signed main()
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