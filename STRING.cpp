#include <bits/stdc++.h>
using namespace std;
int dem[2000];
bool check[2000];
int d=0;
int main()
{
	freopen("STRING.inp","r",stdin);
	freopen("STRING.out","w",stdout);
	string a;
	getline(cin,a);
	int n=a.length();
	for(int i=0;i<n;i++) dem[int(a[i])]++;
	for(int i=0;i<200;i++) {
		if(dem[i]!=0) d+=dem[i];
	}
	int max1=-99,max2=-99;
	for(int i=0;i<200;++i){
		if(dem[i]>max1) {
			max1=dem[i];
			max2=i;
		}
	}
	cout << d << "\n" << char(max2) << " " << max1 << "\n";
	for(int i=0;i<n;i++){
		if(check[int(a[i])]==0) {
			cout << a[i] ;
			check[int(a[i])]=1;
		}
	}
	return 0;
}
