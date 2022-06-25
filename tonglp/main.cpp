#include <iostream>
using namespace std;
int vc (int n)
{
    int dem=0;
    int i=1;
    int j=1;
    int k=0;
    while (j*j*j+1<n) j++;
    while (j>=i)
    {
        if (i>j) break;
        k=i*i*i+j*j*j;
        if (k==n)
        {
            dem++;
            cout<<i<<" "<<j<<endl;
            i++;
            j--;
        }
        if (k<n) i++;
        if (k>n) j--;
    }
    return dem;
}
int main()
{
    int n;
    cin>>n;
    cout<<vc(n);
    return 0;
}
