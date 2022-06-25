#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//( ͡° ͜ʖ ͡°)
//Tunass

int main ()
{
    ll n;
    cin >> n;
    vector <ll> a(n+1);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    } 
    ll kq = 0;
    vector <ll> f(n+1);
    for (ll i = 0; i < n; i++)
    {
        f[i] = a[i];
        for (ll j = 0; j < i; j++)
        {
            if (a[j] <= a[i])
            {
                f[i]=max(f[i],a[j]+a[i]);
            }
        kq = max(kq,f[i]);
        }
    }
    cout << kq;
}
