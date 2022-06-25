#include <iostream>
using namespace std;
float t(float n)
{
    if(n == 1) return (float)1;
    return t(n-1) + n;
}
float bt744(float n)
{
    if(n == 1) return (float)1;
    return bt744(n-1) + 1/(t(n-1) + n);
}
int main()
{
    int n;
    cin>>n;
    cout<<bt744(n);
    return 0;
}
