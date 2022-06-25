#include <bits/stdc++.h>
using namespace std;
int m,n,tam=0,dem=0,a[100][100];
int d1[4] = {1, 0, -1, 0}, d2[4] = {0, 1, 0, -1};
void loang (int x,int y)
{
    a[x][y]=dem;
    for (int i=0; i<4; i++)
        if (a[x + d1[i]][y + d2[i]]==-1)
            loang(x + d1[i], y  + d2[i]);
}

int main()
{

    int m,n;
    cin>>m>>n;
    for(int i=0;i<=m+1;i++)
        for(int j=0;j<=n+1;j++)
        a[i][j]=0;
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            cin>>a[i][j];
            if (a[i][j])a[i][j]=-1;
        }
    }
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++){
            if (a[i][j]==-1){
                dem++;
                loang(i,j);
            }
        }
    cout<<dem<<endl;
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++)
            cout<<a[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}
