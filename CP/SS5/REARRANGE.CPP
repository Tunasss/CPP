#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
#define file "REARRANGE"
#define fto(i,x,y) for(ll i = x; i <= y; i++)
const ll maxx = 1000000;
//( ͡° ͜ʖ ͡°)
//Tunass

///TEMPLATE: Tran Theo Bao

ll gcd(ll a, ll b){
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b){
	return a / gcd(a, b) * b;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen(file".INP","r",stdin);
	freopen(file".OUT","w",stdout);
	ll t,n;
	cin >> t;
	while (t--){
		cin >> n;
		ll a[n+5];
		fto(i,1,n)
			cin >> a[i];
		sort(a + 1, a + 1 + n);
		if (a[n] < a[n - 1] + a[1]){
			cout << "YES\n";
		fto(i,1,n)
			cout << a[i] << ' ';
			cout << '\n';
			continue; 
		}
	swap(a[n], a[n - 1]);
	if (a[n - 1] < a[n] + a[n - 2]){
		cout << "YES\n";
		fto(i,1,n)
			cout << a[i] << ' ';
			cout << '\n';
			continue;
		}	
	cout << "NO\n";				
	}
}

