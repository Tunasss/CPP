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
	ll x;
	cin >> x;
	if (x % 2 == 1){
		if (x == 1) cout << 3 << '\n';
		else cout << 1 << '\n';
		return;
	}
	bitset<32> a(x);
	bitset<32> b;

	FOR(i,0,31) {
        if (a[i] == 1) {
            b[i] = 1;
            break;
        }
    }
    if (a.count() != 1) {
        cout << (ll)b.to_ulong() << '\n';
        return;
    }

    FOR(i,0,31) {
        if (a[i] == 0) {
            b[i] = 1;
            break;
        }
    }
    cout << (ll)b.to_ulong() << '\n';
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    ll t;
    cin >> t;
    while(t--){
    	solve();
    }
}