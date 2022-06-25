#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
//( ͡° ͜ʖ ͡°)
//Tunass

typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;

typedef priority_queue<ll, vector<ll>, greater<ll>> pque;
typedef unordered_map<ll,pque> umap;

#define file "C"
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
	
	int n;
    umap mymap;
    pque myque;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ll temp;
        cin >> temp;
        myque.push(temp);
        mymap[temp].push(0);
    }
    
    for (int i = 1; i < n; i++)
    {
        ll A = myque.top(); myque.pop();
        ll C = myque.top(); myque.pop();
        ll B = mymap[A].top(); mymap[A].pop();
        ll D = mymap[C].top(); mymap[C].pop();
        mymap[A+C].push(max(B+1,D+1));
        myque.push(A+C);
    }
    cout << mymap[myque.top()].top();
    return 0;
	
	cerr << "Time: " << clock() / double(CLOCKS_PER_SEC) << " sec.\n";
}


