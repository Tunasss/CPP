#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;
#define file "WGAME"
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

ll n, m, k;
vector < vector<char> > a;
string s;
ll d = 0;
vector<ll> f;

bool kmp(string x){
    ll j = 0;
    for(ll i = 0; i < x.size(); i++){
        if(s[j] == x[i]) j++;
        else if(j > 0) if(s[f[j - 1]] == x[i]) j = 1 + f[j - 1];
        else j = 0;
        if(j == s.size()) return 1;
    }
    return 0;
}

void dfs(ll x, ll y, string s1){
    s1 += a[x][y];
    if(x == n - 1 && y == m - 1)
    {
        string s2 = s1;
        reverse(s1.begin(), s1.end());
        if(s1 == s2) if(kmp(s1))
        {
            d++;
            return;
        }
    }
    if(a[x + 1][y] != '#') dfs(x + 1, y, s1);
    if(a[x][y + 1] != '#') dfs(x, y + 1, s1);
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".INP","r",stdin);
    freopen(file".OUT","w",stdout);

    cin >> n >> m >> k >> s;
    a.resize(n + 1, vector<char>(m + 1, '#'));
    for(ll i = 0; i < n; i++)
        for(ll j = 0; j < m; j++)
            cin >> a[i][j];
    if(a[0][0] == '#' || a[n - 1][m - 1] == '#'){
        cout << 0;
        return 0;
    }
    f.resize(s.size(), 0);
    ll j = 0;
    for(ll i = 1; i < s.size(); i++)
        if(s[i] == s[j]) f[i] = ++j;
        else if(j > 0){
            j = f[j - 1];
            while(s[i] != s[j] && j > 0)
                j = f[j - 1];
            if(j < 0) j = 0;
            if(s[i] == s[j]) f[i] = ++j;
        }
    dfs(0, 0, "");
    cout << d;
    
    return 0;
}
