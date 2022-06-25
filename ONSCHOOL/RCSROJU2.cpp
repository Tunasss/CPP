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

const ll N = 505;
int m,n;
char graph[N][N];
ll d[N][N] = {};
queue <ii> q;
const int dx[4] = {-1,0,0,1};
const int dy[4] = {0,1,-1,0};

ll iR, jR, iJ, jJ;
vector <ii> res;

bool safe(ll i, ll j){
    if (i < 1 || j < 1 || i > m || j > n || graph[i][j] == 'x') return 0;
    return 1;
}
void backtrace(ll i, ll j){
    
    if (i == iR && j == jR) {
        return;
    }

    if (d[i][j] == d[i - 1][j] + 1 && safe(i - 1, j)){
        res.pb({i - 1, j});
        backtrace(i - 1, j);
    }

    else if (d[i][j] == d[i][j - 1] + 1 && safe(i, j - 1)){
        res.pb({i, j - 1});
        backtrace(i, j - 1);
    }

    else if (d[i][j] == d[i + 1][j] + 1 && safe(i + 1, j)){
        res.pb({i + 1, j});
        backtrace(i + 1, j);
    }

    else if (d[i][j] == d[i][j + 1] + 1 && safe(i, j + 1)){
        res.pb({i, j + 1});
        backtrace(i, j + 1);
    } 
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> m >> n;
    
    for(ll i = 1; i <= m; i++)
        for(ll j = 1; j <= n; j++)
            d[i][j] = 0;
    for(ll i = 1; i <= m; i++){
        for(ll j = 1; j <= n; j++){
            cin >> graph[i][j];
            if(graph[i][j] == 'R'){
                iR = i;
                jR = j;
            }
            if(graph[i][j] == 'J'){
                iJ = i;
                jJ = j;
            }
        }
    }
    q.push({iR,jR});
    ii x;
    while(!q.empty() && d[iJ][jJ] == 0)
    {
        x = q.front();
        q.pop();
        ll i,j;
        for(ll k = 0; k < 4; k++)
        {
            i = x.st + dx[k];
            j = x.nd + dy[k];

            if(i > 0 && i <= m && j > 0 && j <= n 
                && d[i][j] == 0 && graph[i][j] != 'x')
            {
                d[i][j] = d[x.st][x.nd] + 1;
                q.push({i,j});
            }
        }
    }
    if(!d[iJ][jJ]){
        cout << "NO";
        return 0;
    }
    else {
        cout << "YES\n" << d[iJ][jJ] + 1 << '\n';
        if (d[iJ][jJ] + 1 == 2){
            cout << iR << " " << jR << '\n';
            cout << iJ << " " << jJ;
            return 0;
        }
        res.pb({iJ, jJ});
        backtrace(iJ, jJ);
        res.pb({iR, jR});
        reverse(res.begin(), res.end());

        for (auto x : res){
            cout << x.st << ' ' << x.nd << '\n';
        }
    }
}