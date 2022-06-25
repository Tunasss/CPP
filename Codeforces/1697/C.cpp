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

ll t, n;
void solve()
{
    string s, t, ss, tt;
    cin >> n >> s >> t;
    vll pa[2], pc[2];
    s = ' ' + s, t = ' ' + t;
    FOR(i,1,n){
        if (s[i] == 'a') pa[0].push_back(i);
        if (s[i] == 'c') pc[0].push_back(i);
        if (s[i] != 'b') ss += s[i];
    }
    FOR(i,1,n){
        if (t[i] == 'a') pa[1].push_back(i);
        if (t[i] == 'c') pc[1].push_back(i);
        if (t[i] != 'b') tt += t[i];
    }

    if (ss != tt)
    {
        cout << "NO";
        return;
    }

    for (int i=0; i<pa[0].size(); i++)
    {
        if (pa[0][i] > pa[1][i])
        {
            cout << "NO";
            return;
        }
    }
    for (int i=0; i<pc[0].size(); i++)
    {
        if (pc[0][i] < pc[1][i])
        {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    ll q;
    cin >> q;
    while(q--){
        solve();
        cout << '\n';    
    }
    
    return 0;
}