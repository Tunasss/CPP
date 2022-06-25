#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
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
#define vll vector<ll>
#define vi vector<int>
#define all(v) (v).begin(), (v).end()
#define FOR(i,x,y) for(ll i = x; i <= y; i++)
#define FOS(i,x,y) for(ll i = x; i >= y; i--)
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

ll n, res = 0;
str s;
ll d[100][100];
char x = 'Z', y = 'Z';

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n;
    cin >> s;

    FOR(i,0,s.size() - 2){
    	d[s[i] - '0'][s[i + 1] - '0']++;
    }
    FOR(i,0,s.size() - 2){
    	if (d[s[i] - '0'][s[i + 1] - '0'] > res){
    		res = d[s[i] - '0'][s[i + 1] - '0'];
    		x = s[i];
    		y = s[i + 1];
    	}
    	else if (d[s[i] - '0'][s[i + 1] - '0'] == res){
    		if (s[i] < x) {
    			res = d[s[i] - '0'][s[i + 1] - '0'];
	    		x = s[i];
	    		y = s[i + 1];
    		}
    		else if (s[i] < x){
    			if (s[i] + 1 < y){
    				res = d[s[i] - '0'][s[i + 1] - '0'];
		    		x = s[i];
		    		y = s[i + 1];
    			}
    		}
    	}
    }
    cout << x << y;
    return 0;
}
