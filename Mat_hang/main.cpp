#include <bits/stdc++.h>
#define maxpt 50
typedef long long ll;
using namespace std;
ll n,x[maxpt],a[1005],sum=0,maxx;
void mathang (ll i);
int main()
{
//    freopen("Mat_hang.inp","r",stdin);
//    freopen("Mat_hang.out","w",stdout);
    cin>>n;
    for (ll i=0;i<n;i++)
        cin>>a[i];
    mathang(0);
}
void mathang (ll i)
{
    for(ll j=x[i-1]+1; j<=5; j++)
    {
        x[i]=j;
        if (i==n-1)
        {
            for(ll k=0; k<n; k++)
                cout<<x[k]<<" ";
            cout<<endl;
        }
        else mathang(i+1);
    }
}
