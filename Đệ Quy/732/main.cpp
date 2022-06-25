#include <iostream>
using namespace std;
float bt732 (float n)
{
    if (n==1) return 1;
    else return bt732(n-1)+1/n;
}
int main()
{
    int n;
    cin>>n;
    cout<<bt732(n);
    return 0;
}
