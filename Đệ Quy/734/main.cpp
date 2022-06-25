#include <iostream>
using namespace std;
float bt734 (float n)
{
    if (n==1) return 1;
    else return bt734(n-1)+1/(2*n+1);
}
int main()
{
    int n;
    cin>>n;
    cout<<bt734(n);
    return 0;
}
