#include <bits/stdc++.h>

using namespace std;


int main() {
	int n; cin >> n;
    string s,ss; cin >> s;
    int sol=0,sol2=0;
    for(int i=0;i<s.length()-1;i++){
    	if(s[i]=='0'&&s[i+1]=='0') sol++;
	}
	for(int i=0;i<s.length()-1;i++){
    	if(s[i]=='1'&&s[i+1]=='1') sol2++;
	}
	cout << max(sol,sol2);
    return 0;
}

