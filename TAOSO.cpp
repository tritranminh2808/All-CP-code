#include<fstream>
using namespace std;
#define fi "TAOSO.INP"
#define fo "TAOSO.OUT"
fstream f;
int ss (int a)
{
	while (a >= 10)
	{
		a/=10;
	}
	return a;
}
int main()
{
	f.open(fi,ios::in);
	int n;
	f >> n;
	f.close();
	f.open(fo,ios::out);
	int i=2,k=0,z;
	int a[100000];
	while(n>1)
	{
		if(n%i==0)
		{
			n/=i;
			a[k]=i;
			k++;
		}
		else  i++;
	}
	for(int i=0;i<k-1;i++)
	{
		for(int j=i+1;j<k;j++)
		{
			if (ss(a[i])<=ss(a[j])) swap(a[i],a[j]);
		}
	}
	for(int i=0;i<k;i++)
	{
		f << a[i];
	}
	f.close();
	return 0;
}
