#include <bits/stdc++.h>
using namespace std;

#define file "LPDAG"
#define endl '\n'

#define ll long long
#define ull unsigned long long
#define arr array
#define ii pair <int, int>

#define st first
#define nd second

#define pb push_back

#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define bin binary_search

const int SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;

int n, m, res = -1, cc = -1;
int dp[SIZE];
bool c[SIZE];
vector <ii> adj[SIZE];
	
void dfs(int u) {
    int maximum = 0;
    for (auto child : adj[u]) {
        dfs(child.st);
        maximum = max(maximum, dp[child.st] + child.nd);
    }
    dp[u] = maximum;
}
	
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen(file".INP","r",stdin);
	freopen(file".OUT","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].pb( {v, w} );
	}

	dfs(1);
	// for (int i = 1; i <= n; i++) cout << dp[i] << ' ';
	cout << *max_element(dp + 1, dp + 1 + n);

	cout << '\n';
	cerr << "Time: " << clock() / double(CLOCKS_PER_SEC) << " sec.\n";
	return 0;
}