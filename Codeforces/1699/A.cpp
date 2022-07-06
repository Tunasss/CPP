/*
    Hay lam Da Lat vi dai tro lai!!!
                                (  )
    xin than Rua phu ho do tri /_||_\
*/
 
#include <bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define rerep(i,b,a) for (int i = b; i >= a; i--)
#define vii vector<int,int>
#define pii pair<int,int>
#define _pb push_back
 
using namespace std;
 
const int INF = 1e9;
const int Sz = 1e6;
const int Min_Sz = 1e3;
 
void than_chu()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
 
int dp(int n, string s)
{
    s = '0' + s;
    int numA[n+1] = {0}, numB[n+1] = {0}, numC[n+1] = {0};
    
    rep(i,1,n)
    {
        numA[i] = numA[i-1];
        numB[i] = numB[i-1];
        numC[i] = numC[i-1];
 
        if (s[i] == 'a') numA[i]++;
        else 
 
        if (s[i] == 'b') numB[i]++;
        else 
 
        if (s[i] == 'c') numC[i]++;
    }
 
    if (n <= Min_Sz)
    {
        int res = INF;
        rep(i,1,n-1)
        {
            rep(j,i+1,n)
            {
                int vA = numA[j] - numA[i-1];
                int vB = numB[j] - numB[i-1];
                int vC = numC[j] - numC[i-1];
                if (vA > vB && vA > vC) res = min(res,j - i + 1);
            }
        }
        if (res > n || res == 0) return -1;
        return res;
    } else {
        int res = INF;
        rep(i,1,n-1) {
            int temp;
            if (i + 6 > n) temp = n - i + 1; else temp = i + 6;
            for (int j = i + 1; j <= temp; j++){
                int vA = numA[j] - numA[i-1];
                int vB = numB[j] - numB[i-1];
                int vC = numC[j] - numC[i-1];
                if (vA > vB && vA > vC) res = min(res,j - i + 1);
            }
        }
        if (res > n || res == 0) return -1; 
        return res;
    }
}
 
 
int main()
{
    than_chu();
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int n;
        cin >> n;
        cin >> s;
        cout << dp(n,s) << endl;
    }
    return 0;
}