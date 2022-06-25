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

const ll N = 1005;
str x1, x2, temp;
ll s[N][N];
vll a,b;
ll k;

void init(){
	FOR(i,0,1002) FOR(j,0,1002) s[i][j] = 0;

	str s; stringstream ss; ll t;

	getline(cin,s);
	ss << s;
	while(ss >> t) a.pb(t);

	ss.clear();

	getline(cin,s);
    ss << s;
	while(ss >> t) b.pb(t);
}

bool snt(ll n){
	if (n < 2) return false;

	for (ll i = 2; i <= sqrt(n); i++){
		if (n % i == 0){
			return false;
		}
	}
	return true; 
}


bool check(ll n){
	if ((ll)sqrt(n) == (double)sqrt(n)) return 1;

	if ((ll)cbrt(n) == (double)cbrt(n) && snt(cbrt(n))) return 1;

	return 0;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

 	init();    

    for(ll i = 0; i < a.size(); i++)
        for(ll j = 0; j < b.size(); j++)
            if(a[i] == b[j] && check(a[i]))
                s[i + 1][j + 1] = s[i][j] + 1;
            else s[i + 1][j + 1] = max(s[i][j + 1], s[i + 1][j]);

    cout << s[a.size()][b.size()];
    return 0;
}
