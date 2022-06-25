#include <bits/stdc++.h>
using namespace std;
//( ͡° ͜ʖ ͡°)
//Tunass

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

#define fto(i,x,y) for(ll i = x; i <= y; i++)
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;

ll n,m,k;
ll a[1005][1005];
void sinhmang(ll m, ll n){
	for (ll i = 0; i < m; i++){
		for (ll j = 0; j < n; j++){
			a[i][j] = (i + 1) * (j + 1);
		}
	}
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	// freopen(file".INP","r",stdin);
	// freopen(file".OUT","w",stdout);
	
	cin >> m >> n >> k;
	
	sinhmang(m,n);
	for (ll i = 0; i < m; i++){
		for (ll j = 0; j < n; j++){
			cout << a[i][j] << ' ';
			}
		cout << '\n';
		}	
	
	cerr << "Time: " << clock() / double(CLOCKS_PER_SEC) << " sec.\n";
}

