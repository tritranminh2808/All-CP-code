#include <bits/stdc++.h>
using namespace std;
int sol=0;
bool check(string a, string b){
	int t=0;
	for(int i=0;i<a.length();i++){
		if(a[i]==b[0]) {
			bool chck=0;
			for(int j=0;j<b.length();j++){
				if(a[i+j]!=b[j]) {
					chck=1;
					break;
				}
			}
			if(chck==0) return true;
		}
	}
	return false;
}
bool cc[100000];
int main(){
	string a,b;
	getline (cin,a);
	getline(cin,b);
	//cout << a<< endl << b;
	int k=0;
	for(int i=0;i<a.length();i++){
		int l; cin >> l;
		cc[l-1]=1;
		string c="";
		for(int j=0;j<a.length();j++){
			if(cc[j]==0) c+=a[j];
		}
	//	cout << c << endl;
		k++;
		if(check (c,b)) {	
			sol+=k;k=0;
		}
		/*else {
			cout << sol; return 0;		
		}*/
	}
	cout << sol;
	return 0;
}
