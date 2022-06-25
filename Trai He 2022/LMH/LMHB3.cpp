#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
// typedef long long ll;
typedef unsigned long long ll;
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
#define el cout << endl;
#define all(v) (v).begin(), (v).end()
#define FOR(i,x,y) for(ll i = x; i <= y; i++)
#define FOS(i,x,y) for(ll i = x; i >= y; i--)
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

ll a, b, k;

ll power(ll x, ll y){   
    if (y == 0) return 0;
    ll tmp = power(x, y / 2);
    if (y & 1) return tmp + tmp + x % b;
    return tmp + tmp % b
}

ll pow10(ll n){
    if (n == 0) return 1 % b;
    ll tmp = power10(n / 2);
    if (y & 1) return power(tmp, n) * 10 % k;
    return power(tmp, tmp);
}   

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    ll t;
    cin >> t;
    while(t--){
    	cin >> a >> b >> k;
    	cout << a * power(10, k - 1) % b * 10 / b;
        el;
    }
    
    return 0;
}
