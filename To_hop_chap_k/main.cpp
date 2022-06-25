#include <bits/stdc++.h>
#define maxpt 50
using namespace std;
int n,x[maxpt];
int a[1005];
void tohop (int i);
int main()
{
//    freopen("To_hop_chap_k.inp","r",stdin);
//    freopen("To_hop_chap_k.out","w",stdout);
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i];
    tohop(0);
}
void tohop (int i)
{
    for(int j=x[i-1]+1; j<=5; j++)
    {
        x[i]=j;
        if (i==n-1)
        {
            for(int k=0; k<n; k++)
                cout<<x[k]<<" ";
            cout<<endl;
        }
        else tohop(i+1);
    }
}
