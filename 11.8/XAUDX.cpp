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
	//freopen(file".INP","r",stdin);
	//freopen(file".OUT","w",stdout);
	string s;
    cin >> s;
    int k;

    vector<int> fre(256, 0);
    for (char c : s) fre[c]++;

    int res = 0;
    for (int x : fre) res += (x % 2 == 1);
    cout << res;
    

    cout << '\n';
}

