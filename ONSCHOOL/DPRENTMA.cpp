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

const int N = 5001;
int n, l[N], res = INT_MIN;
ii a[N];

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n;
    FOR(i, 1, n) {
    	int t1, t2;
    	cin >> t1 >> t2;
    	a[i] = {t1, t2};
    }
    sort(a + 1, a + n + 1);
    FOR(i, 1, n) {
    	l[i] = a[i].nd - a[i].st + 1;
    	int tmp = l[i];
    	FOR(j, 1, i - 1)
    		if (a[j].nd < a[i].st)
    			l[i] = max(l[i], tmp + l[j]);
    	res = max(res, l[i]);
    }
    cout << res;
    
    return 0;
}
