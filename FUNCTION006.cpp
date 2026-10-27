#include <fstream>
using namespace std;
#define fi "FUNCTION006.INP"
#define fo "FUNCTION006.OUT"
fstream f;
int main()
{
	f.open(fi, ios::in);
	unsigned long long a,b,c,x,k;
	f >> a >> b >>c>>x;
	f.close();
	f.open(fo, ios::out);
	k=a*x*x+b*x+c;
	f << k;
	f.close();
	return 0;
}
