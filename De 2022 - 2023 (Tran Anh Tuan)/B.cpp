#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll a,b;
    cin >> a >> b;
    cout << a / __gcd(a,b) * b;
}
