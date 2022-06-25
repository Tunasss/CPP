#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef string str;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("MATHIEU.INP","r",stdin);
    // freopen("MATHIEU.OUT","w",stdout);
    str s;
    cin >> s;

    ll m;
    cin >> m;
    ll sz = s.size();
    ll a[sz] = {0};

    for (ll i = 1; i <= m; i++){
        ll t;
        cin >> t;
        if (t > sz){
            a[sz - t - 1]--;
        }
        else a[t - 1]++;    
    }

    ll mid = (s.size() - 1) / 2 - 1;
    if (sz % 2 == 0) mid++;
    for (ll i = 1; i <= mid; i++){
        a[i] += a[i - 1];
    }
    for (ll i = 0; i <= mid; i++){
        if (a[i] % 2 != 0){
            swap(s[i], s[sz - i - 1]);
        }
    }  
    cout << s << endl;
}