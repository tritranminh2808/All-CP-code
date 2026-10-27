#include <fstream>
using namespace std;
#define fi "TINHTONG009.INP"
#define fo "TINHTONG009.OUT"
fstream f;
int main()
{
	f.open(fi, ios::in);
	long long n,t,k;
	f >> n >> t;
	k=n*t;
	f.close();
	f.open(fo, ios::out);
	f << k;
	f.close();
	return 0;
}
