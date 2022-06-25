//Tran Anh Tuan (Tunass) - 10 Tin - CTL
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

    ll t;
    cin >> t;
    while(t--){
    	str s;
    	cin >> s;
    	ll c[4] = {0};
    	ll m = s.size();
        
    	FOR(i,1,m - 1){
    		if (isdigit(s[i])) c[1] = 1;
    		if (s[i] >= 'A' && s[i] <= 'Z') c[2] = 1;
    		if (s[i] >= 'a' && s[i] <= 'z') c[3] = 1;
    	}
    	ll length = min(5LL, max(m - 5, 0LL));

    	ll check = (c[1] == 1 && c[2] == 1 && c[3] == 1 ? 5 : c[1] + c[2] + c[3]);

    	ll res = length + check;
    	cout << res << ' ';
    }
    
    return 0;
}
