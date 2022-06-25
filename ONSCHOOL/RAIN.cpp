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

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    int n; 
    cin >> n; 

    vector<int> arr(n + 2, 0), L(n + 2, 0), R(n + 2, 0), Li(n + 2, 0), Ri(n + 2, 0);

    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        L[i] = R[i] = arr[i];
        Li[i] = Ri[i] = i;
    }

    for (int i = 1; i <= n; i++) {
        if (L[i - 1] >= L[i]) {
            L[i] = L[i - 1];
            Li[i] = Li[i - 1];
        }
    }
    for (int i = n; i >= 1; i--){
        if (R[i + 1] >= R[i]) {
            R[i] = R[i + 1]; 
            Ri[i] = Ri[i + 1];
        }
    } 

    int tong = 0;
    for (int i = 2; i <= n - 1; i++){
        tong += max(tong,min(L[i], R[i]) * (abs(Li[i] - Ri[i]) - 1));
        dbg(L[i]); dbg(Li[i]); dbg(R[i]); dbg(Ri[i]); dbge(tong);
    } 

    cout << tong;
    return 0;
}
