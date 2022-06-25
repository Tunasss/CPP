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

#define debug(...) cerr << " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

ll gcd(ll a, ll b){
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b){
	return a / gcd(a, b) * b;
}

int n,m,k;
ll arr[5000];
ll sum[5000];

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen(file".INP","r",stdin);
	//freopen(file".OUT","w",stdout);
	cin >> n >> m >> k;
	ull res = 0;

	for (ll i = 0; i < m; i++)
    {
        cin >> arr[i];
        sum[0] += arr[i];
    }
    for (ll i = m; i < n; i++)
    {
        cin >> arr[i];
        sum[i - m + 1] = sum[i - m] - arr[i - m] + arr[i];
    }

  	// sort (sum, sum + n, greater<int>());

  	for (ll i = 0; i < n; i++){
   		cout << sum[i] << " ";
  	}

  	for (ll i = 0; i < k; i++)
    {
        res += sum[i];
    }

	// cout << "\n";
    cout << res;

	// cout << '\n';
	// cerr << "Time: " << clock() / double(CLOCKS_PER_SEC) << " sec.\n";
}

