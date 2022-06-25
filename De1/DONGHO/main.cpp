#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    freopen("DONGHO.inp","r",stdin);
    freopen("DONGHO.out","w",stdout);
    ll n;
    cin>>n;
    ll k=1;
    if (n>=0)
        k+=n%12;
    else if (n<0)
        k=13+n%12;
    cout<<k;
}
