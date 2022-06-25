#include <iostream>
using namespace std;
float bt735 (float n)
{
    if (n==1) return 0.5;
    else return bt735(n-1) + 1/(n*(n+1));
}
int main()
{
    int n;
    cin>>n;
    cout<<bt735(n);
    return 0;
}
