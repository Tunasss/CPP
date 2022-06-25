#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <ll,ll> ii;
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

#define pii pair <int, ii>
const ll N = 1005;
const ll oo = 9e9;

ll n, m;
ll a[N][N], d[N][N];
ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};

void BFS (){
	FOR(i,1,n) FOR(j,1,m) d[i][j] = oo;
    priority_queue<pii, vector<pii>, greater<pii>> myque;

    d[1][1] = (a[1][1] == 0);
    myque.push({d[1][1], {1, 1}});

    while (!myque.empty()) {
        pii current = myque.top(); 
        myque.pop();
        ii u = current.nd;
        ll distance = current.st;
        ll x = u.st;
        ll y = u.nd;

        if (distance != d[x][y]) continue;

        for (ll i = 0; i < 4; i++)
        {
            ll r = x + dx[i], c = y + dy[i];
            if (r > 0 && r <= n && c > 0 && c <= m)
                if (d[r][c] > distance + 1 + (a[x][y] == a[r][c])) {
                    d[r][c] = distance + 1 + (a[x][y] == a[r][c]);
                    myque.push({d[r][c], {r, c}});
                }
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n >> m;
    FOR(i,1,n){
        FOR(j,1,m){
            cin >> a[i][j];
        }
    }
    BFS();
    cout << d[n][m];
    
    return 0;
}

