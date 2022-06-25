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
#define el cout << endl;
#define all(v) (v).begin(), (v).end()
#define FOR(i,x,y) for(ll i = x; i <= y; i++)
#define FOS(i,x,y) for(ll i = x; i >= y; i--)
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

const ll oo = 99999999999;
const ll N = 2e5 + 5;
ll a[N], n, q;
ll tr[N * 4];
multiset<ll> tree[N * 4];

void build(int id, int L, int R)
{
    if (L < 1 || R > n) return;
    if (L == R) { 
        tree[id].insert(a[L]);
        return;
    }

    int M = (L + R) / 2;
    build(2 * id + 1, L, M);
    build(2 * id + 2, M + 1, R);

    tree[id] = tree[2 * id + 1];
    tree[id].merge(tree[2 * id + 2]);
}

void update(int x, int id, int L, int R, int val)
{
    if (L < 1 || R > n) return;
    if (L == R) { 
        tree[id].erase(tree[id].begin());
        tree[id].insert(val);
        return;
    }

    int M = (L + R) / 2;
    if (x < M) update(x, 2 * id + 1, L, M, val);
    else update(x, 2 * id + 2, M + 1, R, val);

    auto tmp = tree[id].lower_bound(a[x]);
    tree[id].erase(tmp); 
    tree[id].insert(val);
}

ll get(int id, int L, int R, int Lq, int Rq, int type, int k){
    if (L > Rq || R < Lq) return 0;
    if (L == R) { 
        int tmp = *tree[id].begin();
        if (type == 2){
            if (tmp >= k) return tmp;
            return oo;
        }
        if (type == 3){
            if (tmp <= k) return tmp;
            return -1;
        }
    }

    int M = (L + R) / 2;

    if (Lq <= L && Rq >= R){
        auto tmp = lower_bound(tree[id].begin(), tree[id].end(), k);
        if (type == 2) {
            if (tmp == tree[id].begin()) return oo;
            else return *tmp;
        }
        if (tmp == tree[id].begin()) return -1;
        else if (*tmp == k) return *tmp;
        else return *(--tmp);
    }

    ll t1 = get(2 * id + 1, L, M, Lq, Rq, type, k);
    ll t2 = get(2 * id + 2, M + 1, R, Lq, Rq, type, k);
    if (type == 2) return min(t1,t2);
    return max(t1,t2);
}


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    build(0, 1, n);

    while (q--)
    {
        int opp;
        cin >> opp;
        if (opp == 1){
            int i, v;
            cin >> i >> v;
            update(i, 0, 1, n, v);
            a[i] = v;
        }
        else if (opp == 2){
            int l, r, k;
            cin >> l >> r >> k;
            ll tmp = get(0, 1, n, l, r, k, 2);
            if (tmp == oo) cout << -1;
            else cout << tmp;
            el;
        }
        else if (opp == 3){
            int l, r, k;
            cin >> l >> r >> k;
            ll tmp = get(0, 1, n, l, r, k, 3);
            cout << tmp;
            el;
        }
    }
    
    return 0;
}


