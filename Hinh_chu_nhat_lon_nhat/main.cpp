#include <iostream>
using namespace std;
int a[105][105];
int ld1,lc1,ld2,lc2;
int m,n;
int sumMax=INT_MIN;
void taob (int m,int n)
{
    for (int j=2;j<=n;j++)
    a[1][j]=a[1][j]+a[1][j-1];
    for (int i=2;i<=m;i++)
        for (int j=1;j<=n;j++)
           a[i][j]=a[i][j]+a[i][j-1];
}
int tong(int d1,int c1,int d2,int c2)
{
    int p;
    p=a[d2][c2]-a[d1-1][c2]-a[d2][c1-1]+a[d1-1][c1-1];
    return p;
}
void finx ()
{
    int dong1,cot1,dong2,cot2;
    int sum=0;
    for (int dong1=1;dong1<=m;dong1++)
     for (int cot1=1;cot1<=n;cot1++)
      for (int dong2=dong1;dong2<=m;dong2++)
       for (int cot2=cot1;cot2<=n;cot2++)
      {
          sum=tong(dong1,cot1,dong2,cot2);
          if (sum>=sumMax)
           {
            sumMax=sum;
            ld1=dong1;
            lc1=cot1;
            ld2=dong2;
            lc2=cot2;
           }
      }
}
int main()
{
    cin>>m>>n;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
        cin>>a[i][j];
    taob(m,n);
    finx();
    cout<<sumMax<<endl;
    cout<<ld1<<" "<<lc1<<" "<<ld2<<" "<<lc2;
}
