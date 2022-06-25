#include <bits/stdc++.h>
using namespace std;
//( ͡° ͜ʖ ͡°)
//Tunass

typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;

#define file "TEST"
#define st first
#define nd second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define bin binary_search

#define fto(i,x,y) for(ll i = x; i <= y; i++)
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;

bool isPalindrome(string s, int l, int r)
{
    while (r > l)
    {
        if (s[l++] != s[r--])
        {
            return false;
            break;
        }
        else continue;
    }
    return true;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen(file".INP","r",stdin);
	//freopen(file".OUT","w",stdout);
	str s;
	cin >> s;

	ll count = s.length();

	for (ll i = 0; i < s.length(); i++){
		for (ll j = i + 1; j < s.length(); j++){
			if (isPalindrome(s,i,j))
			{
				count++;
				cout << i + 1 << " " << j + 1 << endl;
			}
		}
	}

	cout << count;

	// cout << '\n';
	// cerr << "Time: " << clock() / double(CLOCKS_PER_SEC) << " sec.\n";
}

