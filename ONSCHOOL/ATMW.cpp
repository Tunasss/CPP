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
#define vll vector<ll>
#define vi vector<int>
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

//V. Chương trình chính
int sto[] = {0,1,1,1,2,1,2,2,2,3};
int scach[] = {1,1,1,1,2,1,2,1,1,3};

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    ll w, c;
    cin >> w >> c;

    if (w % 1000 == 0 && w >= 1000)
    w /= 1000;
    else {
        cout << "0";
        return 0;
    }

    ll st = 0, sc = 1;
    while(c > 0 && w > 0)
    {
        c--;
        int d = w % 10;
        w = w / 10;
        st = st + sto[d];
        sc = sc * scach[d];
    }
    if(w % 5 == 0)
        st = st + w / 5;
    else
        if(w % 5 == 1)
        {
            st += w / 5 +1;
            if(w != 1)
            sc *= 2; 
        }
        else
            if(w % 5 == 2)
                st += w / 5 +1;
            else
                if(w % 5 == 3)
                    st += w / 5 +1;
                else
                {
                    st += w / 5 +2;
                    if(w == 4)
                        sc *= 2;
                    else
                        sc *= 3;
                }
    cout << st << " " << sc;
    return 0;
}
    