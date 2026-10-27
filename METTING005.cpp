#include <bits/stdc++.h>
using namespace std;
#define fi "METTING005.INP"
#define fo "METTING005.OUT"
fstream f;
int main()
{
	f.open(fi, ios::in);
	int n,x;
	char b;
	f >> n >> b;
	string a[n];
	for(int i=0;i<n;i++)
	{
		f >> a[i];
	}
	f.close();
	f.open(fo, ios::out);
	for(int i=0;i<n;i++)
	{
		x=0;
		string z=a[i];
		for(int j=0; j<z.size();j++)
		{
			if (z[j]==b) x++;
		}
		if (x==0) f << z << "\n";
	}
	f.close();
	return 0;
}
