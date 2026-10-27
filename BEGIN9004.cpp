#include <fstream>
using namespace std;
#define fi "BEGIN9004.INP"
#define fo "BEGIN9004.OUT"
fstream f;
int b;
unsigned long long a;
int main()
{
	f.open(fi, ios::in);
	f >> a >> b;
	if(b==0){
		 f<< "1";
		return 0;
	}
	int A=a%10,x=b-1,y=b-2,z=b-3;
	f.close();
	f.open(fo, ios::out);
	if(A==0||A==1||A==5||A==6)
	{
		f << A;
		return 0;
	}
	if (A==3)
	{
		if (b%4==0) 
		{
			f << 1;
			return 0;
		}
		else if(x%4==0)
		{
			f << 3;
			return 0;
		}
		else if (y%4==0)
		{
			f << 9;
			return 0;
		}
		else if (z%4==0)
		{
			f << 7;
			return 0;
		}
	}
	if (A==7)
	{
		if (b%4==0) 
		{
			f << 1;
			return 0;
		}
		else if(x%4==0)
		{
			f << 7;
			return 0;
		}
		else if (y%4==0)
		{
			f << 9;
			return 0;
		}
		else if (z%4==0)
		{
			f << 3;
			return 0;
		}
	}
	if (A==2)
	{
		if (b%4==0) 
		{
			f << 6;
			return 0;
		}
		else if(x%4==0)
		{
			f << 2;
			return 0;
		}
		else if (y%4==0)
		{
			f << 4;
			return 0;
		}
		else if (z%4==0)
		{
			f << 8;
			return 0;
		}
	}
	if (A==8)
	{
		if (b%4==0) 
		{
			f << 6;
			return 0;
		}
		else if(x%4==0)
		{
			f << 8;
			return 0;
		}
		else if (y%4==0)
		{
			f << 4;
			return 0;
		}
		else if(z%4==0)
		{
			f << 2;
			return 0;
		}
	}
	if (A==4)
	{
		if (b%2==0)
		{
			f << 6;
			return 0;
		}
		if (b%2==1)
		{
			f << A;
			return 0;
		}
	}
	if (A==9)
	{
		if (b%2==0)
		{
			f << 1;
			return 0;
		}
		if (b%2==1)
		{
			f << A;
			return 0;
		}
	}
	f.close();
	return 0;
}
