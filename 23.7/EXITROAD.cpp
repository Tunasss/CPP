#include <bits/stdc++.h>
#include <unordered_map>
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
#define file "EXITROAD"
#define st first
#define nd second
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
-00
//IV. Định nghĩa hàm Debug
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;

//IV. Định nghĩa hàm sinh số Random từ L đến R
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

int n, m, q;
char a[900][900];
char b[1000][1000];

vector <ii> c(10);

int kx[4] = {0,-1,0,1};
int ky[4] = {-1,0,1,0};

ll dem = 0;

int x1, y1;

int loang (int x, int y)
{
    if (x == 0 || y == 0) return 0;
    if (x > m || y > n) return 0;
    if (a[x][y] == 1) return 0;

    if (a[x][y] == 'x') return 0;

    if (a[x][y] == '.')
    {
        a[x][y] = 1;
        for (int k = 0; k < 4; k++)
        {
            dem += (x + kx[k], y + ky[k]);
        }
    }
    return dem + 1;
}

//V. Chương trình chính
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".INP","r",stdin);
    freopen(file".OUT","w",stdout);
    
    cin >> m >> n >> q;
    int z = 0;
    for (ll i = 1; i <= m; i++){
        for (ll j = 1; j <= n; j++){
            cin >> a[i][j];
            if (a[i][j] == 'x')
            {
                c[z].st = i;
                c[z].nd = j;
                z++;
            }
        }
    }

    for (ll i = 1; i <= m; i++){
        for (ll j = 1; j <= n; j++){
            b[i][j] = a[i][j];
        }
    }

    for (ll i = 0; i < q; i++){
        ll xi, yi;
        
        cin >> xi >> yi;

        if (a[xi][yi] == '#'){
            cout << "-1" << '\n';
            continue;
        }

        else{
            for (ll i = 0; i < z; i++)
            {
                dem = 0;

                x1 = c[i].st;
                y1 = c[i].nd;

                for (ll i = 1; i <= m; i++){
                    for (ll j = 1; j <= n; j++){
                        a[i][j] = b[i][j];
                    }
                }

                int temp = loang(xi,yi);
                cout << temp << "\n";
            }
        }
    }

    cerr << "\nTime: " << clock() / double(CLOCKS_PER_SEC) << " sec.\n";
    return 0;
}
