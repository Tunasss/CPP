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


ll cmp (ii x, ii y)
{
    if (x.nd == y.nd)
        return x.st > y.st;
    return x.nd > y.nd;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    int n;
    cin >> n;
    vector <ii> a(105);
    for (ll i = 0; i < n; i++){
        cin >> a[i].st >> a[i].nd;
    }

    sort(a.begin(), a.end(), cmp);

    // for (ll i = 0; i < n; i++){
    //  cout << a[i].st << " " << a[i].nd << "\n";
    // }

    ll currrent = 1;
    ll sum = 0;
    ll i = 0;
    while(currrent != 0)
    {
        currrent += a[i].nd;
        sum += a[i].st;
        currrent--;
        i++;
    }
    cout << sum;

    // cerr << "\nTime: " << clock() / double(CLOCKS_PER_SEC) << " sec.\n";
    return 0;
}
    