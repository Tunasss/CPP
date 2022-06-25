#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool c(ll n){
    if (n < 2) return 0;
    for(ll i = 2; i <= sqrt(n); i++){
        if (n % i == 0) return 0;
    }
    return 1;
}

int main()
{
    ll n, res = 99999999999;
    cin >> n;
    while(n--){
        ll x;
        cin >> x;
        if (c(x)) res = min(res,x);
    }
    cout << (res == 99999999999 ? -1 : res);
}
