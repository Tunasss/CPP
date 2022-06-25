#include <iostream>
using namespace std;
int bt738 (int n)
{
    if (n==1) return 1;
    else return n*bt738(n-1);
}
int main()
{
    int n;
    cin>>n;
    cout<<bt738(n);
    return 0;
}
