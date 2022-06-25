#include <bits/stdc++.h>

using namespace std;
string t = "01";
unsigned long long n;
void quaylui(string s)
{
    if(s.size() == n)
    {
        cout << s;
        cout << endl;
        return;
    }
    for(int i = 0; i < t.size(); i++)
        quaylui(s + t[i]);
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    quaylui("");
    return 0;
}
    