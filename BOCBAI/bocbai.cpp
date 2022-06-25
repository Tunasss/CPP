#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//( ͡° ͜ʖ ͡°)
//Tunass

ll n,a[100000000];

int main ()
{
    cin >> n;
    if (n==1)
    {
        cout<<"THANG";
        return 0;
    }
    for (ll i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    ll s=0,m=0;
    s+=a[1];
    for (ll i=2; i<=n; i=i+4)
    {
            m+=a[i]+a[i+1];
            s+=a[i+2]+a[i+3];
    }
    if (s>m)
        cout<<"THANG";
    else if (s==m)
        cout<<"HOA";
    else cout<<"THUA";
}
