#include <bits/stdc++.h>
using namespace std;
double bt742(int x, int n)
{
    if (n==1) return pow(x,n);
    return bt742(x,n-1) + pow(x,n*2);
}
int main()
{
    int x,n;
    cin>>x>>n;
    cout<<bt742(x,n)<<endl;
    return 0;
}
