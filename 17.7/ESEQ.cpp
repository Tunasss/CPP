#include <bits/stdc++.h>
using namespace std;
//( ͡° ͜ʖ ͡°)
//Tunass

typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;

#define file "ESEQ"
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
	
	ll n, temp;
    ll arr[100001] = {},sum[100001];
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> temp;
        arr[i] = arr[i - 1] + temp;
        sum[i] = arr[i];
    }
    sort(sum+1,sum+n+1);
    ll dem = 0;
    for (int i = 1; i < n; i++)
    {
        if(bin(sum+1, sum+n+1, arr[n] - arr[i])) dem++;
    }
    if(bin(sum+1, sum+n+1, temp)) dem++;
    cout << dem;
    return 0;
	
	cerr << "Time: " << clock() / double(CLOCKS_PER_SEC) << " sec.\n";
}

