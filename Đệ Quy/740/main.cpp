#include <iostream>
using namespace std;
double gt(int n)
{
    if(n==1) return 1;
    else return gt(n-1)*n;
}
double bt740(int n)
{
    if(n == 1) return 1;
    return bt740(n-1) + gt(n-1)*n;
}
int main()
{
    int n;
    cin>>n;
    cout<<bt740(n);
    return 0;
}
