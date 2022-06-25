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

ll x[31], t[31], n;

void init(){
    cin >> n;
    x[0] = 1, t[0] = 0;
}

void output(ll k){
	cout << n << " = ";
	for(ll i = 1; i < k; i++){
		cout << x[i] << "+";
	}
	cout << x[k] << '\n';
}

void quaylui(ll i)
{
    for(ll j = x[i - 1]; j<=((n - t[i - 1]) / 2); j++){
        x[i] = j;
        t[i] = t[i-1] + j;
        quaylui(i + 1);
    }
   	x[i] = n - t[i - 1];
   	output(i);
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    init();
    quaylui(1);

    return 0;
}
