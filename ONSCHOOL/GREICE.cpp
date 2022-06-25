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

const ll N = 10;
str t,s;
ll d1[N] = {}, d2[N] = {};

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> t >> s;
    FOR(i,0,t.size() - 1){
    	if (t[i] == '5') d1[2]++;
    	else if (t[i] == '9') d1[6]++;
    	else d1[t[i] - '0']++;
    }
    FOR(i,0,s.size() - 1){
    	if (s[i] == '5') d2[2]++;
    	else if (s[i] == '9') d2[6]++;
    	else d2[s[i] - '0']++;
    }
    ll res = INT_MAX;
    FOR(i,1,9){
    	// dbg(i), dbg(d1[i]), dbge(d2[i]);
    	if (d2[i] < d1[i]){
    		res = 0;
    		break;
    	} 
    	if (d1[i] != 0 && d2[i] != 0){
	    	ll temp = d2[i] / d1[i];
	    	if (temp != 0) res = min(temp, res);
	    }
    }
    cout << (res == INT_MAX ? 0 : res);
    
    return 0;
}
