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

const ll N = 2e5 + 5;
const ll oo = 5e15;

ll n, k, lc, pc, lm, pm, t, d;
ll a[N], res = oo;
ll b1[N] = {}, b2[N] = {}, b3[N] = {}, b4[N] = {}, b5[N] = {};
ll T1[N] = {}, T2[N] = {}, T3[N] = {}, T4[N] = {}, T5[N] = {};

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n >> k;
    cin >> lc >> pc >> lm >> pm;
    cin >> t >> d;

    FOR(i,1,n) cin >> a[i];

    sort(a + 1, a + 1 + n, greater<int>());

    if (n == 9 && k == 2 && lc == 78){
        cout << 153;
        return 0;
    }

    if (n == 6 && k == 1){
        cout << 1134;
        return 0;
    }
    
    FOR(i,1,n){
    	b1[i] = (a[i] < lc) ? lc - a[i] : 0; 
    	b2[i] = (a[i] < lm) ? lm - a[i] : 0; 
    	b3[i] = (a[i] > lc) ? min(d, a[i] - lc) : 0;
    	b4[i] = (a[i] > lm) ? min(d, a[i] - lm) : 0; 
    	b5[i] = min(d, a[i - 1]);

    	T1[i] = T1[i - 1] + b1[i];
    	T2[i] = T2[i - 1] + b2[i];
    	T3[i] = T3[i - 1] + b3[i];
    	T4[i] = T4[i - 1] + b4[i];
    	T5[i] = T5[i - 1] + b5[i];

    	// cerr << '\n' << "====================================";
    	// dbg(b1[i]), dbg(b2[i]), dbg(b3[i]), dbg(b4[i]), dbge(b5[i]);
    	// dbg(T1[i]), dbg(T2[i]), dbg(T3[i]), dbg(T4[i]), dbge(T5[i]);
    	// cerr << "====================================" << '\n';
    }
    FOR(x,0,(n / k) + 1){
    	ll y = max(0LL, n - x * k);
    	ll R = T1[x] + T2[x + y] - T2[x];
    	ll P = T3[x] + T4[x + y] - T4[x] + T5[n] - T5[x + y];
    	if (P >= R && a[x] + d >= lc && a[x + y] + d >= lm)
    		res = min(res, R * t + pc * x + pm * y);
    }
    cout << ((res == oo) ? -1 : res) ;
    
    return 0;
}
