#include<fstream>
using namespace std;
#define fi "VT.INP"
#define fo "VT.OUT"
fstream f;
int haha(int a, int b)
{
	while (a>b)
	{
		a=a-b;
	}
	return a;
}
int main()
{
	f.open(fi,ios::in);
	int n,k;
	f>>n>>k;
	int a[n];
	for (int i=0;i<n;i++)
	{
		a[i]=i+1;
	}
	f.close();
	f.open(fo, ios::out);
	int t=k;
	while (n>1)
	{
		for (int i=haha(t, n)-1;i<n-1;i++)
		{
			a[i]=a[i+1];
		}
		if (t>n) t=haha(t,n);
		t+=k-1;
		n--;
	}
	for (int i=0;i<n;i++)
	{
		f << a[i];
	}
	f.close();
	return 0;
}
