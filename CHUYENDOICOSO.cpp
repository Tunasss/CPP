#include <bits/stdc++.h>
#include <unordered_map>
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

#define all(v) (v).begin(), (v).end()
#define fto(i,x,y) for(ll i = x; i <= y; i++)
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;

#define debug(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "

#define debug_end(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

char arr[17] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','F'};

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    int t, n ,b;
    cin >> t;
    while(t--){
    	cin >> n >> b;

    	if (b == 2)
    	{
	    int temp, i = 1, sum = 0;
	    while(n > 0)
	    {
	        temp = n % 2;
	        sum += i * temp;
	        n /= 2;
	        i *= 10;
	    }
	    cout << sum << endl;
    	}

    	if (b == 16)
    	{
    		str s;
    		while (n != 0){
            s = arr[n % b] + s;
            n /= b;
        	}
        cout << s << endl;
    	}
    }

    cerr << "\nTime: " << clock() / double(CLOCKS_PER_SEC) << " sec.\n";
    return 0;
}

