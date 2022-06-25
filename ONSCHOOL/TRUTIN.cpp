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

const ll N = 1002;

struct edge{
	ll u,v,w;
};

ll n, k, cha[N], hang[N], res = 0;
string s;

edge e[N]; 

void reset(){
	FOR(i,1,91) {
		cha[i] = i;
		hang[i] = 0;
	}
}

ll find(ll u) {
    if (cha[u] != u) cha[u] = find(cha[u]);
    return cha[u];
}

bool join(edge e) {
    ll u = find(e.u);
    ll v = find(e.v);
    // dbg(u); dbge(v);
    if (u == v) return false;
    if (hang[u] == hang[v]) hang[u]++;
    if (hang[u] < hang[v]) cha[u] = v;
    else cha[v] = u;
    return true;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    reset();
    cin >> n >> k;
    FOR(i,1,n){
    	cin >> s;
    	s = ' ' + s;

    	FOR(j,1,k - 1){
    		e[j].u = s[j];
            e[j].v = s[j + 1];
            e[j].w = 1;
    	}

    	FOR(j,1,k){
    		if (join(e[j])) res += e[j].w;
    	}
    	cout << res + 1 << '\n';
    }	
    
    return 0;
}
