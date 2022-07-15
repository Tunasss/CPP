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
#define FOR(i,x,y) for(ll i = x; i <= y; ++i)
#define FOS(i,x,y) for(ll i = x; i >= y; --i)
#define EACH(i,x) for (auto &(i) : (x))
#define el cout << '\n';
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

const ll N = 1e5 + 5;

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    
    ll A1, B1, C1, A2, B2, C2;
    cin >> A1 >> B1 >> C1 >> A2 >> B2 >> C2;

    if (A1 == 0 && B1 == 0 && C1 != 0) cout << 0;
    else if (A2 == 0 && B2 == 0 && C2 != 0) cout << 0;
    else if (A1 == 0 && B1 == 0) cout << -1;
    else if (A2 == 0 && B2 == 0) cout << -1;
    else if (A1 * B2 != A2 * B1) cout << 1;
    else if (A1 * C2 == C1 * A2 && B1 * C2 == C1 * B2) cout << -1;
    else cout << 0;

    el;
}
