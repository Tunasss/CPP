#include <bits/stdc++.h>
using namespace std;
//( ͡° ͜ʖ ͡°)
//Tunass
 
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;
 
#define file "TEST"
// #define st first
// #define nd second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define bin binary_search
 
#define fto(i,x,y) for(ll i = x; i <= y; i++)
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;
 
str s;
 
int PaliLength(int L, int R, string s)
{
    int len = 0;
    while (L >= 0 && R < s.size())
    {
        if(s[L] == s[R])
        {
            len = R - L + 1;
            L--;
            R++;
        }
        else break;
    }
    return len;
}
 
// string longestPalindrome(string s) {
//     int start = 0; int end = 0;
//     if (s.size() == 0)
//         return "";
//     else
//     {
//         for (int center = 0; center < s.size(); center++)
//         {
//             int len1 = PaliLength(center, center, s);
//             int len2 = PaliLength(center, center + 1, s);
 
//             if (len1 > end - start)
//             {
//             	start = center - len1 / 2;
//         	    end = center + len1 / 2;
//             }
 
//             if (len2 > end - start)
//             {
//                 start = center + 1 - len2 / 2;
//                 end = center + len2 / 2;
//             }
//         }
//     }
//     return s.substr(start, end - start + 1);
// }
 
int longestPalindrome_int(string s) {
    int start = 0; int end = 0;
    if (s.size() == 0)
        return 0;
    else
    {
        for (int center = 0; center < s.size(); center++)
        {
            int len1 = PaliLength(center, center, s);
            int len2 = PaliLength(center, center + 1, s);
 
            if (len1 > end - start)
            {
            	start = center - len1 / 2;
        	    end = center + len1 / 2;
            }
 
            if (len2 > end - start)
            {
                start = center + 1 - len2 / 2;
                end = center + len2 / 2;
            }
        }
    }
    return end - start + 1;
}
 
 
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen(file".INP","r",stdin);
	//freopen(file".OUT","w",stdout);
	int n;
	cin >> n;
	cin >> s;
 
	// cout << "\n";
	// cout << longestPalindrome(s) << '\n';
	cout << longestPalindrome_int(s);
 
	// cout << '\n';
	// cerr << "Time: " << clock() / double(CLOCKS_PER_SEC) << " sec.\n";
}
 