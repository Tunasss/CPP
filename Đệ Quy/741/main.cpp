#include <iostream>
using namespace std;
float lt (float n)
{
    if (n==0) return 1;
    else return lt(n-1)*n;
}
float bt741 (float n)
{
    if (n==1) return 1;
    else return bt741(n-1)+lt(n-1)*n;
}
int main()
{
    int n;
    cin>>n;
    cout<<bt741(n);
    return 0;
}
