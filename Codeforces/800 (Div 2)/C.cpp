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
#define el cout << endl;
#define all(v) (v).begin(), (v).end()
#define FOR(i,x,y) for(ll i = x; i <= y; i++)
#define FOS(i,x,y) for(ll i = x; i >= y; i--)
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

ll n,t;
const ll N = 2e5 + 5;
ll a[N];

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> t;
    while (t--){
        cin >> n;
        ll sum = 0;
        int pos = -1;
        FOR(i, 0, n - 1){
            cin >> a[i];
            sum += a[i];
            if (!(a[i] == 0)) pos = i;
        }
        if (sum){
            cout << "No" << '\n';
            continue;
        }
        if (pos == -1){
            cout << "Yes" << '\n';
            continue;
        }
        if (!(a[0] > 0)){
            cout << "No" << '\n';
            continue;
        }
        if (!(a[pos] <= 0)){
            cout << "No" << '\n';
            continue;
        }
            ll sum2 = 0;
            bool flag = true;
            FOR(i, 0 , n - 1){
                sum2 += a[i];
                if ( !(sum2 > 0) && !(i >= pos)) {
                    cout << "No" << '\n';
                    flag = false;
                    break; 
                }
            }
            if (flag) 
               cout << "Yes" << '\n';
    }
    
    return 0;
}
