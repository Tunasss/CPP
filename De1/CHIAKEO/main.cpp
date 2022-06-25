#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    freopen("CHIAKEO.INP","r",stdin);
    freopen("CHIAKEO.OUT","w",stdout);
    ll n,a[10000],d=0,t=0;
    cin>>n;
    for (ll i=0;i<n;i++)
        cin>>a[i];
    if (n%2==1)
        t=1;
    sort (a,a+n,greater<ll>());
    for (ll i=t;i<n;i++)
        {
            d=abs(a[n]-a[i]);
            a[n]=d;
        }
    cout<<d;
}
//    b[0]=a[0];
//    c[0]=a[1];
//    ll sum1=0,sum2=0;
//    sum1=b[0];
//    sum2=c[0];
//    for (ll i=2;i<n;i++)
//    {
//        if (a[i]+sum1<a[i]+sum2)
//        {
//            sum1+=a[i];
//        }
//        else if (a[i]+sum2<a[i]+sum1)
//        {
//            sum2+=a[i];
//        }
//        else if (a[i]+sum2==a[i]+sum1)
//        {
//            sum1+=a[i];
//        }
//    }
//     cout<<sum1<<" "<<sum2;
//    if (sum2>sum1) cout<<sum2-sum1;
//    if (sum2<sum1) cout<<sum1-sum2;
//    if (sum2==sum1) cout<<0;
