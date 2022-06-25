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

const ll N = 20001;
ll x, res = 0;
bool d[N] = {};
vll num;

void init(){
	for(ll i = 2; i <= N; i++){
		if (!d[i]){
			for (ll j = i * i; j <= N; j += i){
				d[j] = 1;
			}
		}
	}
    for(ll i = 2; i <= N; i++)
        if (!d[i]) num.pb(i);
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    init();
    cin >> x;
    ll n = num.size() - 1;
    FOR(i,0,n){
    	FOR(j,i + 1,n){
    		if (num[i] * num[i] * num[j] * num[j] <= x){
    			res++;
    		}
    	}
        if (pow(num[i],8) <= x) res++;
    }
    cout << res;
    return 0;
}
