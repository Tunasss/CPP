#include <bits/stdc++.h>
using namespace std;
//Tunass
 
typedef long long ll;

int size = 1;
vector<ll> tree;


void init (int n) {
	while (size < n) size *= 2;
	tree.assign(2 * size, 0);
}

void setV (int i, ll v, int node, int l_bor, int r_bor) {
	if (r_bor - l_bor == 1) {
		tree[node] = v;
		return;
	}

	int mid = (r_bor + l_bor) / 2;
	if (i < mid) {
		setV(i, v, 2 * node + 1, l_bor, mid);
	}
	else {
		setV(i, v, 2 * node + 2, mid, r_bor);
	}

	tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}


void setV (int i, ll v) {
	return setV(i,v,0,0,size);
}

ll sum (int l, int r, int node, int l_bor, int r_bor) {
	if (l_bor >= r || l >= r) return 0;
	if (l_bor >= l && r_bor <= r) return tree[node];

	int mid = (r_bor + l_bor) / 2;
	ll s1 = sum(l, r, 2 * node + 1, l_bor, mid);
	ll s2 = sum(l, r, 2 * node + 2, mid, r_bor);
	return s1 + s2;		
}


ll sum (int l, int r) {
	return sum(l,r,0,0,size);
}

void build(vector<ll> &arr, int node, int l_bor, int r_bor)
{
    if (r_bor - l_bor == 1){
        if (l_bor < arr.size())
        {
            tree[node] = arr[l_bor];
        }
        return;
    }
    int mid = (l_bor + r_bor)/2;
    build(arr,2 * node + 1, l_bor, mid);
    build(arr,2 * node + 2, mid, r_bor);
    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}

void build(vector<ll> &arr)
{
    build(arr, 0, 0, size);
} 
 
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen(file".INP","r",stdin);
	//freopen(file".OUT","w",stdout);
	int m,n;
	cin >> n >> m;
 	
 	vector <ll> arr(n);
	init(n);
 
	for (ll i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	build(arr);

	while (m--)
	{
		int temp = 0;
		cin >> temp;
 
		//SUM
		if (temp == 2) {
			int l,r;
			cin >> l >> r;
			cout << sum(l,r) << "\n";
		}
 
		//SET
		if (temp == 1) {
			int i,v;
			cin >> i >> v;
			setV(i,v);
		}
 
	}
 
	cout << '\n';
	cerr << "Time: " << clock() / double(CLOCKS_PER_SEC) << " sec.\n";
}