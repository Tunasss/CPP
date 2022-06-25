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
const ll SIZE = 1e6 + 5;
const ll MOD = 1e9 + 7;

ll n,m;
ll a[SIZE];

bool check(ll val)
{
    ll dem = 1, s = 0;
    for(int i = 1; i <= n; i++)
        if(s + a[i] <= val){
            s += a[i];
            }
        else{
            if(a[i] > val)
                return false;
            dem++;
            if(dem > m)
                return false;
            s = a[i];
        }
    return true;
    cout << s;
}

// void solve()
// {
    // ll dau = dmin - 1, cuoi = sum + 1, giua;
    // res = dmax + 1;
    // while(dau < cuoi){
        // giua = (dau + cuoi) / 2;
        // if(check(giua))
            // res = giua, cuoi = giua - 1;
        // else dau = giua - 1;
    // }
// }

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen(file".INP","r",stdin);
	//freopen(file".OUT","w",stdout);
	ll n,m, sum = 0, res = 0;
	cin >> n >> m;
	ll dmin = INT_MAX, dmax = INT_MIN;
	for (ll i = 1; i <= n; i++){
		cin >> a[i];
		sum += a[i];
		dmin = min(dmin,a[i]);
		dmax = max(dmax,a[i]);
		}

	ll dau = dmin - 1, cuoi = sum + 1, giua;
    res = dmax + 1;
    while(dau < cuoi){
    	cerr << "{dau, giua, cuoi, res [1]} = " << dau << " " << giua << " " << cuoi << " " << res << '\n';
        giua = (dau + cuoi) / 2;
        if(check(giua))
            res = giua, cuoi = giua - 1;
        else dau = giua - 1;
        cerr << "{dau, giua, cuoi, res [2]} = " << dau << " " << giua << " " << cuoi << " " << res << '\n';
    }
    cout << res;
}

