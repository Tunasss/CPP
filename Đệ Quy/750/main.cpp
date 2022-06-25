#include <iostream>
#include <math.h>
using namespace std;
float bt750(float i, float n)
{
    if(n == i) return sqrt(n);
    else return sqrt( i + bt750(i+1,n));
}
int main()
{
    int n,i ;
    cin>>n;
    cout<<bt750(i,n);
    return 0;
}
