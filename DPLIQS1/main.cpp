#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> s(n + 1, 1);
    int mx = 1;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
            if(a[j] < a[i] && s[i] < s[j] + 1)
                s[i] = s[j] + 1;
        mx = max(mx, s[i]);
    }
    cout << mx;
    return 0;
}