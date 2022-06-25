#include <bits/stdc++.h>
using namespace std;
//Tunass

typedef long long ll;
typedef unsigned long long ull;

ull tich(ull n){
	ull temp = 1;
	while (n > 0)
	{
		temp *= n % 10;
		n /= 10;
	}
	return temp;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // ifstream fi("DOBEN.INP");
    // ofstream fo("DOBEN.OUT");

    ull n;
    ll dem = 0;
    string s;

    cin >> s;
    int temp = s.size() - 7;
    string s_temp = s.substr(6, temp);
    n = stoull(s_temp);
    while (n > 9){
    	dem++;
    	n = tich(n);
    }
    cout << dem;
    return 0;
}
