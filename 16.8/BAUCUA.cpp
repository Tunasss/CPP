#include <bits/stdc++.h>
#include <ctime>
#include <stdio.h>
#include <cstdlib>
#include <unistd.h>
using namespace std;
map<int,int> arr;
map<int,int> arrx;
void quy_doi(int x)
{
    if(x==1)
        cout<<" Huou ";
    if(x==2)
        cout<<" Bau ";
    if(x==3)
        cout<<" Ga ";
    if(x==4)
        cout<<" Ca ";
    if(x==5)
        cout<<" Cua ";
    if(x==6)
        cout<<" Tom ";

}
void doi_mau()
{
    for(int i=1;i<=20;i++)
    {
        if(i%2==0)
            system("Color 2");
        else
            system("Color 7");
        usleep(3000);
    }
    system("Color 7");
}
void reset()
{
    arrx.clear();
    arr.clear();
    fflush(stdin);
    string s;
    cout<<endl<<endl;
    cout<<"=================================Nhan enter de tiep tuc=========================="<<endl;
    getline(cin,s);
}
int tinh_tien(int x,int xx)
{
    for(auto i:arr)
    {
       if(i.first==x)
        if(xx==1)
        return i.second+i.second/2;
        else
        if(xx==2)
        return i.second*2;
        else
        if(xx==3)
        return i.second*3;
    }
    return 0;
}
void infor(string name,int score)
{
    cout<<"- Tai khoan hien co cua "<<name<<": | "<<score<<endl<<endl;
    cout<<name<<" selected "<<endl;
    for(auto i:arr)
    cout<<i.first<<" "<<i.second<<endl;
cout<<endl;
}
void mau_me()
{
    for(int i=1;i<=90;i++)
    {
        usleep(20000);
        cout<<"=";
    }
    usleep(90000);
}
void bang(int room)
{
    cout<<"=====TLers IT 21-24====="<<endl;
    cout<<"Room "<<room<<endl;
    cout<<"===================="<<endl;
    cout<<"| Huou | Bau | Ga  |"<<endl;
    cout<<"===================="<<endl;
    cout<<"|  Ca  | Cua | Tom |"<<endl;
    cout<<"===================="<<endl;

}
int main()
{
    srand(time(NULL));
    int n,coin;
    int x, y, z;
    int score = 10000;
    // srand(time(NULL));
    // int res = rand() % (50 - 3 + 1) + 3;
    cout<<"Xin chao hay cho toi biet ten cua ban:"<<endl;
    string name;
    getline(cin,name);
    system("cls");
    mau_me();
    cout<<endl;
    int room;
    room=rand()%99+1;
    cout << "Chao mung - "<<name<<" - den voi song bac - TLers IT 21-24 - "<<endl;
    cout<<"Ban dang o ban so "<<room<<endl;
    cout<<"Ban co 10000 VND"<<endl;
    cout<<"==Good luck==";
    sleep(3);
    cout<<endl;
    mau_me();
    while (score != 0)
    {
        do{
                int kt=0;
            do
            {
                system("cls");
                bang(room);
                infor(name,score);
                cout << "Moi ban chon so 1-6 hoac 9 de chap nhan :";
                cin >> n;
                if(n<=6)
                {
                    cout<<endl<<"so tien dat cuoc la: "<<endl;
                    do
                    {
                        if(kt==1)
                            cout<<"Ban khong co du tien de cuoc hay cuoc lai"<<endl;
                            cin>>coin;
                        kt=1;
                    }

                    while(coin>score||coin<0);
                        arr[n]+=coin;
                        cout << "\n";
                        score-=coin;
                        kt=1;
                }

            } while (n > 6&&n!=9);
        } while(n!=9);
        int x = rand()%6+1;
        int y = rand()%6+1;
        int z = rand()%6+1;
        arrx[x]++;
        arrx[y]++;
        arrx[z]++;
        mau_me();
        cout<<endl;
        cout<<"====== Ket qua tro choi: ";
        quy_doi(x);
        quy_doi(y);
        quy_doi(z);
        cout<<"====="<<endl;

        int score2=tinh_tien(x,arrx[x])+tinh_tien(y,arrx[y])+tinh_tien(z,arrx[z]);
        if(score2>0)
        {
            doi_mau();
            cout<<"Chuc mung ban"<<endl;
            cout<<"Ban nhan duoc:"<<endl;
            if(tinh_tien(x,arrx[x])>0&&arrx[x]<=3)
            {
                cout<<"-";quy_doi(x);cout<<" x"<<arrx[x]<<" "<<tinh_tien(x,arrx[x])<<endl;
                arrx[x]=9;
            }
            if(tinh_tien(y,arrx[y])>0&&arrx[y]<=3)
            {
                cout<<"-";quy_doi(y);cout<<" x"<<arrx[y]<<" "<<tinh_tien(y,arrx[y])<<endl;
                arrx[y]=9;
            }
            if(tinh_tien(z,arrx[z])>0&&arrx[z]<=3)
            {
                cout<<"-";quy_doi(z);cout<<" x"<<arrx[z]<<" "<<tinh_tien(z,arrx[z])<<endl;
                arrx[z]=9;
            }
            cout<<"==============================="<<endl;
            cout<<"Tong cong | "<<score2<<" VND"<<endl;
            score+=score2;
            cout<<"Tai khoan ban hien gio la: " <<score<<endl;
        }
        else
        {
            cout<<"Chuc ban may man lan sau"<<endl;
            cout<<"Ban da trung 0"<<endl;
            cout<<"Tai khoan ban hien gio la: " <<score<<endl;
        }
        reset();
    }
}
