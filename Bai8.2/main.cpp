#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll tcs(ll x)
{
    ll t = 0;
    while(x>0)
    {
        t+=x%10;
        x/=10;
    }
    return t;
}
int main()
{
//    freopen("BAI8.2.INP","r",stdin);
//    freopen("BAI8.2.OUT","w",stdout);
    ll n,d=0,x;
    cin>>n;
    vector<int>a;
    for(ll i = 0; i < n; i++)
    {
        cin>>x;
        a.push_back(tcs(x));
    }
    for(ll i = 0; i < n-1; i++)
        for(ll j = i + 1; j < n; j++)
            if((a[i] + a[j]) % 9 == 0)
                d++;
    cout<<d;
    return 0;
}
