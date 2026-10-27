#include <bits/stdc++.h>
using namespace std;
bool check(string s){
	for(int i=0;i<s.length()/2;i++){
		if(s[i]<s[s.length()-i-1]) return true;
	}
	return false;
}
int main(){
	string s; cin >> s;
	int n=s.length();
	vector <char> v;
	for(int i=0;i<n/2;++i){
		v.push_back(s[i]);
	}
	if(n%2==0){
		if(v[v.size()-1]<s[n/2])v[v.size()-1]=s[n/2];
		
	}
	if(n%2==1) {
		if(check(s)) {
			if(s[n/2]!='9')s[n/2]+=1;
			else{
				int nn=v.size()-1;
				while(v[nn-1]=='9') nn--;
				v[nn]+=1;
				s[n/2]='0';
			}
		}
		
	}
	for(int i=0;i<v.size();i++) cout << v[i];
	if(n%2==1) cout << s[n/2];
	for(int i=v.size()-1;i>=0;--i) cout << v[i];
	return 0;
}
