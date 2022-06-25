#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;
#define file "TURBO"
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

const ll N = 100005;
ll n, num[N], pos[N];

ll tree[N] = {};

ll take(ll val) {
    ll res = 0;
    for (ll i = val; i >= 1; i -= (i & -i) ){
        res += tree[i];
    }
    return res;
}

ll sum(ll L, ll R) {
  	return take(R) - take(L - 1);
}

void add(ll pos, ll val) {
  	for (ll i = pos; i <= n; i += (i & -i) ){
    	tree[i] += val;
  	}
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n;
   	FOR(i,1,n){
	    cin >> num[i];
	    pos[num[i]] = i;
	    add(i, 1);
   	}
   	ll min_i = 1, max_i = n;

   	FOR(i,1,n){
      	if(i % 2 == 0) {
         	add(pos[max_i], -1);
         	cout << sum(pos[max_i], n) << '\n';
        	max_i--;
      	} 
      	else {
         	add(pos[min_i], -1);
         	cout << sum(1, pos[min_i]) << '\n';
         	min_i++;
      }
   }
    return 0;
}
    