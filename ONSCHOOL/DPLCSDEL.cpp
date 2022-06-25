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

    ll t;
    cin >> t;
    while(t--){

    
    }
    
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
string str1, str2;
int f[4004][4004];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> str1 >> str2;
    f[0][0] = 0;
    for(int i = 1; i <= str1.size(); i++) f[i][0] = i;
    for(int j = 1; j <= str2.size(); j++) f[0][j] = j;
    for(int i = 0; i < str1.size(); i++)
    {
        for(int j = 0; j < str2.size(); j++)
        {
            if(str1[i] == str2[j]) f[i+1][j+1] = f[i][j];
            else f[i+1][j+1] = min(f[i][j+1], f[i+1][j]) + 1;
        }
    }
    cout << f[str1.size()][str2.size()];
    return 0;
}