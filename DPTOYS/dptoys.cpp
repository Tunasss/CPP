#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX=1000010;

ll n, price[MAX], money[MAX];    
int main()
{
	int T, test;
	cin >> T;
	for(test = 0; test < T; test++)
	{
        int N;
		cin >> N;
		for(int i = 1; i <= N; i++)
		{
			cin >> price[i];
			money[i] = 0;
		}
		money[N] = price[N];
		for(int i = N + 1; i <= N + 5; i++)
			price[i] = money[i] = 0;
		for(int i = N-1; i >= 1; i--)
		{
			money[i] = (long long)price[i] + money[i + 2];

			long long t = (long long)(price[i] + price[i + 1]) + money[i + 4];
			if(t > money[i])
			 money[i] = t;

			t = (long long)(price[i] + price[i + 1] + price[i + 2]) + money[i + 6];
			if(t > money[i])
			 money[i] = t;
		}
		cout << money[1] << endl;
	}
	return 0;
}
