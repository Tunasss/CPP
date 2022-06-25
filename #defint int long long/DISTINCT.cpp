#include <bits/stdc++.h>
using namespace std;
int main(){

   int ans = 3;
   string s; 
   cin >> s;
   if (s[0] != s[1] && s[1] != s[2] && s[2] != s[0]) ans = 6;
   else if (s[0] == s[1] && s[1] == s[2]) ans=1;
   cout << ans;
}