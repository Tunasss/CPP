//Tran Anh Tuan - 10 Tin - CTL
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef string str;
#define file "CUTSTR"
const ll MOD = 1e9 + 7;

str b, a;
ll dem = 0;
unordered_map <string, bool> check;

ll power(ll a, ll b){
    if (b == 1) return a;
    if (b == 0) return 1;
    ll ans = power(a, b / 2);
    if (b & 1) return ans * ans % MOD * a % MOD;
    return ans * ans % MOD;
}

bool kmp(str a){
    if (check[a]) return true;

    ll n = a.size();
    ll s[n + 1] = {0}, j = 0;
    for(ll i = 1; i < n; i++)
        if(a[j] == a[i]) s[i] = s[i - 1] + 1, j++;
        else if(j > 0)
        {
            j = s[j - 1];
            while(a[j] != a[i] && j > 0) j = s[j - 1];
            if(a[j] == a[i]) s[i] = s[j] + 1, j++;
        }
    j = 0;
    for(ll i = 0; i < b.size(); i++)
    {
        if(a[j] == b[i]) j++;
        else if(j > 0) if(a[s[j - 1]] == b[i]) j = s[j - 1] + 1;
        else j = 0;
        if(j == n)
        {   
            check[a] = true;
            return true;
            j = s[j - 1];
        }
    }
    return false;
}

void quaylui(ll x)
{
    if(x == a.size()){
        dem++;
        return;
    }
    str s = "";
    for(ll i = x; i < a.size(); i++){
        s += a[i];
        if(kmp(s)) quaylui(i + 1);
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".INP","r",stdin);
    freopen(file".OUT","w",stdout);

    cin >> a >> b;
    if(kmp(a))
    {
        dem = power(2, b.size() - 1);
        cout << dem % MOD;
        return 0;
    }

    for(ll i = 0; i < b.size(); i++) {
        check[b[i] + ""] = 1;
    }
    for(ll i = 0; i < a.size(); i++){
        if(!check[a[i] + ""]){
            cout << 0;
            return 0;
        }
    }

    quaylui(0);
    cout << dem;
    
    return 0;
}