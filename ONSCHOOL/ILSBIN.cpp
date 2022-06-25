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

const ll N = 1e6 + 1;
ll n,m,dem;
char c;

ll find(ll x){
	ll l = 1;
	ll r = dem;
	while(l <= r){
		mid = (l + r) / 2;
		if (gt[mid] < x) l = mid + 1;
		else{
			r = mid - 1;
		}
	}
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n >> m;
    for (ll i = 1; i <= m; i++){
    	cin >> a[i] >> b[i] >> c;
    	if (c = 'e') then c[i] = 0;
    	else c[i]= 1;
    	dem++;
    	gt[dem] = a[i] - 1;
    	dem++;
    	gt[dem] = b[i];
    }
    sort(1, dem)
    
    return 0;
}
