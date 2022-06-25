#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> s(n + 1, 1), vt(n + 1);
    int mx = 1, vitri = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j < i; j++)
            if(a[j] < a[i] && s[i] < s[j] + 1)
                s[i] = s[j] + 1, vt[i] = j;
        if(mx < s[i])
            mx = s[i], vitri = i;
    }
    vector<int> ans;
    cout << mx << endl;
    while(vitri > 0)
    {
        ans.push_back(vitri);
        vitri = vt[vitri];
    }
    for(int i = mx - 1; i >= 0; i--)
        cout << ans[i] << ' ';
    return 0;
}