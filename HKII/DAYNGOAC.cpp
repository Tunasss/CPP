#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;
#define file "DAYNGOAC"
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

#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

const ll N = 1e7 + 1;
const ll MOD = 12345678910;
ll n;
stack<ll> st;
ll a[N], sum[N];

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".INP","r",stdin);
    freopen(file".OUT","w",stdout);
    
    cin >> n;
    FOR(i,1,n){
        bool c;
        cin >> c;
        if(c == 0) st.push(i);
        else{
            if(!st.empty()){
                ll tmp = st.top(); 
                st.pop();
                if(i - 1 == tmp)
                	a[tmp] = 1;
                else a[tmp] = (a[tmp] * 2) % MOD;

                if (st.empty()) a[0] = (a[0] + a[tmp]) % MOD;
                else a[st.top()] = (a[st.top()] + a[tmp]) % MOD;
            }
        }
    }

    cout << a[0];
    
    return 0;
}
