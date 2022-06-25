#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
#define file "TIMSO"
#define fto(i,x,y) for(ll i = x; i <= y; i++)
const ll maxx = 1000000;
//( ͡° ͜ʖ ͡°)
//Tunass



signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen(file".INP","r",stdin);
	//freopen(file".OUT","w",stdout);
	
	ll a,b;
	cin >> a >> b;
	ll uoc1 = 0, uoc2 = 0, tong = 0;
	bool fl = 0;
	for (ll i = 1; i <= b; i++)
	{
		if (b % i == 0)
		{
			uoc1 = i;
			uoc2 = b / i;
			tong = uoc1 + uoc2;
			if (tong == a)
			{
				cout << uoc1 << " " << uoc2;
				fl = 1;
				break;
			}
		} 
		else continue;
	}
	if (!fl) cout << "N";
}

