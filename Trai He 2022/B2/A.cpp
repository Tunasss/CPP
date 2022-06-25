#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <double, double> ii;
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
#define el cout << endl;
#define all(v) (v).begin(), (v).end()
#define FOR(i,x,y) for(ll i = x; i <= y; i++)
#define FOS(i,x,y) for(ll i = x; i >= y; i--)
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

const ll N = 1001;
ii p[N];
ll n;

const double dx[] = {-1, 1, -1, 1};
const double dy[] = {-1, -1, 1, 1};

double calc (ii A, ii B){
	return sqrt((A.st - B.st) * (A.st - B.st) + (A.nd - B.nd) * (A.nd - B.nd));
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);

    cin >> n;
    double x = 0, y = 0;
    for (int i = 1; i <= n; i++){
    	cin >> p[i].st >> p[i].nd;
    	x += p[i].st;
        y += p[i].nd;
    }

    x /= n;
    y /= n;

    ii point = make_pair(x, y);
    double res = 0; 

    for (int i = 1; i <= n; i++){
 		res += calc(point, p[i]);
    }

    double test = 100000;
    bool check;
 
    while (test > 0.00001)
    {
        check = true;
 
        for (int i = 0; i < 4; i++)
        {
            ii newPoint = make_pair(point.st + test * dx[i], point.nd + test * dy[i]);
 
            double tmp = 0;
 
            for (int j = 1; j <= n; j++)
                tmp += calc(newPoint, p[j]);
 
            if (tmp < res)
            {
                res = tmp;
                point = newPoint;
                check = false;
                break;
            }
        }
 
        if (check) test /= 2;
    }

    cout << fixed << setprecision(6) << res;
    
    return 0;
}