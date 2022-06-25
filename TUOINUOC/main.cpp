#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//( ͡° ͜ʖ ͡°)
//Tunass

ll n,k;
ll a[1000000];
ll b[1000000];
int main ()
{
    int dem=0,maxx=0;
    cin >> n >> k;

    for (ll i = 0; i < k; i++)
    {
        int temp;
        cin >> temp;
        a[temp] = temp;
    }
    if (n==2)
    {
        cout << "2";
        return 0;
    }

    for (ll i = 1; i <= n; i++)
    {
        if (i!=a[i])
        {
            dem++;
        }
        else
        {
            if (maxx < dem)
            maxx = dem;
            dem = 1;
        }
    }

    ll kcc = 0;
    for (ll i=n; i>=1; i--)
    {
        if (i!=a[i])
        {
            kcc++;
        }
        else break;
    }
    
    if (maxx > kcc)
    cout << maxx / 2 + 1;
    else cout << kcc + 1;
}
