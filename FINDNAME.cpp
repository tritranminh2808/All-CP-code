#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("FINDNAME.inp", "r", stdin);
    freopen("FINDNAME.out", "w", stdout);
    string s;
    cin >> s;
    cout<< s[0];
    for(int i=1;i<s.length();i++){
    	if(s[i]=='m'){
    		if(s[i-1]=='a'||s[i-1]=='e'||s[i-1]=='i'||s[i-1]=='o'||s[i-1]=='u'||s[i-1]=='y') continue;
		}
		cout << s[i];
	}
}
