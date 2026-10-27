#include <bits/stdc++.h>
using namespace std;
bool check(string s){
	stack <int> st;
	for(auto i : s){
		if(i=='(') st.push('(');
		else{
			if(!st.empty()) st.pop();
			else return false;
		}
	}
	if(st.empty()) return true;
	return false;
}
int main(){
	string s;
	cin >> s;
	int dong=0,mo=0;
	for(auto i : s){
		if(i=='(') mo++;
		if(i==')') dong++;
	}
	if(mo!=dong){
		cout << -1; return 0;
	}
	if(check(s)) {
		cout << 0; return 0;
	}
	int iiiii=0,iiii=0,ii,iii;
	for(int i=0;i<s.length();i++){
		if(s[i]==')')iiiii--;
		else iiiii++;
		if(iiiii<0&&iiii>iiiii) {
			ii=i;
			iiii=iiiii;
		}
	}
	iiiii=0;
	iiii=0;
	for(int i=s.length()-1;i>=0;i--){
		if(s[i]=='(')iiiii--;
		else iiiii++;
		if(iiiii<0&&iiii>iiiii) {
			iii=i;
			iiii=iiiii;
		}
	}
	int k2=s.length()-iii;
	cout << min(k2,ii+1);
}
