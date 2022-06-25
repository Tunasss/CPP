#include <iostream>
using namespace std;
int main()
{int a,b,d=0;cin>>a>>b;int x=a^b;for (int i=0;i<32;i++){if (x&1!=0)d++;x=x>>1;}cout<<d;}

