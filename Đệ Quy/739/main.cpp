#include <iostream>
using namespace std;
int bt739(int n)
{
    if (n==0) return 1;
    else if (n<0) return bt739(n+1)*1/n;
    return bt739(n-1)*n;
}
int main()
{
    int n;
    cin>>n;
    cout<<bt739(n);
    return 0;
}
