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
void solution(int a, int b, int n)
{
    for (int i = n / b; i >= 0; i--) {
        if ((n - (i * b)) % a == 0) {
            cout << i  + (n - (i * b)) / a;
            return;
        }
    }
    cout << -1;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, k;
    cin >> n >> k;

    vector <ll> a(n);
    for (ll i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(all(a), greater<int>());

    ull rs = 0;
    bool check[n];
    int j = 0;
    while(j < n)
    {
        ll temp = a[j];
        if (!check[j]){
        for (int i = j; i < n; i++)
            if(!check[i])
                {
                    if(temp - k >= a[i])
                    {
                        check[i] = true;
                        temp = a[i];
                    }
                }
        }
        j++;
    }
    for (ll i = 0;i < n;i++)
        if(!check[i])
            rs += a[i];
    cout << rs;   
    return 0;
}