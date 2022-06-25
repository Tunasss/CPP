#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
const ull maxx = 1000000;
#define fto(i,x,y) for(int i=x;i<y;i++)
//( ͡° ͜ʖ ͡°)
//Tunass
using namespace std;

ull temp = 1e9 + 7;

ull mu(ull x, ull n)
{
    if(n == 1)
        return x % temp;
    else
    {
        ull t = mu(x , n / 2) ;
        if(n % 2 == 0)
            return t * t ;
        else
            return x * t * t ;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ull x, n;
    cin >> x >> n;
    ull kq = mu(x , n);
    cout << kq ;
    return 0;
}
