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

int const N = 1e2 + 1;
int const maxM = 20001;

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    ll t;
    cin >> t;
    while(t--){
    	int n;
		cin >> n;

		int arr[N];

		for (int i = 1; i <= n; i++) cin >> arr[i];

		bool dp[N][maxM] = {};

		dp[0][0] = 1;
		for (int i = 1; i <= n; i++) dp[i][0] = 1;
		for (int i = 1; i < maxM; i++){
			for (int j = 1; j <= n; j++){
				dp[j][i] = dp[j - 1][i] | (i - arr[j] >= 0?dp[j - 1][i - arr[j]]:0);
			}
		}

		for (int i = 0; i < maxM; i++)
			if (dp[n][i]) cout << i << " ";
		cout << endl;
    
    }
    
    return 0;
}
