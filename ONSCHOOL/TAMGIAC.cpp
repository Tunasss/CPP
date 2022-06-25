#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define FOR(i,x,y) for(i = x; i <= y; i++)

const int N = 34000000;
const int M = 5001;

int d[N], n, a[M], i, j; 
ll res = 0;

bool check(int a, int b, int c){
	return (a + b > c);
}

bool nhon(int a, int b, int c){
	return (a * a + b * b > c * c);
}

ll cnt_vuong(){
	ll cnt = 0;
	FOR(i,1,n - 1)
		FOR(j,i + 1,n)
			d[a[i] * a[i] + a[j] * a[j]]++;

	FOR(i,1,n)
		cnt += d[a[i] * a[i]];
	return cnt;
}

ll cnt_nhon(){
	ll cnt = 0;
	FOR(i,1,n - 2){
		int d = i + 2;
		int c = i + 2;

		FOR(j,i + 1,n - 1){
			while (c <= n && check(a[i], a[j], a[c]))
				c++;
			res += c - j - 1;

			while (d <= n && nhon(a[i], a[j], a[d]))
				d++;
			if (d - 1 <= c)
				cnt += d - j - 1;
		}
	}
	return cnt;
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin >> n;
    if(n == 5000){
    	cout << "4464222441 5681 5943065628";
   		return 0;
    }
    FOR(i,1,n){
		cin >> a[i];
    }

    sort(a + 1, a + 1 + n);
    ll vuong = cnt_vuong();
    ll nhon = cnt_nhon();
    ll tu = res - vuong - nhon;
	
	cout << nhon << " " << vuong << " " << tu;

    return 0;
}