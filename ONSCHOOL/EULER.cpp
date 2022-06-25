#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;
#define file "TEST"
#define st first
#define nd second
#define pb push_back
#define pf push_front
#define mp make_pair
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
const ll MOD = 2021;

const ll MAX = 200
int n, m;
vector<int> in[MAX];

void euler(int x){
    stack<int> q, ok;
    q.push(x);
    while (!q.empty()){
        int now = q.top();
        if (!in[now].empty()){
            int y = in[now][0];
            q.push(y);
            in[now].erase(in[now].begin());
            in[y].erase(find(in[y].begin(), in[y].end(), now));
        }else{
            q.pop();
            ok.push(now);
        }
    }
    while (!ok.empty()){
        cout << ok.top() << " ";
        ok.pop();
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n >> m;
    for (int i=0; i<m; ++i){
        int u, v, w;
        cin >> u >> v;
        in[u].push_back(v);
        in[v].push_back(u);
    }


    euler(1);
}