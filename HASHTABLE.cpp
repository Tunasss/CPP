#include <bits/stdc++.h>
#include <list>
using namespace std;
//( ͡° ͜ʖ ͡°)
//Tunass

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

#define fto(i,x,y) for(ll i = x; i <= y; i++)
const ll SIZE = 1000;
const ll MOD = 1e9 + 7;


list <pair<int,str>> table[SIZE];

bool isEmpty()
{
	int sum = 0;
	for (int i{}; i < SIZE; i++)
	{
		sum += table[i].size();
	}
	if (!sum) return false;
	return true;
}

int hashfun (int key){
	return key % SIZE;
}

void add (int key, str value){
	int hashValue = hashfun(key);
	auto& cell = table[hashValue];
	auto iter = begin(cell);
	bool keyExist = false;
	for (; iter != end(cell); iter++)
	{
		if (iter->first == key)
		{
			keyExist = true;
			iter->second = value;
			cout << "Exist!" << endl;
		}
	}
	if (!keyExist) 
	cell.emplace_back(key,value);
}

void remove (int key){
	int hashValue = hashfun(key);
	auto& cell = table[hashValue];
	auto iter = begin(cell);
	bool keyExist = false;
	for (; iter != end(cell); iter++)
	{
		if (iter->first == key)
		{
			keyExist = true;
			iter = cell.erase(iter);
			cout << "Removed!" << endl;
		}
	}
	if (!keyExist) cout << "Key not found!"; 
	
}

void print()
{
	for(int i{}; i < SIZE; i++)
	{
		if (table[i].size() == 0) continue;
		
		auto iter = table[i].begin();
		for(; iter != table[i].end(); iter++)
		{
			cout << "Key: "<< iter->first << " - Value: " << iter->second << endl;
		} 
	}
	cout << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//freopen(file".INP","r",stdin);
	//freopen(file".OUT","w",stdout);
	
	if (isEmpty())
	{
		cout << "CLEAR!" << endl;
	}
	else
	{
		cout << "Check code!" << endl;
	}
	
	add(1,"Vinh");
	add(4,"Huy");
	add(5,"Tuan");
	add(2,"Hao");
	add(3,"Khiem");
	
	print();
	
	add(3,"Nghi");
	print();
	
	remove(3);
	print();
	
	if (isEmpty())
	{
		cout << "CLEAR!" << endl;
	}
	else
	{
		cout << "GOOD JOB!" << endl;
	}
	
	cerr << "Time: " << clock() / double(CLOCKS_PER_SEC) << " sec.\n";
}

