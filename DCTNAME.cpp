#include <bits/stdc++.h>
using namespace std;

vector <int> v3(26);
int main()
{
	freopen("DCTNAME009.inp","r",stdin);
	freopen("DCTNAME009.out","w",stdout);
	string a,b;
	getline(cin,a);
	getline(cin,b);
	int n=a.length(),m=b.length();

	for(int i=25;i>=0;i--){
		vector <int> v1(26);
		vector <int> v2(26);
		for(int j=0;j<a.length();j++)	if((int)a[j]-97==i) v1[i]++;
		for(int j=0;j<b.length();j++)	if((int)b[j]-97==i) v2[i]++;
		if(v1[i]>0&&v2[i]>0){
			v3[i]=min(v2[i],v1[i]);
			//cout << v1[i] << " " << v2[i] << "\n";
			int t=min(v2[i],v1[i]);
			int l1=0,l2=0,vt1,vt2;
			//cout << char(97+i) << " " << t << "\n";
			for(int k=0;k<a.length();k++){
				if(int(a[k])-97==i){
					l1++;
					if(l1==t) {
						vt1=k;
						break;
					}
				}
			}
			for(int k=0;k<b.length();k++){
				if(int(b[k])-97==i){
					l2++;
					if(l2==t) {
						vt2=k;
						break;
					}
				}
			}
			//cout << vt1 << " " << vt2 << endl;
			a.erase(a.begin(),a.begin()+vt1+1);
			b.erase(b.begin(),b.begin()+vt2+1);
		//	cout << a << " " << b << "\n";
		}
	}
	//cout << a;
	for(int i=25;i>=0;i--){
		if(v3[i]>0){
			for(int j=0;j<v3[i];j++){
				cout << char(i+97);
			}
		}
	}
	return 0;
}
