#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll,ll> ii;
#define st first
#define nd second

#define FOR(i,x,y) for(ll i = x; i <= y; ++i)
#define el cout << endl;

ll n, m, k;

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    
    cin >> n >> m >> k;

    ll temp = k % m;
    vector<ii> a(n);

    FOR(i,0,n - 1) {
    	FOR(j,0,m - 1){
            ll cur;
            cin >> cur;
            a[i].st += cur;

            if (j + 1 == temp) a[i].nd = a[i].st;
        }
    }
    sort(a.begin(), a.end(), greater<ii>());

    
    ll take = k / m;

    ll sum = 0, max_temp = 0;
    for (ll i = 0; i < take; i++) sum += a[i].st;
    for (ll i = take; i < n; i++) max_temp = max(max_temp, a[i].nd);

    ll res = sum + max_temp;
	
	if (temp == 0){
		cout << res;
		el;
		return 0;
	}

	sum += a[take].st;

    for (ll i = 0; i < take; i++)
        res = max(res, sum - a[i].st + a[i].nd);

    cout << res << "\n";
    return 0;
}
