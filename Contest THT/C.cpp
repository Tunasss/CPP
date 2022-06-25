#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
//( ͡° ͜ʖ ͡°)
//Tunass

typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;

#define file "NHOMF1"
#define st first
#define nd second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define bin binary_search

#define all(v) (v).begin(), (v).end()
#define fto(i,x,y) for(ll i = x; i <= y; i++)
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;

#define debug(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "

#define debug_end(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

   	ll n;
   	cin >> n;

   	ll a[n][n];

   	for (ll i = 1; i <= n; i++)
   		for (ll j = 1; j <= n; j++)
   			cin >> a[i][j];
   	for (ll i = 0; i < n; i++){
   		for (ll j = 0; j < n; j++)
   		{
   			
   		}
   	} 
        cerr << "\nTime: " << clock() / double(CLOCKS_PER_SEC) << " sec.\n";
        return 0;
    }
