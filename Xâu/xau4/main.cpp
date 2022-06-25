#include <iostream>
using namespace std;
int main()
{
    string s,p;
    cin>>s;
    int j=0;
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]!=s[i+1])
        {
            p[j++]=s[i];
        }
    }
    for (int i=0; i<j; i++)
    {
        cout<<p[i];
    }
}
