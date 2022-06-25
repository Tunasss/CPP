#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//( ͡° ͜ʖ ͡°)
//Tunass


ll n,k;

int main ()
{
    cin >> n >> k;
    vector <ll> a(n + 1), b(n + 1,INT_MIN);
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll maxx = 0;
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = 1; j <= k; i++)
        {
            b[i+j]=max(b[i+j],b[i]+a[i+j]);
            if (maxx < b[i+j])
            maxx = b[i+j];
        }
    }
    cout << maxx;
}
