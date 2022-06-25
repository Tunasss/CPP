#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
//( ͡° ͜ʖ ͡°)
//Tunass

typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;

#define file "TEST"
#define st first
#define nd second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define bin binary_search

#define all(v) (v).begin(), (v).end()
#define fto(i,x,y) for(ll i = x; i <= y; i++)
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;

#define debug(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "

#define debug_end(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;

const long long MAX = 10E6+1;

long long n;
long long F,L;
long long a[MAX];
long long s[MAX];
int pos[MAX];
void Input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}
void Process()
{
    s[0] = 0;
    for (int i = 1; i <= n; i++)
        s[i] = s[i-1] + a[i];
    long long Min = MAX;
    int prepos;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] < Min)
        {
            Min = s[i];
            prepos = i;
        } 
        pos[i] = prepos;
    }
    long long L = 0, R = 0, ma = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] <= 0)
        {
            long long pre = i;
            long long sum = 0;
            while (sum + s[pre] - s[pos[pre-1]] > 0)
            {
                sum += s[pre] - s[pos[pre-1]];
                pre = pos[pre-1];
            }
            if (i - pre >= ma)
            {
                ma = i - pre;
                L = pre+1;
                R = i;
            }
        }
        else if (i > ma)
        {
            ma = i;
            L = 1;
            R = i;
        }
        debug(L); debug(R); debug_end(ma);
    }
    cout << L << " " << R;
}

int main()
{
    Input();
    Process();
}
