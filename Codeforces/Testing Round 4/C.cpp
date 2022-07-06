#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;
#define file "DECOMP"
#define st first
#define nd second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define bin binary_search
#define vll vector<int>
#define all(v) (v).begin(), (v).end()
#define FOR(i,x,y) for(int i = x; i <= y; ++i)
#define FOS(i,x,y) for(ll i = x; i >= y; --i)
#define EACH(i,x) for (auto &(i) : (x))
#define el cout << '\n';
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

const ll N = 1e5 + 5;

int k,n;
int a[N], res = 0;
vll num;

void process(vll num){
    int i = 0;

    map<ll,ll> cnt;

    for(auto x : num){
        while(x--){
            cnt[a[i]]++;
            if(cnt[a[i]] == 1) res++;
            if(cnt[a[i]] == k + 1) res--;
            ++i;
        }
        cnt.clear();
    }
}

void quaylui()
{
    int sum = 0;
    for(auto x : num) sum += x;

    if (sum > n) return;

    if (sum == n){
        process(num);
    }

    FOR(i,1,n){
        num.pb(i);
        quaylui();
        num.pop_back();
    }
}

signed main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".INP","r",stdin);
    freopen(file".OUT","w",stdout);

    cin >> n >> k;

    FOR(i,0,n - 1){
    	cin >> a[i];
    }

    quaylui();

    cout << res;
    return 0;
}