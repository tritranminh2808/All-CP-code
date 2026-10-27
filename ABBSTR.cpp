#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("ABBSTR.inp", "r", stdin);
    freopen("ABBSTR.out", "w", stdout);
    string s;
    cin >> s;
    for(int i=0;i<s.length();i++){
    	if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='y'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='Y') continue;
    	if(s[i]>='a'&&s[i]<='z') cout << "." << s[i];
    	else if(s[i]>='A'&&s[i]<='Z') cout << "." << char(s[i]+32);
	}
}
