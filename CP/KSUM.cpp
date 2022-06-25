#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
#define string str
#define file "KSUM"
#define fto(i,x,y) for(ll i = x; i <= y; i++)
const ll maxx = 1000000;
using namespace std;
//( ͡° ͜ʖ ͡°)
//Tunass



signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen(file".INP","r",stdin);
	freopen(file".OUT","w",stdout);
	
	ll n,k;
	cin >> n >> k;
	
    ll a[n+1];
    for(ll i = 1; i <= n; i++)
        cin >> a[i];
    
    ll s[n+5];
	ll res = 0; 
    s[0] = 0;
    
    for(ll i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    
	for(ll i = 1; i <= n - k; i++)
		res = max(res,s[i + k] - s[i]);
	cout << res;
}
