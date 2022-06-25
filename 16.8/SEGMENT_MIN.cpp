#include <bits/stdc++.h>
using namespace std;
//( ͡° ͜ʖ ͡°)
//Tunass

typedef long long ll;

#define debug(...) cerr << " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int size = 1;
vector<ll> seg;

int MAXX = 999999999;

void init(int n)
{
    while (size < n) size *= 2;
    seg.assign(2 * size, 0);
}

void setV(int i, ll value, int x, int lx, int rx)
{
    if (rx - lx == 1)
    {
        seg[x] = value;
        return;
    }
    int mid = (rx + lx)/2;
    if (i < mid)
    {
        setV(i, value, 2 * x + 1, lx, mid);
    }
    else
    {
        setV(i, value, 2 * x + 2, mid, rx);
    }

    //HUY: tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    seg[x] = min(seg[2 * x + 1], seg[2 * x + 2]);
}


void setV(int i, ll value)
{
    setV(i, value, 0, 0, size);
}

void build(vector<ll> &arr, int x, int lx, int rx)
{
    if (rx - lx == 1){
        if (lx < arr.size())
        {
            seg[x] = arr[lx];
        }
        return;
    }
    int mid = (lx + rx)/2;
    build(arr,2 * x + 1, lx, mid);
    build(arr,2 * x + 2, mid, rx);
    seg[x] = min(seg[2 * x + 1],seg[2 * x + 2]);

    //HUY: tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
}

void build(vector<ll> &arr)
{
    build(arr, 0, 0, size);
}

ll process(int l, int r, int x, int lx, int rx)
{
    if (r <= lx || rx <= l) return MAXX;
    if (l <= lx && rx <= r) return seg[x];
    int mid = (rx + lx) /  2;

    return min(

    process(l, r, 2 * x + 1, lx, mid),
    process(l, r, 2 * x + 2, mid, rx)

    );

	// HUY
	// ll s1 = sum(l, r, 2 * node + 1, l_bor, mid);
	// ll s2 = sum(l, r, 2 * node + 2, mid, r_bor);
	// return s1 + s2;	
}

ll process(int l, int r)
{
    return process(l,r,0,0,size);
}

int main() {
    int n, m;
    cin >> n >> m;
    init(n);
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    build(arr);
    while (m--)
    {
        int opp;
        cin >> opp;
        if (opp == 1)
        {
            int i, v;
            cin >> i >> v;
            setV(i,v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << process(l,r) << endl;
        }
    }
}