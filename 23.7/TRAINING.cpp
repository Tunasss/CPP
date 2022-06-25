#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
//( ͡° ͜ʖ ͡°)
//Tunass

typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;

#define file "TRAINING"
#define st first
#define nd second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define bin binary_search

#define fto(i,x,y) for(ll i = x; i <= y; i++)
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;


ll gcd(ll a, ll b){
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b){
	return a / gcd(a, b) * b;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen(file".INP","r",stdin);
	freopen(file".OUT","w",stdout);
	
	ll b[SIZE], c[SIZE];
    vector <ii> a;
    ll n,m,temp,i,j;
    ll sum;
    cin >> n >>m;
    
    for(ll i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(make_pair(temp,i));
    }
    
    for(ll j = 0; j < m; j++)
       cin >> b[j];
    
    sort(a.begin(),a.end());
    sort(b,b + m);
    sum = a[0].first;
    b[m] = LLONG_MAX;
    i = 0,j = 0;
    while(i < n)
    {
        if(sum < b[j])
        {
            c[a[i].second] = sum;
            i++;
            sum += (a[i].first-a[i-1].first);
            continue;
        }
        sum += b[j];
        j++;
    }
    for(ll i = 0; i < n; i++)
    {
        cout << c[i] <<" ";
    }
    return 0;
}