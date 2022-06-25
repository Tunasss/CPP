#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//( ͡° ͜ʖ ͡°)
//Tunass
int main ()
{
    unsigned long long n;
    cin >> n;
    n--;
    if (n % 2 == 0) n--;
    unsigned long long spt = (n-1)/2+1;
    cout << spt*(1+n)/2; 
}
