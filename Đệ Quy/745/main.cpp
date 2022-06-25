#include <iostream>
using namespace std;
float lt (float x, float n)
{
    if(n == 1)
    {
        return x;
    }
    return lt (x,n-1)*x;
}
float gt(float n)
{
    if(n == 1)
    {
        return (float)1;
    }
    return gt(n-1)*n;
}
float bt745(float x, float n)
{
    if(n == 1)
    {
        return x;
    }
    return bt745(x,n-1) + ((lt(x,n-1)*x) / (gt(n-1)*n));
}
int main()
{
    int n
    cin>>n;
    cout<<bt745(n);
    return 0;
}
