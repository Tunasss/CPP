#include <bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;
int main ()
{
    ll x,y,z;
    cin >> x >> y >> z;
    x *= 1000;
    x -= 2*z;
    long dem=0;
    dem = x/(y+z);
    cout << dem;
}

