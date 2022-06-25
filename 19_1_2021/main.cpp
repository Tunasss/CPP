#include <bits/stdc++.h>
using namespace std;
//Bai 1
//int main()
//{
//    int n;
//    cin>>n;
//    int a[100];
//    for (int i=0;i<n;i++)
//        cin>>a[i];
//    for (int i=0;i<n-1;i++)
//    {
//        if (abs(a[i])>a[i+1])
//            cout<<a[i]<<" ";
//    }
//}
//Bai 2
//int main()
//{
//    int n,sum;
//    cin>>n;
//    int a[100];
//    for (int i=0; i<n; i++)
//        cin>>a[i];
//    for (int i=0; i<n; i++)
//    {
//        int k=a[i];
//        while (a[i]/10!=0)
//        {
//            a[i]/=10;
//        }
//        if (a[i]%2==1)
//        {
//            sum+=k;
//        }
//    }
//    cout<<sum;
//}
//Bai 3
//int main()
//{
//    int n,sum;
//    cin>>n;
//    int a[100];
//    for (int i=0; i<n; i++)
//        cin>>a[i];
//    for (int i=1; i<n-1; i++)
//    {
//        if (a[i]>a[i+1]&&a[i]>a[i-1])
//        {
//            sum+=a[i];
//        }
//    }
//    cout<<sum;
//}
//Bai 4
//int main()
//{
//    int n;
//    int k=0;
//    cin>>n;
//    int a[100];
//    int b[100];
//    for (int i=0; i<n; i++)
//        cin>>a[i];
//    sort (a,a+n);
//    for (int i=0; i<n; i++)
//    {
//        if (a[i]!=a[i+1])
//        {
//            b[k]=a[i];
//            k++;
//        }
//    }
//    for (int i=0; i<k; i++)
//    {
//        int dem=0;
//        for (int j=0; j<n; j++)
//        {
//            if (b[i]==a[j])
//                dem++;
//        }
//        if (dem==1) cout<<b[i]<<" ";
//    }
//}
//Bai 5
//int main()
//{
//    int n;
//    cin>>n;
//    int a[100];
//    for (int i=0; i<n; i++)
//        cin>>a[i];
//    for (int i=0; i<n; i++)
//    {
//        if (a[i]==0&&a[i+1]==0)
//        {
//            cout<<1;
//            return 0;
//        }
//    }
//    cout<<0;
//}
//Bai 6
//int main()
//{
//    int n;
//    int dem=0;
//    cin>>n;
//    int a[100];
//    for (int i=1; i<=n; i++)
//        cin>>a[i];
//    for (int i=1; i<=n/2; i++)
//    {
//        if (a[i]==a[n-i+1])
//        {
//            dem++;
//        }
//    }
//    if (dem==n/2) cout<<1;
//    else cout<<0;
//}
//Bai 7
//int main()
//{
//    int n;
//    cin>>n;
//    int a[100],l[100];
//    int d=1;
//    for (int i=1; i<=n; i++)
//    {
//        cin>>a[i];
//        if (a[i]%2!=0)
//        {
//            l[d]=a[i];
//            d++;
//        }
//    }
//    sort (l,l+d);
//    d=1;
//    for (int i=1; i<=n; i++)
//    {
//        if (a[i]%2!=0)
//        {
//            a[i]=l[d];
//            d++;
//        }
//        cout<<a[i]<<" ";
//    }
//}
//Bai 8
//int main()
//{
//    int n;
//    cin>>n;
//    int a[100],c[100],l[100];
//    int d1=1,d2=1;
//    for (int i=1; i<=n; i++)
//    {
//        cin>>a[i];
//        if (a[i]%2!=0)
//        {
//            l[d1]=a[i];
//            d1++;
//        }
//        else
//        {
//            c[d2]=a[i];
//            d2++;
//        }
//    }
//    sort (l,l+d1);
//    sort (c,c+d2);
//    d1=1,d2=1;
//    for (int i=1; i<=n; i++)
//    {
//        if (a[i]%2!=0)
//        {
//            a[i]=l[d1-1];
//            d1++;
//        }
//    }
//    for (int i=1; i<=n; i++)
//    {
//        if (a[i]%2==0)
//        {
//            a[i]=c[d2-1];
//            d2++;
//        }
//    }
//    for (int i=1; i<=n; i++)
//        cout<<a[i]<<" ";
//}
//Bai 9
//int main()
//{
//    int n,m;
//    cin>>n>>m;
//    int a[n],b[n+1],t=0;
//    b[0]=0;
//    for(int i=0; i<n; i++)
//    {
//        cin>>a[i];
//        t+=a[i];
//        b[i+1]=t;
//    }
//    int j=0,dau=0,cuoi=0;
//    for(int i=1; i<n; i++)
//    {
//        int t=0;
//        while(j<=i)
//        {
//            if(b[i]-b[j]==m)
//            {
//                t=1;
//                dau=j;
//                cuoi=i;
//                break;
//            }
//            else
//                j++;
//        }
//        if(t==1)
//            break;
//        else j=0;
//    }
//    if(t==0)
//        cout<<-1;
//    else
//        for(int i=dau; i<cuoi; i++)
//            cout<<a[i]<<' ';
//    return 0;
//}
//Bai 10
//int main()
//{
//    int n;
//    cin>>n;
//    vector<int> a(n+100,0);
//    int maxx=INT_MIN;
//    for (int i=0; i<n; i++)
//        cin>>a[i];
//    for (int i=0; i<n; i++)
//    {
//        int temp=0;
//        int j=i;
//        while (a[j]>0)
//        {
//            temp+=a[j];
//            j++;
//        }
//        if (maxx<temp)
//            maxx=temp;
//    }
//    for (int i=0; i<n; i++)
//    {
//        int temp=0;
//        int j=i;
//        while (a[j]>0)
//        {
//            temp+=a[j];
//            j++;
//        }
//        if (maxx==temp)
//        {
//            for (int t=i;t<j;t++)
//                cout<<a[t]<<" ";
//            cout<<endl;
//        }
//    }
//    return 0;
//}
int a[10],n;
void init ()
{
    cin >> n;
}
void output()
{
    for(int i=0;i<n;i++)
        cout << a[i];
    cout << endl;
}
void tim(int i)
{
    for(int j=0;j<=1;j++)
    {
        a[i]=j;
        if(i==n-1)
            output();
        else
            tim(i+1);
    }
}
int main()
{
    init();
    tim(0);
}
