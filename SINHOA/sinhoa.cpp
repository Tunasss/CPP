#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//( ͡° ͜ʖ ͡°)
//Tunass
int main ()
{
    string s;
    getline(cin,s);
    char c;
    for (int i=0;i<s.size();i++)
    {
        c=s[i];
        if (islower(c))
        c=toupper(c);
        s[i]=c;
    }
    cout<<s;
}
    