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

#define debug(...) cerr << " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int size = 1;
vector<pair<ll,int>> seg;

void init(int n)
{
    while (size < n) size *= 2;
    seg.assign(2 * size, {LONG_LONG_MAX,1});
}

void setV(int i, ll value, int x, int lx, int rx)
{
    if (rx - lx == 1)
    {
        seg[x] = {value,1};
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
    int node1 = 2 * x + 1;
    int node2 = 2 * x + 2;
    ll v1 = seg[node1].first;
    ll v2 = seg[node2].first;
    if (v1 < v2) seg[x] = {v1,seg[node1].second};
    else if (v1 > v2) seg[x] = {v2,seg[node2].second};
    else seg[x] = {v1, seg[node1].second + seg[node2].second};
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
            seg[x] = {arr[lx],1};
        }
        return;
    }
    int mid = (lx + rx)/2;
    build(arr,2 * x + 1, lx, mid);
    build(arr,2 * x + 2, mid, rx);
    int node1 = 2 * x + 1;
    int node2 = 2 * x + 2;
    ll v1 = seg[node1].first;
    ll v2 = seg[node2].first;
    if (v1 < v2) seg[x] = {v1,seg[node1].second};
    else if (v1 > v2) seg[x] = {v2,seg[node2].second};
    else seg[x] = {v1, seg[node1].second + seg[node2].second};
}

void build(vector<ll> &arr)
{
    build(arr, 0, 0, size);
}

pair<ll,int> fmin(int l, int r, int x, int lx, int rx)
{
    if (r <= lx || rx <= l) return {LONG_LONG_MAX,0};
    if (l <= lx && rx <= r) return seg[x];
    int mid = (rx + lx) /  2;
    pair<ll,int> s1 = fmin(l, r, 2 * x + 1, lx, mid);
    pair<ll,int> s2 = fmin(l, r, 2 * x + 2, mid, rx);
    if (s1.first < s2.first) return s1;
    else if (s1.first > s2.first) return s2;
    else return {s1.first,s1.second+s2.second};
    
}

pair<ll,int> fmin(int l, int r)
{
    return fmin(l, r, 0, 0, size);
}


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen(file".INP","r",stdin);
	//freopen(file".OUT","w",stdout);
	
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
            pair<ll,int> kq = fmin(l,r);
            cout << kq.st << " " << kq.nd << endl;
        }
    }

	cout << '\n';
	cerr << "Time: " << clock() / double(CLOCKS_PER_SEC) << " sec.\n";
}
