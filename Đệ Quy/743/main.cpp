#include <bits/stdc++.h>
using namespace std;
int bt743 (int x,int n)
{
    if (n==1) return pow(x,n);
    return bt743(x,n-1) + pow(x,2*n+1);
}
int main()
{
    int n,x;
    cin>>x>>n;
    cout<<bt743(x,n);
    return 0;
}
