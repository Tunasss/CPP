#include <iostream>
#include <math.h>
using namespace std;
float bt749 (float n)
{
    if (n==1) return 1;
    else return sqrt(n+bt749(n-1));
}
int main()
{
    int n;
    cin>>n;
    cout<<bt749(n);
    return 0;
}
