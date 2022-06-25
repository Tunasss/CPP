#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
#define file "TROCHOI"
#define fto(i,x,y) for(ll i = x; i <= y; i++)
const ll maxx = 1000000;
//( ͡° ͜ʖ ͡°)
//Tunass

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen(file".INP","r",stdin);
	freopen(file".OUT","w",stdout);
	
	int n, k;
	cin >> n >> k;
	string t = "";
	for(int i = 1; i <= n; i++){
		stringstream s;
		s << i;
		t += s.str();
	}
	int p = 0;
	while(p < (int) t.size()){
		int mx = p;
		for(int i = p + 1; i <= p + k && i < (int) t.size(); i++)
			if(t[i] > t[mx]) mx = i;
		k -= mx - p;
		cout << t[mx];
		p = mx + 1;
	}
	cout << endl;
	return 0;
}