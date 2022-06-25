#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair <int,int> ii;
#define file "GRECUTSEG"
#define st first
#define nd second
#define pb push_back
#define sz size
#define FOR(i,x,y) for(ll i = x; i <= y; i++)

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".INP","r",stdin);
    freopen(file".OUT","w",stdout);

    ll a[150000];
    ll t;
    cin >> t;
    while(t--){
    	unordered_map<ll,ll> mymap;
		vector<ii> dp;
		ll n;
        cin >> n;
        FOR(i,1,n) cin >> a[i];
        ll d = 1;
        FOR(i,1,n){
            mymap[a[i]]++;
            if (mymap[a[i]] == 2)
            {
                dp.pb({d,i}); 
                FOR(k,d,i) mymap[a[k]] = 0;
                d = i + 1;
            }
        }
        if (d != 1){
        	if (d <= n) dp[dp.sz()-1].nd = n;
            for (auto itr:dp) cout << itr.st << " " << itr.nd <<"\n";
        }
        else cout << -1 << "\n";
    }
    return 0;
}
