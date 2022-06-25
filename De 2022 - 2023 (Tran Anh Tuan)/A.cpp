#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n, res = 0;
    cin >> n;
    for (ll i = 1; i <= sqrt(n); i++){
        res += i * i;
    }
    cout << res;
}
