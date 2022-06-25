#include <bits/stdc++.h>
using namespace std;
int main()
{
//    freopen("MAXSEQ.inp","w",stdin);
//    freopen("MAXSEQ.out","r",stdout);
    int n,k;
    cin>>n>>k;
    int arr[1005];
    for (int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    int d=0,temp=1;
    for (int i=0;i<n;i++)
    {
       if (arr[i]==arr[i+1])
           temp++;
       if (temp>=k)
           temp=k;
       if (arr[i]!=arr[i+1]&&arr[i]!=arr[i-1])
           d++;
       if (arr[i]!=arr[i+1]&&arr[i]==arr[i-1])
       {
           d+=temp;
           temp=1;
       }
    }
    cout<<d;
}
