#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;
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
#define FOR(i,x,y) for(ll i = x; i <= y; i++)
#define FOS(i,x,y) for(ll i = x; i >= y; i--)
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    str s;
    cin >> s;
    string num = s.substr(1, s.size());
    double n = stod(num);
    int d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0;
    while (n >= 1.00){
        d1++;
        n -= 1.00;
    }
    while (n >= 0.25){
        d2++;
        n -= 0.25;
    }
    while (n >= 0.10){
        d3++;
        n -= 0.10;
    }
    while (n >= 0.05){
        d4++;
        n -= 0.05;
    }
    while (n >= 0.01){
        d5++;
        n -= 0.01;
    }
    cout << d1 << " " << d2 << " " << d3 << " " << d4 << " " << d5 << endl;
    
    return 0;
}
