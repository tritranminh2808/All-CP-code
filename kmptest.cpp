#include <bits/stdc++.h>
using namespace std;
int f[1000005];
int main(){
	string s; cin >> s;
	f[0]=0;
	for(int i=1;i<s.length();i++){
		int j=f[i-1];
		while(j>0&&s[i]!=s[j]) j=f[j-1];
		if(s[i]==s[j]) j++;
		f[i]=j;
	}
	for(int i=0;i<s.length();i++) cout << f[i] << " ";
	return 0;
}
