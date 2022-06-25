//Tran Anh Tuan - 10 Tin - CTL
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,x,y) for(ll i = x; i <= y; i++)

const ll N = 1e6 + 5;

struct edge {
    ll u, v, w;
};

ll n, m;
ll cha[N], hang[N];
edge e[N];

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

ll find(ll u) {
    if (cha[u] != u) cha[u] = find(cha[u]);
    return cha[u];
}

bool join(ll u, ll v) {
    u = find(u); 
    v = find(v);
    if (u == v) return false;
    if (hang[u] == hang[v]) hang[u]++;
    if (hang[u] < hang[v]) cha[u] = v;
    else cha[v] = u;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n >> m;
    FOR(i,1,m) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }

    sort(e + 1, e + 1 + m, cmp);

    FOR(i,1,n){
        cha[i] = i;
        hang[i] = 0;
    }
    ll res = 0;

    FOR(i,1,m) {
        if (join(e[i].u, e[i].v)) {
            res += e[i].w;
        }
    }
    cout << res;
    return 0;
}