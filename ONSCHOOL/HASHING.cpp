#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll A = 9973, B = 1e9 + 1, N = 1111111;
ll p[N], h[N];
string a, b;

ll Hash(int x,int y) {
    if(x == 0) return h[y];
    return (h[y] - h[x - 1] * p[y - x + 1] + B * B) % B;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> a >> b;
    h[0] = a[0];
    p[0] = 1;
    for (int i = 1; i < a.size(); i++){
        p[i] = (p[i - 1] * A) % B;
        h[i] = (h[i - 1] * A + a[i]) % B;
    }
    ll hash_value = b[0];

    for(int i = 1; i < b.size(); i++)
        hash_value = (hash_value  * A + b[i]) % B;
    for(int i = 0; i < a.size() - b.size() + 1; i++)
        if(hash_value == Hash(i, i + b.size() - 1)) 
            cout << i + 1 << ' ';
}
