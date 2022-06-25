#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int double
typedef string str;
typedef pair <int,int> P;
#define file "TEST"
#define X first
#define Y second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define bin binarnd_search
#define vll vector<ll>
#define vi vector<int>
#define el cout << endl;
#define all(v) (v).begin(), (v).end()
#define FOR(i,st,nd) for(ll i = st; i <= nd; i++)
#define FOS(i,st,nd) for(ll i = st; i >= nd; i--)
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;

int norm(P a, P b) {
    return (b.X - a.X) * (b.X - a.X) + (b.Y - a.Y) * (b.Y - a.Y);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    
    ll n; cin>>n;
    vector<P> v(n);
    int d = LLONG_MAX;
    for (ll i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        v[i] = {x, y};
    }
    sort(v.begin(), v.end());
    set<P> s = {{v[0].Y, v[0].X}};
    ll j = 0;
    for (ll i = 1; i < n; i++) {
        auto it = s.begin();	
        int dd = sqrt(d);
        while (j < i && v[j].X < v[i].X - dd) {
            s.erase({v[j].Y, v[j].X});
            j++;
        }

        auto l = s.lower_bound({v[i].Y - dd, 0});
        auto r = s.upper_bound({v[i].Y + dd, 0});
        for (auto it = l; it != r; it++) {
            d = min(d, norm({it->Y, it->X}, v[i]));
        } 
        s.insert({v[i].Y, v[i].X});
    }
    cout << sqrt(d);
}