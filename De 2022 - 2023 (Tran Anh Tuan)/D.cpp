#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; i++){
        cin >> a[i];
    }
    stack<ll> s;
    ll res = 0;
    ll i = 0;
    while(i < n){
        if (s.empty() || a[s.top()] <= a[i]){
            s.push(i++);
        }
        else{
            ll t = s.top();
            s.pop();
            if (s.empty()) res = max(res, a[t] * i);
            else res = max(res, a[t] * (i - s.top() - 1));
        }
    }
    while(!s.empty()){
        ll t = s.top();
        s.pop();
        if (s.empty()) res = max(res, a[t] * i);
        else res = max(res, a[t] * (i - s.top() - 1));
    }
    cout << res;
}
