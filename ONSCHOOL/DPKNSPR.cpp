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

const int N = 1121;
const int M = 188;
const int K = 15;
int n, k, p[M], d[N][K], z = 0;
bool mark[N];

signed main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    for (int i = 2; i < N; ++i) {
        if (mark[i]) continue;
        p[++z] = i;
        for (int j = i + i; j < N; j += i) mark[j] = 1;
    }
    d[0][0] = 1;
    for (int i = 1; i <= z; ++i) {
        for (int j = 1120; j > 0; --j) {
            if (j < p[i]) break;
            for (int f = 14; f > 0; --f) {
                d[j][f] += d[j - p[i]][f - 1];
            }
        }
    }
    while (cin >> n >> k) {
        if (n == 0 && k == 0) break;
        cout << d[n][k] << '\n';
    }
    
    return 0;
}
