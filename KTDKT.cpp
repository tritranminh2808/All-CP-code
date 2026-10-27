#include <bits/stdc++.h>
using namespace std;
const int i=1e7+3;int dem;
bool chck[i];
int main(){
	freopen("KTDKT.INP","r+",stdin);
	freopen("KTDKT.OUT","w+",stdout);
	string a;getline(cin,a);
	for(int i=0;i<a.length();i++)
	{
		if(chck[int(a[i])]==0){
			dem++;chck[int(a[i])]=1;
		}
	}cout << dem;
	return 0;
}
