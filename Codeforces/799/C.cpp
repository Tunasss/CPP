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

str s[8];
str p[8];

bool check(ll x, ll y){
    FOR(i,0,7){
        p[i] = "";
        FOR(j,0,7){
            p[i] = p[i] + ".";
        }
    }
    p[x][y] = '#';
    FOR(i,1,8){
        ll x2 = x - i, y2 = y - i;
        if (x2 < 0 || x2 >= 8 || y2 < 0 || y2 >= 8) break;
        p[x2][y2] = '#';
    }
    FOR(i,1,8){
        ll x2 = x - i, y2 = y + i;
        if (x2 < 0 || x2 >= 8 || y2 < 0 || y2 >= 8) break;
        p[x2][y2] = '#';
    }
    FOR(i,1,8){
        ll x2 = x + i, y2 = y + i;
        if (x2 < 0 || x2 >= 8 || y2 < 0 || y2 >= 8) break;
        p[x2][y2] = '#';
    }
    FOR(i,1,8){
        ll x2 = x + i, y2 = y - i;
        if (x2 < 0 || x2 >= 8 || y2 < 0 || y2 >= 8) break;
        p[x2][y2] = '#';
    }
    FOR(i,0,7){
        if (p[i] != s[i]) return false;
    }
    return true;
}

void solve(){
    FOR(i,0,7) cin >> s[i];
    FOR(i,0,7){
        FOR(j,0,7){
            if (check(i, j)){
                cout << i + 1 << " " << j+1 << endl;
                return;
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    ll t;
    cin >> t;
    while(t--){
    	solve();
    }
    
    return 0;
}
