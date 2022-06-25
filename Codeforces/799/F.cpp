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

void solve(){
	ll d[10] = {};
	ll n;
	cin >> n;
	FOR(i,1,n){
		ll x; cin >> x;
		d[x % 10]++;
	}
	vll f;
	for(ll i = 0; i < 10; i++){
		d[i] = min(d[i], 3LL);
    	for(ll j = 0; j < d[i]; j++) f.pb(i);
	}
	bool flag = 0;
    for(ll i = 0; i < f.size(); i++){
        for(ll j = 0; j < f.size(); j++){
            for(ll k = 0; k < f.size(); k++){
                if (i != j && j != k && i != k && (f[i] + f[j] + f[k]) % 10 == 3){
                    cout << "YES" << "\n";
                    flag = 1;
                    return;
                }
            }
        }
    }
    if (!flag) cout << "NO" << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freofen(file".INf","r",stdin);
    //freofen(file".OUT","w",stdout);

    ll t;
    cin >> t;
    while(t--){
    	solve();
    }
    
    return 0;
}
