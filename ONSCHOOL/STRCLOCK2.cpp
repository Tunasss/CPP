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

ll n;
str s;

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    
    cin >> n;
    cin >> s;

    str hh = s.substr(0,2);
	str mm = s.substr(3,5);

	if (mm[0] >= '6'){
		mm[0] = '0';
	}

	if (n == 12){
		if (hh[0] >= '1' && hh[1] != '0'){
			hh[0] = '0';
		}
		if (hh[0] > '1' && hh[1] == '0'){
			hh[0] = '1';
		}
		if (hh[0] == '0' && hh[1] == '0') {
			hh[1] = '1';
		}
	}

	if (n == 24){
		if (hh[0] >= '2') {
			hh[0] = '0';
		}
	}

    cout << hh << ":" << mm;
    return 0;
}
