#include <bits/stdc++.h>
using namespace std;
//( ͡° ͜ʖ ͡°)
//Tunass

typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;

#define file "REWARD"
#define st first
#define nd second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define bin binary_search

#define fto(i,x,y) for(ll i = x; i <= y; i++)
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;


ll gcd(ll a, ll b){
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b){
	return a / gcd(a, b) * b;
}

ull genValue(int i,int j,int n)
{
    int m = (i+j) - 1;
    if (m <= n)
    {
        ull tong = (pow(m+1,2)-(m+1))/2;
        if (m % 2 == 0) return tong - (j - 1);
        else return tong - (i - 1);
    }
    else
    {
        int k = n - (m - n);
        ull tong = pow(n,2) - (pow(k,2)-k)/2;
        if (m % 2 == 0) return tong - (n - i);
        else return tong - (n - j);
    }
    return -1;
}

//void inmang(int n)
//{
//    for (int i = 1; i <= n; i++)
//    {
//        for(int j = 1; j <= n; j++) testlog << genValue(i, j, n) << " ";
//        testlog << endl;
//    }
//    testlog << "..." << endl;
//}
//
//void gentest(ofstream file_out, int n, int x, int y)
//{
//    file_out << n << " " << x  << " " << y << endl;
//    for (int i = 1; i < n; i++)
//    {
//        file_out << "S";
//    }
//    for (int i = 1; i < n; i++)
//    {
//        file_out << "E";
//    }
//}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen(file".INP","r",stdin);
	freopen(file".OUT","w",stdout);
	
	//gentest(ofstream("REWARD.inp"), 1000000, 1, 1);
    //tao map huong di
    unordered_map<char,pair<int,int>> huongdi;
    huongdi['E'] = { 0, 1};
    huongdi['S'] = { 1, 0};
    huongdi['W'] = { 0,-1};
    huongdi['N'] = {-1, 0};
    //
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    ull tong = genValue(x, y, n);
    map<pair<int,int>,bool> mymap;
    mymap[{x,y}] = true;
    //inmang(n);
    //testlog << "{" << x << "," << y << "} = " << tong << endl;
    for (ll i = 0; i < s.length(); i++)
    {
        x += huongdi[s[i]].first;
        y += huongdi[s[i]].second;
        //ull temp = genValue(x, y, n);
        cerr << "{" << x << "," << y << "}"<< endl;
        if (mymap[{x,y}] == false)
        {
            tong += genValue(x, y, n);
            mymap[{x,y}] = true;
        }
    }
    cout << tong;
    cout << "\n";
    //cerr << "Time: " << clock() / double(CLOCKS_PER_SEC) << "sec.\n";
    return 0;
}
//6 1 1
//SSSSSNNEEENWSW
	

