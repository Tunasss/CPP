#include <bits/stdc++.h>
#include <string>
typedef long long ll;
typedef unsigned long long ull;
const ull maxx = 1000000;
//( ͡° ͜ʖ ͡°)
//Tunass`
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,k;
    cin >> n >> k;
    string s;

    for (ll i = '1'; i <= n + '0'; ++i)
    {
        s += i;
    }

    ll dem = 0;
    ll point = 1;
    while (s.size() > 1)
    {
        dem++;
        point++;
//        if (dem > s.size())
//        {
//            dem = 0;
//        }
        if (point == k)
        {
            if (dem > s.size())
            {
            s.erase(s.begin() + (dem % (s.size())));
            cout << s << '\n';
            point = 0;
            }
            else if (dem < s.size())
            {
            s.erase(s.begin() + (dem % (s.size())));
            cout << s << '\n';
            point = 1;
            }
        }
    }
}
