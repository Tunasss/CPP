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
#define vll vector<ll>
#define vi vector<int>

//III. Định nghĩa các MAX của kiểu dữ liệu
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;

//IV. Định nghĩa hàm Debug
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;

//IV. Định nghĩa hàm sinh số Random từ L đến R
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }


//V. Chương trình chính
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("BAI2.INP","r",stdin);
    // freopen("BAI2.OUT","w",stdout);
    int k,n;
    cin >> k;
    while(k--){
    	cin >> n;
        if (n < 10){ 
            ll iter1 = 1;
            ll iter2 = n - 1;
            while(iter1 <= n){
                cout << iter1;
                iter1++;
            }
            while(iter2 >= 1){
                cout << iter2;
                iter2--;
            }
            cout << '\n';
            continue;
        }
    	ll sz = n * 2 - 1;
        ll iter1 = 0;
        while(iter1 + 9 < n){
            cout << "123456790";
            iter1 += 9;
        }
        sz -= iter1 * 2 + 1;
        ll iter2 = iter1;

        if (sz != 0){
            ll sz_mid = (sz + 2) / 2;
            ll tmp1 = 1;
            ll tmp2 = sz_mid - 1;
            while (tmp1 <= sz_mid){
                cout << tmp1;
                tmp1++;
            }
            while (tmp2 > 1){
                cout << tmp2;
                tmp2--;
            }
        }

        while(iter2 - 9 >= 0){
            cout << "098765432";
            iter2 -= 9;
        }
        cout << 1;
        cout << "\n";
    }
    
    cerr << "\nTime: " << clock() / double(CLOCKS_PER_SEC) << " sec.\n";
    return 0;
}
