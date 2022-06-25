#include <iostream>
using namespace std;
typedef long long ll;
int a[1005];
int gt(int n);
ll n;
ll tancung(ll n)
{
    ll d=0,k=5;
    while (k<=n){
        d+=n/k;
        k*=5;
    }
    return d;
}
int main()
{

    cin>>n;
    for (ll i=0;i<n;i++)
        cin>>a[i];
    for (ll i=0;i<n;i++)
    {
       cout<<tancung(a[i])<<endl;
    }
    return 0;
}
