#include <iostream>
using namespace std;
int bt747(int n)
{
    if(n%2==1) return n;
    return bt747(n/2);
}
int main()
{
    int n;
    cin>>n;
    cout<<bt747(n);
    return 0;
}
