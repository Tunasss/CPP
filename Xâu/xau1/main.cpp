#include <iostream>
using namespace std;
int main()
{
    int dem=0;
    string s;
    cin>>s;
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]-48<=9)
            dem++;
    }
    cout<<dem;
}
