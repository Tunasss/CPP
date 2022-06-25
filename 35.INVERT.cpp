#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l -= 1;
        r -= 1;
        int dem = 0;
        for (int i = l; i < r; i++) {
            for (int j = i + 1; j <= r; j++) {
                if (a[i] > a[j]) {
                    dem++;
                }
            }
        }
        cout << dem << endl;
    }
    return 0;
}
    