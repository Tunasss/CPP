#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    //freopen("maxsum.inp","r",stdin);
    //freopen("maxsum.out","w",stdout);
    ll n;
    cin >> n;
    vector <ll> s(n + 1), sum(n + 1, 0);
    for(ll i = 1; i <= n; i++){
        cin >> s[i];
        sum[i] = s[i] + sum[i - 1];
    }
    ll ans = INT_MIN;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++){
            ll temp = sum[i] - sum[j - 1];
            ans = max(ans, max(temp, sum[n] - temp));
        }
    cout << ans;
    return 0;
}
