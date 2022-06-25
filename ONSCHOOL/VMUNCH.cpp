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

int m,n;
char graph[105][105];
int d[105][105];
queue <ii> q;
const int dx[4] = {-1,0,0,1};
const int dy[4]={0,1,-1,0};

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> m >> n;
    int iC, jC, iB, jB;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            d[i][j] = 0;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
        {
            cin >> graph[i][j];
            if(graph[i][j] == 'C'){
                iC = i;
                jC = j;
            }
            if(graph[i][j] == 'B'){
                iB = i;
                jB = j;
            }
        }
    q.push(make_pair(iC,jC));
    ii x;
    while(!q.empty() && d[iB][jB]==0)
    {
        x = q.front();
        q.pop();
        int i,j;
        for(int k = 0; k < 4; k++)
        {
            i = x.st + dx[k];
            j = x.nd + dy[k];

            if(i > 0 && i <= m && j > 0 && j <= n && d[i][j] == 0 && graph[i][j] != '*')
            {
                d[i][j] = d[x.st][x.nd] + 1;
                q.push(make_pair(i,j));
            }
        }
    }
    if(d[iB][jB] == 0) d[iB][jB] = -1;
    cout << d[iB][jB];
}