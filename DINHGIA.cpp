#include <fstream>
using namespace std;
#define fi "DINHGIA.INP"
#define fo "DINHGIA.OUT"
fstream f;
int main()
{
	f.open(fi,ios::in);
	int n,m,x=0,y=1,luu=0,luu2,l,p;
	f >> n >> m;
	int a[m];
	for(int i=0;i<m;i++)
	{
		f >> a[i];
	}
	f.close();
	f.open(fo,ios::out);
	for(int i=0;i <m-1;i++)
	{
		for(int j=i+1;j <m;j++)
		{
			if (a[i]>=a[j])
			{
				l=a[i];
				a[i]=a[j];
				a[j]=l;
			}
		}
	}
	for(int i=0;i <m;i++)
	{
		p=m-i;
		x=a[i]*p;
		if(luu<=x)
		{
			luu=x;
			luu2=a[i];
		}
	}
	f << luu2 << " " << luu;
	f.close();
	return 0;
}
