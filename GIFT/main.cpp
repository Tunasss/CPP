#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//( ͡° ͜ʖ ͡°)
//Tunass

int main ()
{
    ll a[10000005];
    vector <ll> kq;
    int t,x,y,u,v;
    ll tong1=0,tong2=0;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        t = 0; x = 0 ; y = 0; u = 0; v = 0;
        cin >> x >> y >> u >> v >> t;
        tong1 = x * u;
        tong2 = y * v;
        ll temp = max(x , y);
        if (temp - x > t && temp - x > 0)
            {
                tong1 += (x * v) + (x * t);
                kq.push_back(tong1);
            }
        else if (temp - y > t && temp - y > 0)
            {
                tong2 += (y * u) + (y * t);
                kq.push_back(tong2);
            }
        else kq.push_back(tong1 + tong2);
    }
    for (int i = 0; i < kq.size() - 1; i++){
        cout << kq[i] << endl;
    }
}
