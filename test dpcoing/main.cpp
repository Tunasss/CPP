#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//( ͡° ͜ʖ ͡°)
//Tunass

ll n, k, m, l;
ll a[100000];

int main ()
{
    cin >> k >> l >> m;
    for (ll i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    for (ll i = 1; i <= m; i++)
    {
        int ck=0;
        int temp = a[i];
        if (temp % k == 0)
        {
            if ((temp / k) % 2 != 0)
            {
                cout<<"A";
                ck=1;
            }
        }
        if (temp % l == 0)
        {
            if ((temp / l) % 2 != 0)
            {
                cout<<"A";
                ck=1;
            }
        }
        if (temp % k != 0)
        {
            if ((temp / k) % 2 == 0)
            {
                cout<<"A";
                ck=1;
            }
        }
        if (temp % l != 0)
        {
            if ((temp / l) % 2 == 0)
            {
                cout<<"A";
                ck=1;
            }
        }
        if (temp % 2 != 0)
        {
            cout << "A";
            ck=1;
        }
        else cout<<"B";
    }
    return 0;
}
