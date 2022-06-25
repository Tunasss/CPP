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

const ll N = 2e6 + 1;
ll n, d, cnt[N] = {}, sum[N] = {};

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n >> d;
    FOR(i,1,n) {
        ll x; cin >> x;
        cnt[x]++;
    }

    FOR(i,1,N - 1) {
        sum[i] = sum[i - 1] + cnt[i];
    }

    ll res = 0;

    FOR(i,1,N - 1){
		ll cnt_a = sum[i - 1] - sum[max(0LL, i - d - 1)];

		res += cnt[i] * (cnt_a * (cnt_a - 1) / 2);
        res += (cnt[i] - 2) * (cnt[i] - 1) * cnt[i] / 6;
        res += (cnt[i] * (cnt[i] - 1) / 2) * cnt_a;
    }
    cout << res;
    return 0;
}
