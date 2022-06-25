#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define file "PAIRNUM"
#define FOR(i,x,y) for(ll i = x; i <= y; i++)

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".INP","r",stdin);
    freopen(file".OUT","w",stdout);
    
	ll n,x = 1, rs = 0;
	cin >> n;
	ll a[n];
	FOR(i,0,n - 1) cin >> a[i];
	sort(a,a + n);

	FOR(i,0,n-1){
		if (a[i] == a[i+1]) x++; 
		else 
		{
			rs += x * (x - 1) / 2;
			x = 1;
		}
	}
	cout << rs;
    
    return 0;
}

