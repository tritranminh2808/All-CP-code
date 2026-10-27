#include <bits/stdc++.h>
using namespace std;
long long n;
long long bona(long long n)
{

	while(n%4!=0)
	{
		n++;
	}
	return n;
}
long long bonb(long long n)
{

	while(n%4!=0)
	{
		n--;
	}
	return n;
}
long long baya(long long n)
{

	while(n%7!=0)
	{
		n++;
	}
	return n;
}
long long bayb(long long n)
{

	while(n%7!=0)
	{
		n--;
	}
	return n;
}
long long muoimota(long long n)
{
	
	while(n%11!=0)
	{
		n++;
	}
	return n;
}
long long muoimotb(long long n)
{

	while(n%11!=0)
	{
		n--;
	}
	return n;
}
long long haitama(long long n)
{

	while(n%28!=0)
	{
		n++;
	}
	return n;
}
long long haitamb(long long n)
{
	
	while(n%28!=0)
	{
		n--;
	}
	return n;
}
long long bonbona(long long n)
{

	while(n%44!=0)
	{
		n++;
	}
	return n;
}
long long bonbonb(long long n)
{

	while(n%44!=0)
	{
		n--;
	}
	return n;
}
long long baybaya(long long n)
{

	while(n%77!=0)
	{
		n++;
	}
	return n;
}
long long baybayb(long long n)
{
	
	while(n%7!=0)
	{
		n--;
	}
	return n;
}
long long blta(long long n)
{
	
	while(n%308!=0)
	{
		n++;
	}
	return n;
}
long long bltb(long long n)
{
	
	while(n%308!=0)
	{
		n--;
	}
	return n;
}

int main()
{
	freopen("DIVISIBLE006.INP","r+",stdin);
	freopen("DIVISIBLE006.OUT","w+",stdout);
	cin >> n;
	long long k=0;
	for(long long i=0;i<n;i++)
	{
		long long x,y;
		cin >> x >> y;
			long long d1,d2,d3;
			if(y<4) d1=0;
			else d1=(bonb(y)-bona(x))/4+1;
			if(y<7) d2=0;
			else d2=(bayb(y)-baya(x))/7+1;
			if(y<11) d3=0;
			else d3=(muoimotb(y)-muoimota(x))/11+1;
			long long c1,c2,c3,v;
			if(y<28) c1=0;
			else c1=(haitamb(y) -haitama(x))/28+1;
			if(y<44) c2=0; else c2=(bonbonb(y) -bonbona(x))/44+1;
			if(y<77) c3=0;
			else c3=(baybayb(y) -baybaya(x))/77+1;
			if(y<308) v=0;
			else v=(bltb(y) -blta(x))/308+1;
			k=d1+d2+d3-c1-c2-c3+v;
			cout << k << "\n";
	}
	
	return 0;
}
