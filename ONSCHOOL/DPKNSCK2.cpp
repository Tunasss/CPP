#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;
    long long a[n + 1], b[n + 1];
    for(long long i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    vector<vector<long long> > s(n + 1, vector<long long>(m + 1, 0));
    for(long long i = 1; i <= n; i++)
        for(long long j = 1; j <= m; j++)
        if(b[i] <= j)
            s[i][j] = max(s[i - 1][j], s[i - 1][j - b[i]] + a[i]);
        else s[i][j] = s[i - 1][j];
    stack<long long> t;
    while(n > 0)
    {
        if(s[n][m] != s[n - 1][m])
        {
            t.push(n);
            m -= b[n];
        }
        n--;
    }
    cout << t.size() << endl;
    while(!t.empty())
    {
        cout << t.top() << ' ';
        t.pop();
    }
    return 0;
}
    