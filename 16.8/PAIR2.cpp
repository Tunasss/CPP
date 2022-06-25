#include <bits/stdc++.h>
using namespace std;
//( ͡° ͜ʖ ͡°)
//Tunass

typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;
typedef vector <ll> vecll;

#define file "TEST"
#define st first
#define nd second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define bin binary_search
#define lb lower_bound
#define up upper_bound


#define fto(i,x,y) for (ll i = x; i <= y; i++)
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;

#define debug(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "

#define debug_end(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;

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
    int n,k;
    cin >> n >> k;

    vector <ll> arr(n);
    for (auto &x : arr) cin >> x;

    sort (arr.begin(),arr.end());

	for (auto &x : arr) cerr << x << " ";
	cerr << "\n";

    ll res = INT_MAX;
	for (ll i = 0; i < k; i++){
		ll temp = arr[n - k + i] - arr[i];
		res = min(res, temp);
	}
	cout << res;

	cout << '\n';
	cerr << "Time: " << clock() / double(CLOCKS_PER_SEC) << " sec.\n";
}

