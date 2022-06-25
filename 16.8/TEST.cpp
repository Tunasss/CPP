#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
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


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen(file".INP","r",stdin);
	//freopen(file".OUT","w",stdout);

    ll n,m;
    cin >> n >> m;
    vector <ll> a(n,0), b(m,0);

    int dem = 0, dem2 = 0, contro = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
        if (b[i] != a[contro - 1])
        {
            dem2 = 0;
            while (contro < n && b[i] > a[contro]) contro++;
        }
        while (contro < n && b[i] == a[contro])
        {
            contro++;
            dem2++;
        }
        dem += dem2;
    }
    cout << gcd(dem,2);
    cerr << "\nTime: " << clock() / double(CLOCKS_PER_SEC) << " sec.\n";
    return 0;
}

