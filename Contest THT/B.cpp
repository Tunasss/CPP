#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n ,dem =0;
    int a[10000];
    cin>>n;
    for (int i =0;i<n;i++)
        cin>>a[i];
    sort (a,a+n,greater<int>());
    for (int i =0;i<n;i++)
    {
        c=a[i];
       if(a[i]>=dem)
            dem=dem +1;
    }
    cout<<dem;
    return 0;
}