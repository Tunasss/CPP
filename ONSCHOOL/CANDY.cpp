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

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    ll n;
    cin >> n;
    ll a[n + 1], max_left[n + 1], max_right[n + 1], sum = 0;
    FOR(i,1,n) {
    	cin >> a[i];
		max_left[i] = max_right[i] = a[i];
	}
    FOR(i,2,n){
        max_left[i] = max(max_left[i-1], max_left[i]);
    }
    FOS(i,n - 1,1){
       	max_right[i] = max(max_right[i+1], max_right[i]);
    }
	FOR(i,1,n) {
		sum += (min(max_left[i], max_right[i]) - a[i]);
	}
	cout << << sum;
    return 0;
}
