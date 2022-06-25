#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("HOMEWORK.INP","r",stdin);
    freopen("HOMEWORK.OUT","w",stdout);
    ll n, s;
    cin >> n >> s;
    ll a[n];
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    sort(a,a + n);
    ll dem = 0;
    for (ll i = 0; i < n; i++){
        if(s >= a[i]){
            dem++;
            s += a[i]; 
        }
    }
    cout << dem;
}