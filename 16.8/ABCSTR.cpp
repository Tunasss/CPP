#include <bits/stdc++.h>
using namespace std;
#define st first
#define nd second
#define pb push_back
#define pf push_front
#define _pb pop_back
#define _pf pop_front
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define mtp make_tuple
#define all(x) (x).begin(), (x).end()
#define spc(x, y) setprecision((y)) << fixed << (x)
#define slc(x, w, c) setw((w)) << setfill((c)) << (x)
#define file "TEST"
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef double db;
typedef long double ldb;
#define read_arr(a, l, r) for (int (i) = (l); (i) <= (r); ++(i)) cin >> (a)[(i)]
#define read_vec(a, n) int (tmp); for (int (i) = 0; (i) < (n); ++(i)) cin >> (tmp), (a).pb((tmp))
#define db_tag "DEBUG>> "
#define db_v(x) cerr << db_tag << (#x) << ": " << (x) << '\n'
#define db_p(x) cerr << db_tag << (#x) << ": " << (x).st << ' ' << (x).nd << '\n';
#define db_vec(x) cerr << db_tag << (#x) << ": "; for (auto (i) : (x)) cerr << (i) << ' '; cerr << '\n'
#define db_arr(x, l, r) cerr << db_tag << (#x) << ": "; for (int (i) = (l); (i) <= (r); ++(i)) cerr << (x)[(i)] << ' '; cerr << '\n'
mt19937_64 rd(time(0));
template<typename T> T gcd(T a, T b) { return (b == 0)? a : gcd(b, a % b); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<typename T> T i_rand(T l, T r) { return uniform_int_distribution<T>(l, r)(rd); }
template<typename T> T r_rand(T l, T r) { return uniform_real_distribution<T>(l, r)(rd); }

const int buff = 1e6;
str s;
int n;
ll rs = 0;
int f[1000005][3];
map<int, ll> d[2000005];

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    // freopen(file".INP", "r", stdin), freopen(file".OUT", "w", stdout);
    cin >> s;
    n = s.size();
    s = " " + s;
    for (int i = 1; i <= n; ++i)
    	f[i][0] = f[i - 1][0], f[i][1] = f[i - 1][1], f[i][2] = f[i - 1][2], f[i][(int)s[i] - 'A'] = f[i - 1][(int)s[i] - 'A'] + 1;
    for (int i = 1; i <= n; ++i) {
    	// db_v(f[i][0]);
    	// db_v(f[i][1]);
    	// db_v(f[i][2]);
    	rs += d[f[i][0] - f[i][1] + buff][f[i][1] - f[i][2]] + (f[i][0] == f[i][1] && f[i][1] == f[i][2]);
    	++d[f[i][0] - f[i][1] + buff][f[i][1] - f[i][2]];
    }
    cout << rs;
    return cerr << "\nTime: " << spc(clock() / db(CLOCKS_PER_SEC), 6) << " sec.\n", 0;
}
