#include <fstream>
using namespace std;
#define fi "POSIPROD005.INP"
#define fo "POSIPROD005.OUT"
fstream f;
int main()
{
	f.open(fi, ios::in);
	int n,sa=0,sd=0;
	f >> n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		f >> a[i];
		
	}
	f.close();
	f.open(fo, ios::out);
	for(int i=0;i<n;i++)
	{
		if (a[i]==0)
		{
			f << "-1";
			return 0;
		}
		if (a[i]<0) sa++;
		if(a[i]>0) sd++;
	}
	if (sa<sd) f << sa;
	else f << sd;
	f.close();
	return 0;
}
