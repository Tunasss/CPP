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

const ll N = 3001;
ll a[N];
ll n,t;
ll s1, s2 = 0, s3;

// Tam giac vuong
void check_s2(){
	FOR(i,0,n - 1){
		ll x = a[i];
		FOR(j,i + 1,n - 1){
			ll y = a[j];

			double cal = sqrt(x * x + y * y);

			if (bin(a, a + n, cal)){
				// dbg(x); dbg(y); dbge(cal);
				s2++;
			}
		}
	}
	cout << s2;
}

//Tam giac nhon
void check_s1(){
	FOR(i,0,n - 1){
		ll x = a[i];

		FOR(j,i + 1,n - 1){
			ll y = a[j];

			FOR(k,j + 1,n - 1){
				ll z = a[k];
				if (x + y < z) continue;

				double cal = sqrt(x * x + y * y); 

				if (cal > z){
					// dbg(x); dbg(y); dbg(z); dbge(cal);			
					s1++;	
				}
			}
		}
	}
	cout << s1;
}

//Tam giac tu
void check_s3(){
	FOR(i,0,n - 1){
		ll x = a[i];

		FOR(j,i + 1,n - 1){
			ll y = a[j];

			FOR(k,j + 1,n - 1){
				ll z = a[k];
				if (x + y < z) continue;

				double cal = sqrt(x * x + y * y); 

				if (cal < z){
					// dbg(x); dbg(y); dbg(z); dbge(cal);			
					s3++;	
				}
			}
		}
	}
	cout << s3;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

	cin >> n >> t;
	
	FOR(i,0,n - 1) cin >> a[i];  

    sort(a, a + n);

    if (t == 1) check_s1();
    else if (t == 2) check_s2();
	else if (t == 3) check_s3();
	
    return 0;
}
