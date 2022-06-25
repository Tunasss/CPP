#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("CPLOAI.INP","r",stdin);
    freopen("CPLOAI.OUT","w",stdout);
    ll n;
    cin >> n;
    set <ll> a;
    for (ll i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        a.insert(temp);
    }
    cout << a.size() << "\n";
    set <ll> ::iterator itr;
    for (itr = a.begin(); itr != a.end(); itr++)
    {
        cout << *itr << " ";
    }
}