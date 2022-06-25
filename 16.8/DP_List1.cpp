#include <bits/stdc++.h>
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

#define fto(i,x,y) for(ll i = x; i <= y; i++)
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;

#define debug(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define debug_end(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;


/// Fibonaci bang QHD
/*
int ketqua[SIZE];

int fibonaci(int n){
	int fibo[SIZE];

	fibo[0] = 1;
	fibo[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}

	return fibo[n];

}	


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen(file".INP","r",stdin);
	//freopen(file".OUT","w",stdout);
	int n;
	cin >> n;
	cout << fibonaci(n);

	cout << '\n';
	cerr << "Time: " << clock() / double(CLOCKS_PER_SEC) << " sec.\n";
}
*/

///Duong di co tong lon nhat QHD
/*
int n;
int mang[1005][1005];

int maxPathSum(int r, int c){
	if (r == n - 1 && c == n - 1)
		return mang[r][c];

	if (r > n - 1 || c > n - 1)
		return 0;

	int path1 = maxPathSum(r, c + 1);
	int path2 = maxPathSum(r + 1, c);

	return mang[r][c] + max(path1, path2);
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen(file".INP","r",stdin);
	//freopen(file".OUT","w",stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> mang[i][j];

	cout << maxPathSum(0,0);

	cout << '\n';
	cerr << "Time: " << clock() / double(CLOCKS_PER_SEC) << " sec.\n";
}
*/

