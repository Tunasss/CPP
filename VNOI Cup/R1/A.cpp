#include <bits/stdc++.h>
#define ll long long int
#define N 1000005
#define pb push_back
using namespace std;

const ll MOD = 1e9 + 7;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n), b(n), c;
    string s;

    for(int i = 0;i < a.size();i++)cin >> a[i];
    for(int i = 0;i < b.size();i++)cin >> b[i];

    int i = 0, j = 0;

    c.pb(a[i]);
    i++;
    s += "a";

    while(c.size() < n * 2){
        if(i >= a.size()){
            c.pb(b[j]);
            j++;
            s += "b";
        }
        else if(j >= b.size()){
            c.pb(a[i]);
            i++;
            s += "a";
        }
        else{
            if(a[i] == c[c.size() - 1]){
                c.pb(b[j]);
                j++;
                s += "b";
            }
            else{
                if(b[j] == c[c.size() - 1]){
                    c.pb(a[i]);
                    i++;
                    s += "a";
                }
                else{
                    if(j > i){
                        c.pb(a[i]);
                        i++;
                        wwwwwwwwwwwwwwwwwwwwd     s += "a";
                    }
                    else{
                        c.pb(b[j]);
                        j++;
                        s += "b";
                    }
                }
            }
        }
    }
    cout << s;

    return 0;
}