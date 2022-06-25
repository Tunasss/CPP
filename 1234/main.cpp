#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("1234.inp","r",stdin);
    freopen("1234.out","w",stdout);
//    ios_base::sync_with_stdio(false)
//    cin.tie(NULL);
//    cout.tie(NULL;
    int a[1005];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    sort(a,a+n,greater<int>());
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
