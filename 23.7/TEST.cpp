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

string const ar = "0123456789ABCDEF";

char conv(string s){
    int dem = 2 * 2 * 2, tong = 0;
    for (int i = 0; i < s.length(); i++){
        tong += (s[i] - '0') * dem;
        dem /= 2;
    }
    return ar[tong];
}

ll chuyendoi (str s, int base)
{
    ll pow = 1;
    ull num = 0;  
    for (ll i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9') 
        {
            s[i] = s[i] - '0';
        }
        else s[i] = s[i] - 'A' + 10;
        num += s[i] * pow;
        // dbge(num);
        pow *= base;
    }
    return num;
}

//V. Chương trình chính
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    int t, b;
    str s;
    cin >> t;
    while(t--){
        cin >> s >> b;
        // ll n = chuyendoi(s,b);
        ll n = stoull(s);
        str c;
            while (n != 0){
            c = ar[n % b] + c;
            n /= b;
        }
        cout << c << endl;
    }

    cerr << "\nTime: " << clock() / double(CLOCKS_PER_SEC) << " sec.\n";
    return 0;
}

// signed main()
// {
//     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//     //freopen(file".INP","r",stdin);
//     //freopen(file".OUT","w",stdout);
//     int t, b;
//     str s,c;
//     cin >> t;

//     while (s.length() % 4 != 0) s = '0' + s;
//     while(t--){
//         cin >> s >> b;

//         for (ll i = s.size() - 1; i > 0; i -= 4)
//         {
//             c = conv(s.substr(i - 4 + 1, 4)) + c;
//         }
//         cout << c << " ";
//     }

//     cerr << "\nTime: " << clock() / double(CLOCKS_PER_SEC) << " sec.\n";
//     return 0;
// }