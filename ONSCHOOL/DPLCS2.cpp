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

    str a, b;
    cin >> a >> b;
    ll s[a.size() + 2][b.size() + 2];

    for(int i = 0; i <= a.size(); i++)
        for(int j = 0; j <= b.size(); j++)
        	s[i][j] = 0;

    s[0][0] = 0;
    for(int i = 0; i < a.size(); i++)
        for(int j = 0; j < b.size(); j++)
            if(a[i] == b[j])
                s[i + 1][j + 1] = s[i][j] + 1;
            else s[i + 1][j + 1] = max(s[i][j + 1], s[i + 1][j]);


    
    // cout << s[a.size()][b.size()];

    stack<char> ans;
    int i = a.size(), j = b.size();
    while(i > 0 && s[i][j] !=0){
        if(s[i][j] == s[i - 1][j]){
            if(s[i][j] > s[i][j - 1])
                i--;
            else j--;
        }
        else{
            ans.push(a[i - 1]);
            i--;
            j--;
        }
    }
    while(!ans.empty()){
        cout << ans.top();
        ans.pop();
    }
    return 0;
}
