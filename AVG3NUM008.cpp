#include <fstream>
using namespace std;
#define fi "AVG3NUM008.INP"
#define fo "AVG3NUM008.OUT"
fstream f;
int a,b,x,c;
int main()
{
	f.open(fi, ios::in);
	f >> a >> b >> x;;
	f.close();
	f.open(fo, ios::out);
	c=x*3-a-b;
	f << c;
	f.close();
	return 0;
}
