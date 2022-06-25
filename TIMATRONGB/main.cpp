#include <bits/stdc++.h>
//( ͡° ͜ʖ ͡°)
//Tunass
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<long long> a(n), b(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	long long t = 0;
	for(int i = 0; i < n; i++)
		cin >> b[i];
	for(int i = 0; i < n; i++)
		if(binary_search(b.begin(), b.end(), a[i]))
			t++;
	cout << t; 
	return 0;
}