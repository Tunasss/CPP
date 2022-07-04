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
 
const ll N = 3e6 + 5;
const ll oo = 2e15;
ll Ta[N], Tb[N], Tc[N], na, nb, nc;
str s;
 
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
 
    cin >> s;
    ll n = s.size();
    s = '#' + s;

	FOR(i,1,n){
    	Ta[i] = Ta[i - 1] + (s[i] == 'A');
    	Tb[i] = Tb[i - 1] + (s[i] == 'B');
    	Tc[i] = Tc[i - 1] + (s[i] == 'C');
    }
 
    na = Ta[n];
    nb = Tb[n]; 
    nc = Tc[n];

    FOR(i,1 + n,n + n){
        Ta[i] = na + Ta[i - n];
        Tb[i] = nb + Tb[i - n];
        Tc[i] = nc + Tc[i - n];
    }

    ll res = oo;
 
    FOR(i,1,n){
    	ll fa = na - (Ta[i + na - 1] - Ta[i - 1]);
    	ll fb = nb - (Tb[i + na + nb - 1] - Tb[i + na - 1]);
    	ll fc = nc - (Tc[i + na + nc - 1] - Tc[i + na - 1]);
    	
    	ll x = Tb[i + na - 1] - Tb[i - 1];
    	ll y = Ta[i + na + nb - 1] - Ta[i + na - 1];
    	
    	ll u = Tc[i + na - 1] - Tc[i - 1];
    	ll v = Ta[i + na + nc - 1] - Ta[i + na - 1];
 
    	ll zb = min(x,y);
    	res = min(res, fa + fb - zb);
 
    	ll zc = min(u,v);
    	res = min(res, fa + fc - zc);
    }
    cout << res;
    
    return 0;
}
