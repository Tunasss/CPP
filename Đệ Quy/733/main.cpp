#include <iostream>
using namespace std;
float bt733 (float n)
{
    if (n==1) return 0.5;
    else return bt733(n-1)+1/(2*n);
}
int main()
{
    int n;
    cin>>n;
    cout<<bt733(n);
    return 0;
}
