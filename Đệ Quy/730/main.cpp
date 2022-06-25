#include <iostream>
using namespace std;
int bt730(int n)
{
    if (n==1) return 1;
    else return tong730(n-1)+n;
}
int main()
{
    int n;
    cin>>n;
    cout<<bt730(n)<<endl;
    return 0;
}
