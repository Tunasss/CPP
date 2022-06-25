#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    freopen("TIMSO.INP","r",stdin);
    freopen("TIMSO.OUT","w",stdout);
    ll n;
    cin>>n;
    int a[1005];
    for (ll i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n,greater<int>());
    for (ll i=0;i<n;i++)
    {
        if (a[i]!=a[i+1])
            {
        cout<<a[i+1];
        break;
            }
    }
    return 0;
}
