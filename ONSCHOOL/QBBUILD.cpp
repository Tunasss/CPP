#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define file "TEST"
#define FOR(i,x,y) for(ll i = x; i <= y; i++)

const ll INF = 999999999999999;
const ll N = 101;
ll graph[N][N], d[N][N], f[5];
ll n, u, v, c, ans = INT_MAX;

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".INP","r",stdin);
    freopen(file".OUT","w",stdout);
    cin >> n;	

   	FOR(i,1,4) cin >> f[i];
	FOR(i,1,n) graph[i][i] = 0;
	while(cin >> u >> v >> c) {
	    graph[v][u] = graph[u][v] = c;
	}
	FOR(i,1,n){
		FOR(j,1,n){
			if (i == j) d[i][j] = 0;
			else if (graph[i][j]) d[i][j] = graph[i][j];
			else d[i][j] = INF;
		}
	}	

	//Floyd
	FOR(k,1,n) {
		FOR(i,1,n){
			FOR(j,1,n){
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	FOR(x,1,n) {
		FOR(y,1,n){
			FOR(i,1,4) {
				FOR(j,i + 1,4){
					ll cal = d[f[i]][x] + d[f[j]][x] + d[x][y];
					FOR(k,1,4) {
						if (k != i && k != j) cal += d[f[k]][y];
					}
					ans = min(ans, cal);
				}			
			}
		}
	}
	cout << ans;
}
