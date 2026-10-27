#include <bits/stdc++.h>
using namespace std;
const int p=1e5+5;
int ss[p],pp[p];

int main(){
	string s;cin>> s;
	int n=s.length();
	for(char c:s){
		++pp [c-'@'];
	}
	for(int c='A'; c<='Z';++c){
		pp[c-'@']+=pp[c-'@'-1];
	}
	for(int i=n-1;i>=0;--i){
		ss[--pp[s[i]-'@']]=i;
	}
	for(int i=1;i<n;i++) cout << s[ss[i]];
	
}
