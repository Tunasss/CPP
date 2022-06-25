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

const int N = 5001;
string s, d[N];

string sum(string a, string b) {
	while (a.size() < b.size())
		a = '0' + a;
	while (b.size() < a.size())
		b = '0' + b;
	int tmp = 0;
	string res = "";
	for (int i = a.size() - 1; i >= 0; --i) {
		int t = a[i] - '0' + b[i] - '0' + tmp;
		tmp = t / 10;
		t %= 10;
		char c = t + '0';
		res = c + res;
	}
	if (tmp > 0)
		res = '1' + res;
	return res;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	while (cin >> s) {
		if (s == "0")
			break;
		int n = s.size();
		d[n] = '1';
		d[n - 1] = (s[n - 1] == '0')? '0' : '1';
		for (int i = n - 2; i >= 0; --i) {
			int t1 = s[i] - '0', t2 = s[i + 1] - '0';
			if (t1 == 0)
				d[i] = '0';
			else if (t1 * 10 + t2 <= 26)
				d[i] = sum(d[i + 1], d[i + 2]);
			else 
				d[i] = d[i + 1]; 
		}
		cout << d[0] << '\n';
	}
	return 0;
}