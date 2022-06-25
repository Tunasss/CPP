#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,a[10000], ok[105][105];
    cin>>n;
    for(int i=0;i < n*n;i++){
        a[i] = i + 1;
    }
    sort(a,a+(n*n));
    int dema=0,demb=n-1,dem=0;
    while(dema<=demb&&demb<n){
        for(int i=dema;i<=demb;i++){
            ok[dema][i]=a[dem];
            dem++;
        }
        for(int i=dema+1;i<=demb;i++){
            ok[i][demb]=a[dem];
            dem++;
        }
        for(int i=demb-1;i>=dema;i--){
            ok[demb][i]=a[dem];
            dem++;
        }
        for(int i=demb-1;i>dema;i--){
            ok[i][dema]=a[dem];
            dem++;
        }
        dema++;
        demb--;
    }
    cout<<endl<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ok[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}