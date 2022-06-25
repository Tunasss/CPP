#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;

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

int num(char x){
    return x - '0';
}
str sum = "0";

str tong(str a, str b){
    if (a.size() > b.size()) swap(a, b);
    while (a.size() < b.size()) a = '0' + a;
    int memo = 0;
    string c;
    for (int i = a.size() - 1; i >= 0; i--){
        int x = num(a[i]) + num(b[i]) + memo;
        memo = x / 10;
        c = (char)((x % 10) + '0') + c;
    }
    if (memo != 0) c = (char)(memo + '0') + c;
    return c;
}

str tru(str a, str b){
    if(a.size() < b.size()){
        swap(a, b);
        fl = 0;
    }
    while (b.size() < a.size()) b = '0' + b;
    int memo = 0;
    string c;
    for (int i = a.size() - 1; i >= 0; i--){
        int x = num(a[i]) - num(b[i]) - memo;
        if (x >= 0){
            memo = 0;
            c = (char)(x + '0') + c;    
        } 
        else{
            memo = 1;
            c = (char)(10 + x + '0') + c;
        }
        //cout << x << " " << c << endl;
    }
    while (c[0] == '0') c.erase(0,1);
    if (fl == 0) c = '-' + c;
    if (c == "") c = "0";
    return c;
}

void tongnhan(string a, string b){
    if (a.size() > b.size()) swap(a, b);
    while (a.size() < b.size()) a = '0' + a;
    int memo = 0;
    string c;
    for (int i = a.size() - 1; i >= 0; i--){
        int x = num(a[i]) + num(b[i]) + memo;
        memo = x / 10;
        c = (char)((x % 10) + '0') + c;
    }
    if (memo != 0) c = (char)(memo + '0') + c;
    sum = c;
}

str nhanmain(str a, int b){
    str c;
    int memo = 0;
    for (int i = a.size() - 1; i >= 0; i--){
        int x = (a[i] - '0') * b + memo;
        memo = x / 10;
        c = (char)((x % 10) + '0') + c;
    }
    if (memo != 0) c = (char)(memo + '0') + c;
    return c;

}

str nhan(str a, str b){
    if(a.size() < b.size()){
        swap(a, b);
    }
    ll k = 0;
    for (int j = b.size() - 1; j >= 0; j--){ 
        int s2 = num(b[j]);
        str temp = nhanmain(a,s2);
        for (int i = 0; i < k; i++) temp = temp + "0";
        tongnhan(sum, temp);
        k++;
    }
    return sum;
}

    
//V. Chương trình chính
int main()
{
    string a, b;
	getline(cin, a);
	getline(cin, b);
	
	cout << endl << "CONG: " << tong(a,b);
	cout << endl << "TRU: " << tru(a,b);	
    cout << endl << "NHAN: " << nhan(a,b);
    // cerr << "\nTime: " << clock() / double(CLOCKS_PER_SEC) << " sec.\n";
    return 0;
}
