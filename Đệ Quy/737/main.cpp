#include <iostream>
using namespace std;
float bt737 (float n)
{
    if (n==0) return 0.5;
    else return bt736(n-1) + (2n+1)/(2n+2);
}
int main()
{
    int n;
    cin>>n;
    cout<<bt737(n);
    return 0;
}
