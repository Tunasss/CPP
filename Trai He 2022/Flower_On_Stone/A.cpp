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

const ll N = 4e5 + 5;
ll n, q;
ll BIT[N];

struct node{
	ll pos, L, R, val;
};

node a[N * 2];

ll cmp(node a, node b){
	return (a.val == b.val ? a.L > b.L : a.val > b.val);
}

void add(ll pos){
	for (ll i = pos; i <= n; i += (i & (-i)) ){
		BIT[i]++;
	}
}

ll take(ll pos) {
    ll res = 0;
    for (ll i = pos; i >= 1; i -= (i & (-i)) ){
        res += BIT[i];
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n; 
    
    FOR(i,1,n){
    	ll temp;
    	cin >> temp;
    	a[i].val = temp;
    	a[i].pos = i;
    	a[i].L = -2;
    }
    cin >> q;
    FOR(i,n + 1,n + q) {
    	ll l, r, k;
    	cin >> l >> r >> k;
        a[i].pos = i - n;
        a[i].val = k;
        a[i].L = l;
        a[i].R = r;
    }

    sort(a + 1, a + n + q + 1, cmp);

    memset(BIT, 0, sizeof(BIT));

    ll ans[q + 1];
 
    FOR(i,1,n + q) {
        if (a[i].L != -2) ans[a[i].pos] = take(a[i].R) - take(a[i].L - 1);
        else add(a[i].pos);
    }

    FOR(i,1,q) {
    	cout << ans[i];
    	el;
    }

    return 0;
}
