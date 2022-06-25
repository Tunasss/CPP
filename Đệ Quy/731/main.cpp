#include <iostream>
using namespace std;
int bt731 (int n)
{
    if (n==1) return 1;
    else return tong731(n-1)*n;
}
int main()
{
    int n;
    cin>>n;
    cout<<bt731(n);
    return 0;
}
