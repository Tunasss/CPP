#include <bits/stdc++.h>
using namespace std;
/*
       _,    _   _    ,_
  .o888P     Y8o8Y     Y888o.
 d88888      88888      88888b
d888888b_  _d88888b_  _d888888b
8888888888888888888888888888888
8888888888888888888888888888888
YJGS8P"Y888P"Y888P"Y888P"Y8888P
 Y888   '8'   Y8P   '8'   888Y
  '8o          V          o8'
*/
//Tunass

//I. Định nghĩa các kiểu dữ liệu
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;

//II. Định nghĩa các từ hay dùng (snippet)
#define file "TEST"
#define X first
#define Y second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define bin binary_search
#define all(v) (v).begin(), (v).end()
#define fto(i,x,y) for(ll i = x; i <= y; i++)

//III. Định nghĩa các MAX của kiểu dữ liệu
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;

//IV. Định nghĩa hàm Debug
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;

//IV. Định nghĩa hàm sinh số Random từ L đến R
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

int par[SIZE];
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
int n, m;
vector<iii> edge;

int anc(int p) {
    if (par[p] == p)
        return p;
    else
        return par[p] = anc(par[p]);
}

void join(int p, int q) {
	par[anc(p)] = anc(q);
}


//V. Chương trình chính
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v ,w;
        cin >> u >> v >> w;
        edge.pb(iii(w, ii(u, v)));
    }
    for (int i = 1; i <= n; i++)
        par[i] = i;

    sort(edge.begin(), edge.end());
    vector<int>::iterator it;

    int r = 0;

    for (it = edge.begin(); it != edge.end(); it++) {
        if (anc(it -> Y.X) != anc(it -> Y.Y)) {
            join(it -> Y.X, it -> Y.Y);
            r += it -> X;
        }
    }
    cout << r;

    cerr << "\nTime: " << clock() / double(CLOCKS_PER_SEC) << " sec.\n";
    return 0;
}
