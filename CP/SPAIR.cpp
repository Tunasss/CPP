#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
#define file "SPAIR"
#define fto(i,x,y) for(ll i = x; i <= y; i++)
const ll maxx = 1000000;
//( ͡° ͜ʖ ͡°)
//Tunass

ll gcd(ll a, ll b){
	if (b == 0) return a;
	return gcd(b, a % b);
}
signed main()
{
   	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen(file".INP","r",stdin);
	//freopen(file".OUT","w",stdout);
	
	ll n,x;
    cin >> n >> x;
    ll a[n+1];
    for(ll i = 1; i <= n; i++)
        cin >> a[i];
    ll dem = 0;
    for(ll i = 1; i <= n - 1; i++){
    	for (ll j = i; j <= n; j++){
    		if (a[i] + (a[j] * a[j]) == x)
    		dem++;
    		}
    	}
    cout << dem;
	return 0;
}

