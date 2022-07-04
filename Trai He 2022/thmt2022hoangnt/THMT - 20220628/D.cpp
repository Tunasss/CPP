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

const ll N = 1e6 + 5;
const ll oo = 2e15;
ll n, a[N], d1[N], d2[N], res = -oo;

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n;
    FOR(i,1,n) cin >> a[i];
    if (n == 1 && a[1] & 1) {
    	cout << "NOT_FOUND";
    	return 0;
    }
    d2[0] = -oo;
    FOR(i,1,n){
    	d1[i] = -oo;
    	d2[i] = -oo;
    	if (a[i] & 1){
    		if (d2[i - 1] & 1) d1[i] = d2[i - 1] + a[i];
    		d2[i] = max(a[i], d1[i - 1] + a[i]); 
    	}
    	else{
    		if (d2[i - 1] & 1) d2[i] = d2[i - 1] + a[i];
    		d1[i] = max(a[i], d1[i - 1] + a[i]);
    	}
    	res = max(res, d1[i]);
    }
    cout << res;
    return 0;
}
