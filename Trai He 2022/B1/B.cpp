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
ll par[N], val[N];

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    ll q;
    cin >> q;
    FOR(i,1,q){
    	ll t,x;
    	cin >> t;
    	if (t == 1){
    		cin >> x;
    		par[i] = i - 1;
    		val[i] = x;
    	}
    	if (t == 2){
    		par[i] = par[par[i - 1]];
    		val[i] = val[par[i - 1]];
    	}
    	if (t == 3){
    		cin >> x;
    		val[i] = val[x];
            par[i] = par[x];
        }
        if(t == 0)
        {
            val[i] = val[i - 1];
            par[i] = par[i - 1];
            cout << val[i];
            el;
        }
    }
    
    return 0;
}
