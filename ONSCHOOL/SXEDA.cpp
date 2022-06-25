#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const char alphabet[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int find(char c)
{
	int i;
	for (i = 0; i < 26; i++)
	if (*(alphabet + i) == c)
	return i;
} 

char encrypt(char c, int offset)
{
	int ind = find(c);
	ind = (ind + offset) % 26;
	return *(alphabet + ind);
}

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		cout << encrypt(s[i], n);
	}
}