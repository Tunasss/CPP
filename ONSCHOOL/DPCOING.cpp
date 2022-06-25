#include<bits/stdc++.h>
using namespace std;

bool f[1800001];
int l, k, m;

int main(){
    cin >> m >> k >> l;
    for (int i = 1; i <= 1000000; i++){
        if (!f[i-1] || (i >= k && !f[i-k]) || (i >= l && !f[i-l])) f[i] = true;
    }
    for (int i = 0; i < m; i++){
        int t;
        cin >> t;
        if (f[t]) cout << 'A'; 
        else cout << 'B';
    }
}