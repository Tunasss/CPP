#include <iostream>
using namespace std;
float bt736 (float n)
{
    if (n==1) return 0.5;
    else return bt736(n-1) + n/(n+1);
}
int main()
{
    int n;
    cin>>n;
    cout<<bt736(n);
    return 0;
}
