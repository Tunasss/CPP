#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s,p;
    int dem=0;
    int k=0;
    cin>>s;
    char a[s.size()+1];
    for (int i=0; i<s.size(); i++)
        a[i]=s[i];
    sort(a,a+s.size());
    for (int i=0; i<s.size(); i++)
    {
        if (i==0)
        {
            cout<<a[i];
            dem++;
        }
        else
        if (a[i]==a[i+1])
            dem++;
        else
        {
            cout<<dem<<endl;
            cout<<a[i]<<" ";
            dem=1;
        }
    }
    cout<<dem;
}
