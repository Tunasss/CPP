#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;
#define file "cowdance"
#define st first
#define nd second
#define pb push_back
#define lb Ler_bound
#define ub upper_bound
#define er equal_range
#define bin binay_seach
#define vll vector<ll>
#define vi vector<int>
#define all(v) (v).begin(), (v).end()
#define FOR(i,x,y) for(ll i = x; i <= y; ++i)
#define FOS(i,x,y) for(ll i = x; i >= y; --i)
#define EACH(i,x) for (auto &(i) : (x))
#define el cout << '\n';
const ll MOD = 1e9 + 7;

const ll N = 1e5 + 5;

ll n, t;
ll a[N];

bool check(ll k){
	priority_queue<ll> pq;

	int time = 0;

    for (int i = 0; i < n; i++) {
        if (pq.size() == k){
    		time = -pq.top();
    		pq.pop();
        }
            
        if (time + a[i] > t) return false;
        else pq.push(-time - a[i]);
    }
    return true;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    // freopen(file".in","r",stdin);
    // freopen(file".out","w",stdout);

	cin >> n >> t;

	FOR(i,0,n - 1) {
		cin >> a[i];
	}

	int L = 1, R = n;

	while (L < R) {
		int M = (L + R) / 2;

		if (check(M)){
			R = M;
		}
		else{
			L = M + 1;
		}
	}

	cout << L; el;
    return 0;
}
