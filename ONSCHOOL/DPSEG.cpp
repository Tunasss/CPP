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

const int N = 1001;
int n, l[N], MAX = 0;
ii a[N];

bool cmp(ii a, ii b) {
	if (a.st == b.st) return a.nd > b.nd;
	return a.st < b.st;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n;
    FOR(i,1,n) {
    	int t1, t2;
    	cin >> t1 >> t2;
    	a[i] = {t1, t2};
    }
	sort(a + 1, a + n + 1, cmp);

    FOR(i,1,n) {
    	l[i] = 1;
    	FOS(j, i - 1, 1)
    		if (a[j].st <= a[i].st && a[i].nd <= a[j].nd)
    			l[i] = max(l[i], l[j] + 1);
    	MAX = max(MAX, l[i]);
    }
    cout << MAX;
    return 0;
}
