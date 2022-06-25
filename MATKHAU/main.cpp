#include <bits/stdc++.h>
using namespace std;
bool check (int n)
{
    if (n<2) return false;
    for (int i=2;i<sqrt(n);i++)
    {
        if (n%i==0)
        return false;
    }
    return true;
}
string s;
int solve (string s)
{
    int res=INT_MIN;
    for (int i=0;i<s.size();i++)
    {
        int n=0;
        int j=i;
        while (s[j]>='0'&&s[j]<='9'){
            n=n*10+(s[j]-'0');
            j++;
            if (check(n)) res=max(n,res);
        }
    }
    return res;
}
int main()
{
//    freopen("MATKHAU.INP","r",stdin);
//    freopen("MATKHAU.OUT","w",stdout);
    cin>>s;
    cout<<solve(s);
}
