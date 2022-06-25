#include <bits/stdc++.h>
 
using namespace std;
 
const int Sz = 1e6 + 5;
 
int a[Sz];
int n;
 
signed main()
{
 
	cin >> n;
 
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	n = unique(a, a + 1 + n) - a - 1;
	a[0] = 1;
 
	int res = 0;
 
	for(int i = 1; i <= n; i++)
	{
		for(int M = 1; M * a[i] < Sz; M++)
		{
			int k = lower_bound(a + 1, a + 1 + n, a[i] * M + a[i]) - a;
			k--;
			res = max(res, a[k] % a[i]);
		} 
	}
	cout << res << "\n";
	return 0;
}