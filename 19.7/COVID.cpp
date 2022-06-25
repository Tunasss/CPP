#include <bits/stdc++.h>
using namespace std;
//( ͡° ͜ʖ ͡°)
//Tunass

typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;

#define file "COVID"
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
	ll n;
	
	cin >> n;
	vector <ll> a(n);
	
	ll room = 0;
	for (ll i = 0; i < n; i++)
		cin >> a[i];
		
	sort(a.begin(),a.end());
	
	for (ll i = 0; i < n; i++)
		cerr << a[i] << " ";
	cerr << endl;
	for (ll i = 0; i < n; i++){
	 	ll temp = 4 - a[i];
	 	if (bin(a.begin() + 1,a.end(),temp)){
	 		a.erase(a.begin());
	 		cerr << "found" << endl;
	 	}
	 	else
	 	{ 
		 	room++;
		 	cerr << "n-found" << endl;
		}
	}
	cout << room;
	cerr << "Time: " << clock() / double(CLOCKS_PER_SEC) << " sec.\n";
}

