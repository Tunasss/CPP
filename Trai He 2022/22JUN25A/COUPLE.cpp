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
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

const ll MOD = 1e9 + 7;
const ll N = 1e6 + 5;

ll a[N], n;
ll f[N], fc[N], inv[N];

ll power(ll a, ll b){
    ll ans = 1 % MOD;
    for (; b; b >>= 1)
    {
        if (b & 1)
            ans = ans * a % MOD;
        a = a * a % MOD;
    }
    return ans;
}

ll C(int m, int n)
{
    if (m > n)
        return 0;
    return fc[n] * inv[m] % MOD * inv[n - m] % MOD;
}

void init(){
    fc[0] = inv[0] = 1; 
    for (ll i = 1; i < N; i++){
        fc[i] = fc[i - 1] * i % MOD;
        inv[i] = power(fc[i], MOD - 2);
    }
    f[0] = f[1] = 1;
    for (ll i = 2; i < N; i++){
        f[i] = f[i - 2] * i % MOD;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    init();	
    cin >> n;
    ll ans = 0;
    for(ll i = 0; i <= n; i++){
    	if ((n - i) % 2 == 0){
	    	(ans += C(i,n) * power(f[max(n - i - 1,0LL)], 2) % MOD) %= MOD;
	    }
    }
    cout << ans;

    return 0;
}
