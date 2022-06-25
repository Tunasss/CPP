#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//( ͡° ͜ʖ ͡°)
//Tunass
const ll full=10000000;
vector <ll> kq(full,0);
ll maxx=1;
int main ()
{
    ll k=0;
    ll t,n;
    cin >> t;
    for (ll x = 0; x < t; x++)
    {
        vector <ll> a(full,0);
        cin >> n;
        for (ll j = 1; j <= n; j++)
        {
            cin >> a[j];
        }
        for (ll i = 1; i <= n; i++)
        {
            maxx = 1;
            for (ll j = i; j <= n; j++)
            {
                if ((a[j] < 0 && a[j+1] > 0) || (a[j] > 0 && a[j+1] < 0))
                {
                    maxx++;
                }
                else break;  
            }
            kq[k] = maxx;
            k++;
        }
        n = 0;
    } 
    for (ll i=0; i<k; i++)
    {
        cout << kq[i] <<" ";
    }
}
