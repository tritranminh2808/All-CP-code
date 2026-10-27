#include <bits/stdc++.h>
using namespace std;
char sech[1005][1005];
int main(){
//	freopen("output.out","w",stdout);
	string s; cin >> s;
	for(int i=0;i<=1000;i++){
		for(int j=0;j<=1000;j++) sech[i][j]='.';
	}
	int l=500,r=0;
	s='!'+s;
	int n=s.length()-1;
	for(int i=1;i<=n;i++){
		if(s[i]=='(' ){
			if(s[i]!=s[i-1]){
				r++;
				sech[l][r]='/';
			}
			else{
				l--;
				r++;
				sech[l][r]='/';
			}
		}
		else {
			if(s[i]!=s[i-1]){
				r++;
				sech[l][r]='|';
			}
			else{
				l++;
				r++;
				sech[l][r]='|';
			}
		}
	}
	int s1=-1,s2=1001,e1=0,e2=0;
	for(int i=0;i<1000;i++){
		s1++;
		bool loz=0;
		for(int j=0;j<=1000;j++){
			if(sech[i][j]=='/'||sech[i][j]=='|') {
				loz=1;
				break;
			}
		}
		if(loz) break;
	}
	for(int i=1000;i>=0;i--){
		s2--;
		bool cac=0;
		for(int j=0;j<=1000;j++){
			if((char)sech[i][j]=='/'||(char)sech[i][j]=='|') {
				cac=1;
				break;
			}
		}
		if(cac) break;
	}
	int bien=1001;
	for(int i=1000;i>=0;i--){
		bien--;
		bool p=0;
		for(int j=0;j<=1000;j++){
			if(sech[j][i]!='.'){
				p=1;
				break;
			}
		}
		if(p) break;
	}
	for(int i=s1;i<=s2;i++){
		for(int j=1;j<=bien;++j) {
			if(sech[i][j]=='|') cout << char(92);
			else cout << sech[i][j];
		}
		cout << "\n";
	}
	return 0;
}
