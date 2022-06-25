#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".INP","r",stdin);
    //freopen(file".OUT","w",stdout);
    ll status = rand(0,1);
    str msg = (!status) ? "you are the loser" : "you are the winner";
    cout << msg;
}