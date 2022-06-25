#include <iostream>
using namespace std;
int main()
{
    char a[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int n;
    cin>>n;
    int k;
    while (n>=15)
    {
        k=n%16;
        cout<<a[k];
        n/=16;
        k=0;
    }
}
