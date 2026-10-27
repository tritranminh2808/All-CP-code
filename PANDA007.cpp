#include <fstream>
using namespace std;
#define fi "PANDA007.INP"
#define fo "PANDA007.OUT"
fstream f;
int main()
{
	f.open(fi, ios::in);
	long long x;
	f >> x;
	f.close();
	f.open(fo, ios::out);
	if (x>0) f << "P";
	else f << "A";
	f.close();
	return 0;
}
