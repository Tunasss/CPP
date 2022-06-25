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
const int N = 5001;
struct elp {
    int w, iq, ind;
};
int n = 1, l[N], p[N], t1, t2, MAX = 1, MAXI = 1;
elp a[N];
bool cmp(elp a, elp b) {
    return a.w < b.w;
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    while(cin >> t1 >> t2) {
        if (t1 == 0)
            break;
        a[n].w = t1;
        a[n].iq = t2;
        a[n].ind = n;
        ++n;
    }
    --n;
    sort(a + 1, a + 1 + n, cmp);
    FOR(i, 1, n) {
        l[i] = 1;
        p[i] = i;
        FOR(j, 1, i - 1)
            if (a[i].w > a[j].w && a[i].iq < a[j].iq)
                if (l[j] + 1 > l[i]) {
                    l[i] = l[j] + 1;
                    p[i] = j;
                }
        if (l[i] > MAX) {
            MAX = l[i];
            MAXI = i;
        }
    }
    cout << MAX << '\n';
    if (MAX == 1)
        cout << 1;
    else {
        stack<int> tmp;
        while(p[MAXI] != MAXI) {
            tmp.push(MAXI);
            MAXI = p[MAXI];
        }
        tmp.push(MAXI);
        while(!tmp.empty()) {
            cout << a[tmp.top()].ind << ' ';
            tmp.pop();
        }
    }
    return 0;
}
    
