#include <iostream>
using namespace std;
int main()
{
    int a[1005];
    int n;
    cin>>n;
    int max=INT_MIN,bs,es,b=0;
    for (int i=0;i<n;i++)
    {
         cin>>a[i];
         b+=a[i];
         if (b>max)
         {
             max=b;
             es=i;
         }
    }
    b=0;
    max=INT_MIN;
    for (int i=es;i>=0;i--)
    {
        b+=a[i];
        if (b>max)
        {
            max=b;
            bs=i;
        }
    }
    for (int i=bs;i<=es;i++)
        cout<<a[i]<<" ";
    return 0;
}
