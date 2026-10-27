#include <bits/stdc++.h>
using namespace std;
int nn;
string s;
int sol=0;
bool b=0;
int main(){
	cin >> nn;
	cin >> s;
	bool sech=1;
	while(sech==1){
//		cout << s << " ";
		sech=0;
		int n=s.length();
		int luu=0;
		
		for(int i=0;i<n-2;i++){
			string temp;
			temp+=s[i];temp+=s[i+1];temp+=s[i+2];
			
			if(temp=="ABC"){
				sech=1;
				if(b==0){
					if(i<n-3&&i>0&&s[i-1]=='A'&&s[i+3]=='C') {
						luu=i;
						continue;
					}
					s.replace(i,3,"B");
					sol++;
					break;
				}
				else{
//					cout << i;
					s.replace(i,3,"AC");
					sol++;
					break;
				}
			}
		}
		b=1-b;
		if(s.length()==n){
			s.replace(luu,3,"B");
			sol++;
		}
	}
	cout << sol;
	return 0;
}
