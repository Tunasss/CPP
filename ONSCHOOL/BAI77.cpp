#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
//Tunass

//I. Định nghĩa các kiểu dữ liệu
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;

//II. Định nghĩa các từ hay dùng (snippet)
#define file "TEST"
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

//IV. Định nghĩa hàm Debug
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;

//IV. Định nghĩa hàm sinh số Random từ L đến R
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

ll a[SIZE];

//V. Chương trình chính
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    
    ll i1, j1, i2, j2;
    ll k = 0;
    ll a[8][8];

    cout << "NHAP(X1, Y1): ";
    cin >> i1 >> j1;
    cout << "NHAP(X2, Y2): ";
    cin >> i2 >> j2;

    ///BLACK_WHITE

    for (ll i = 0; i < 8; i++){
        if (i % 2 == 0){
            for (ll j = 0; j < 8; j += 2){
                a[i][j] = 0;
                a[i][j + 1] = 1;
            }
        }
        else{
            for (ll j = 0; j < 8; j += 2){
                a[i][j] = 1;
                a[i][j + 1] = 0;
            }
        }
    }

    if (a[i1][j1] == a[i2][j2]) cout << "Hai o cung mau";
    else cout << "Hai o khac mau";
    cout << "\n";

    ///QUEEN

    //COLUMN
    bool ck = 0;
    if (i1 == i2){
        cout << "Con Hau o o A khong che duoc con Hau o o B";
        ck = 1;
    }

    //ROW
    if (j1 == j2){
        cout << "Con Hau o o A khong che duoc con Hau o o B";
        ck = 1;
    }
    //DOWN_LEFT
    k = 0;
    while(i1 - k >= 1 && j1 + k <= 8){
        if (i1 - k == i2 && j1 + k == j2){
            cout << "Con Hau o o A khong che duoc con Hau o o B";
            ck = 1;
        }
        k++;
    }
    //UP_RIGHT
    k = 0;
    while(i1 - k >= 1 && j1 + k <= 8){
        if (i1 + k == i2 && j1 - k == j2){
            cout << "Con Hau o o A khong che duoc con Hau o o B";
            ck = 1;
        }
        k++;
    }
    //DOWN_RIGHT
    k = 0;
    while(i1 + k <= 8 && j1 + k <= 8){
        if (i1 + k == i2 && j1 + k == j2){
            cout << "Con Hau o o A khong che duoc con Hau o o B";
            ck = 1;
        }
        k++;
    }
    //UP_LEFT
    k = 0;
    while(i1 - k >= 1 && j1 - k >= 1){
        if (i1 - k == i2 && j1 - k == j2){
            cout << "Con Hau o o A khong che duoc con Hau o o B";
            ck = 1;        
        }
        k++;
    }
    
    if (!ck)
    cout << "Con Hau o o A khong khong che duoc con Hau o o B";

    cout << '\n';

    ///HORSE

    //TOP
    if (j1 - 2 == j2){
        if (i1 - 1 == i2 || i1 + 1 == i2){
            cout << "Con Ma o o A khong che duoc con Ma o o B";
            return 0;
        }
    }
    //DOWN
    if (j1 + 2 == j2){
        if (i1 - 1 == i2 || i1 + 1 == i2){
            cout << "Con Ma o o A khong che duoc con Ma o o B";
            return 0;
        }
    }
    //LEFT
    if (i1 - 2 == i2){
        if (j1 - 1 == j2 || j1 + 1 == j2){
            cout << "Con Ma o o A khong che duoc con Ma o o B";
            return 0;
        }
    }
    //RIGHT
    if (i1 + 2 == i2){
        if (j1 - 1 == j2 || j1 + 1 == j2){
            cout << "Con Ma o o A khong che duoc con Ma o o B";
            return 0;
        }
    }
    cout << "Con Ma o o A khong khong che duoc con Ma o o B";


    // cerr << "\nTime: " << clock() / double(CLOCKS_PER_SEC) << " sec.\n";
    return 0;
}
    