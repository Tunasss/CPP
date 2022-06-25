#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
const int Sz = 2e5 + 5;
 
ll a[Sz];
int n, q;
 
ll f(ll D)
{
	ll cnt = 0;
	for(int i = 1; i <= n; i++)
		cnt += D / a[i];
	return cnt;
}
 
ll BinS(ll target)
{
	ll l = 1;
	ll r = 1e18;
	ll res = 1e18;
 
	while(l <= r)
	{
		ll mid = (l + r) >> 1;
		ll Pins = f(mid);
		if(Pins >= target)
		{
			res = mid;
			r = mid - 1;
		}else l = mid + 1;
	}
 
	return res;
}
 
signed main()
{	
 
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
 
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
 
	ll t;
	cin >> t;
 
	cout << BinS(t) << "\n";
 
	return 0;
}