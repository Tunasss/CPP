#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//( ͡° ͜ʖ ͡°)
//Tunass
const ll full=1000000;
int main ()
{
    ll n;
    cin >> n;
    vector <ll> t(full),r(full),k(full);
    ll maxx=0;
    for (ll i = 1; i <= n; i++)
    {
        cin >> t[i];
    }
    for (ll j = 1; j <= n-1; j++)
    {
        cin >> r[j];
    }
    k[1]=t[1];
    for (ll i = 2; i <= n; i++)
    {
        k[i]=min(k[i-2]+r[i-1],k[i-1]+t[i]);
    }
    cout<<k[n];
}