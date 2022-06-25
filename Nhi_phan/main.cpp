#include <bits/stdc++.h>
#define maxpt 50
using namespace std;
int n,x[maxpt];
void nhiphan (int i);
int main()
{
//    freopen("Nhi_phan.inp","r",stdin);
//    freopen("Nhi_phan.out","w",stdout);
    cin>>n;
    nhiphan(0);
}
void nhiphan (int i)
{
    for(int j=0; j<=1; j++)
    {
        x[i]=j;
        if (i==n-1)
        {
            for(int k=0; k<n; k++)
                cout<<x[k]<<" ";
            cout<<endl;
        }
        else nhiphan(i+1);
    }
}
