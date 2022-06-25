#include <iostream>
using namespace std;
int main()
{
    int dem=0;
    string s;
    int k;
    cin>>s>>k;
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]==s[i+1])
            dem++;
    }
    if (k==dem) cout<<"YES";
    else cout<<"NO";
    return 0;
}
