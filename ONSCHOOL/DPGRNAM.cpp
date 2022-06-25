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

const ll N = 505;
ll n, m, f[N][N], a[N][N];

void reset(ll x){
	memset(f, 0, sizeof f);
	FOR(i,1,n){
   		FOR(j,1,m){
   			if (a[i][j] == x || a[i][j] == -1)
   				f[i][j] = -1;
   		}
   	}
}

void dp(){
	a[1][1] = 1;
	FOR(i,1,n){
        FOR(j,1,m){
            if (i == 1 && j == 1) continue;

            if (a[i][j] == -1) {
                a[i][j] = 0;
            }

            else a[i][j] = a[i - 1][j] + a[i][j - 1];

        }
    }
    FOR(i,1,n){
        FOR(j,1,m){
        	cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << a[n][m];
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

   	cin >> n >> m;
   	FOR(i,1,n){
   		FOR(j,1,m){
   			cin >> a[i][j];
   		}
   	}
   	reset(1);
   	dp();
   	// FOR()
    
    return 0;
}