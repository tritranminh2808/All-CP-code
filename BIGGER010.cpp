#include <fstream>
using namespace std;
#define fi "BIGGER010.INP"
#define fo "BIGGER010.OUT"
fstream f;
int a,b,k=0;
int main()
{
	f.open(fi, ios::in);
	f >> a >> b;
	f.close();
	f.open(fo, ios::out);
	while (a<=b)
	{
		a*=3;
		b*=2;
		k++;
	}
	f << k;
	f.close();
	return 0;
}
