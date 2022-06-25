#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef string str;
typedef pair <int,int> ii;
#define file "TEST"
#define st first
#define nd second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define er equal_range
#define bin binary_search
#define vll vector<ll>
#define vi vector<int>
#define all(v) (v).begin(), (v).end()
#define FOR(i,x,y) for(ll i = x; i <= y; i++)
#define FOS(i,x,y) for(ll i = x; i >= y; i--)
const ll SIZE = 1e5 + 5;
const ll MOD = 1e9 + 7;
#define dbg(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]  "
#define dbge(...) cerr << "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "]" << endl;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

// signed main()
// {
//     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//     //freopen(file".INP","r",stdin);
//     //freopen(file".OUT","w",stdout);

//     char a[11];
//     FOR(i,1,10) cin >> a[i];
//     ll res;
//     ll cnt_odd = 0, cnt_2 = 0, cnt_3 = 0, cnt_4 = 0;
//     ll n[6];
//     vector <char> m(4,0);

//     for (ll i = 1; i <= 10; i += 2){
//   		char mode = a[i + 1];
//   		m[mode]++;
//   		char num = a[i];
//   		if (num - '0' <= 9 && num - '0' >= 2){
//   			if (num % 2 != 0) cnt_odd++;
//   			n[num - '0']++;
//   		}
//     }

//     for (ll i = 1; i <= 10; i++){
//     	if (n[i] == 2) cnt_2++;
//     	else if (n[i] == 3) cnt_3++;
//     	else if (n[i] == 4) cnt_4++;
//     }

//     if (cnt_odd == 5) res = 1; // Mau thau
//     else if (cnt_2 == 1) res = 2; // Doi
//     else if (cnt_2 == 2) res = 3; // Thu
// 	else if (cnt_2 == 1) res = 4; // Sam


// 	else if (m['H'] == 5 || m['D'] == 5 || m['C'] == 5 || m['S'] == 5) res = 6; // Thung
// 	else if (cnt_2 == 1 && cnt_3 == 1) res = 7; // Cu lu;
// 	else if (cnt_4 == 1) res = 8; //Tu Quy


//     return 0;
// }


int main()
{
	int t,i,j,k,rank_2,rank_3;
	int poker[13][4];
	int row[13];
	int column[4];
	string str;
	getline(cin,str);
	bool done,flush;
	flush = false;
	rank_2 = 0;
	rank_3 = 0;
	done = false;
	for(i=0;i<13;i++)
	{
		for(j=0;j<4;j++)
			poker[i][j] = 0;
	}
	for(i=0;i<4;i++)
		column[i] = 0;
	for(i=0;i<13;i++)
		row[i] = 0;
	for(i=0;i<14;i += 3)
	{
		switch(str[i])
		{
		case 'A':
			j = 1;
			break;
		case 'T':
			j = 10;
			break;
		case 'J':
			j = 11;
			break;
		case 'Q':
			j = 12;
			break;
		case 'K':
			j = 13;
			break;
		default:
			j = str[i] - 48;
		}
		switch(str[i+1])
		{
		case 'S':
			k = 0;
			break;
		case 'H':
			k = 1;
			break;
		case 'D':
			k = 2;
			break;
		case 'C':
			k = 3;
			break;
		}
		poker[j-1][k] = 1;
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<13;j++)
			column[i] += poker[j][i];
	}
	for(i=0;i<13;i++)
	{
		for(j=0;j<4;j++)
			row[i] += poker[i][j];
	}
	for(i=0;i<4;i++)
	{
		if(column[i] == 5)
		{
			if(poker[0][i] == 1 && poker[9][i] == 1 && poker[10][i] == 1 && poker[11][i] == 1 && poker[12][i] == 1)
			{
				printf("Thung");
				done = true;
			}
			else
			{
				for(j=0;j<9;j++)
				{
					if(poker[j][i] == 1)
						break;
				}
				for(k=j+1;k<=(j+4);k++)
				{
					if(poker[k][i] != 1)
						break;
				}
				if(k == (j+5))
				{
					printf("Thung pha sanh");
					done = true;
				}
			}
			flush = true;
			break;
		}
	}
	if(!done)
	{
		for(i=0;i<13;i++)
		{
			if(row[i] == 4)
			{
				printf("Tu quy");
				done = true;
			}
			else if(row[i] == 3)
				rank_3 ++ ;
			else if(row[i] == 2)
				rank_2 ++ ;
		}
	}
	if(!done && rank_3 == 1 && rank_2 == 1)
	{
			printf("Cu lu");
			done = true;
	}
	if(!done && flush)
	{
		printf("Thung");
		done = true;
	}
	if(!done)
	{
		for(j=0;j<9;j++)
		{
			if(row[j] == 1)
				break;
		}
		for(k=j+1;k<=(j+4);k++)
		{
			if(row[k] != 1)
				break;
		}
		if(k == (j+5))
		{
			printf("Sanh");
			done = true;
		}
		else if(row[0] == 1 && row[9] == 1 && row[10] == 1 && row[11] == 1 && row[12] == 1)
		{
			printf("Sanh");
			done = true;
		}
	}
	if(!done && rank_3 == 1)
	{
		printf("Sam");
		done = true;
	}
	if(!done && rank_2 == 2)
	{
		printf("Thu");
		done = true;
	}
	if(!done && rank_2 == 1)
	{
		printf("Doi");
		done = true;
	}
	if(!done)
		printf("Mau thau");
}
	