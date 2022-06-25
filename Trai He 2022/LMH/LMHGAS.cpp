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

struct box{
    ll vol;
    ll pri;
};

ll n, k;
deque<box> que;
ll a, cost;
    
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n >> k;
    cin >> a;
    que.pb({k, a});
    for(ll i = 2; i <= n; i++){
        cin >> a;

        cost += que.front().pri;
        que.front().vol--;

        if(que.front().vol <= 0) que.pop_front();

        ll t = 1;
        while(!que.empty() && que.back().pri > a){

            t += que.back().vol;
            que.pop_back();
            que.pb({t, a});
        }
        cout << cost << endl;
        if(que.empty())que.push_back({(n - i) % k, a});
    }
    cout << cost;
    
    return 0;
}
