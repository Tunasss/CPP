#include <iostream>
using namespace std;
float bt748(float n)
{
    if(n == 1)
    {
        return sqrt(2);
    }
    return sqrt(2 + 748(n-1));
}
int main()
{
    int n;
    cin>>n;
    cout<<bt748(n)
    return 0;
}
