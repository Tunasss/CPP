#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
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
#define vll vector<ll>
#define vi vector<int>
#define all(v) (v).begin(), (v).end()
#define FOR(i,x,y) for(ll i = x; i <= y; i++)
#define FOS(i,x,y) for(ll i = x; i >= y; i--)
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    ll t;
    cin >> t;
    while(t--){
    	ll n;
    	cin >> n;
        ll s = 4 * n * n;
    	ll a = 4 + 8 * ((n * 2 - 2) / 2);

    	if (n == 1){
    		cout << "4 0" << endl;
    		continue;
    	}
        ll cnt = 0; //Corner count
        for (int i = 0; i <= n; i++){
            for (int j = 0; j <= n - i; j++){
                ll x1 = n - i - 1, y1 = n - j - 1;
                //Center is I(n,n);
                long double r = n - 0.5;
                long double dis2 = x1 * x1 + y1 * y1;
                if (dis2 > r * r) cnt++;
            }
        }
    	cout << a << " " << s - a - cnt * 4 << endl;
    } 
    return 0;
}
