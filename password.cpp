#include <bits/stdc++.h>
using namespace std;
int main(){
	int m,t,n; cin >> m >> t >> n;
	string a="abcdefg";
	string b="abcdefg";string c;
	
	while(t--){
		
		c=b;
		b+='a';
		b+=c;
	}
//	cout << b[n%b.length()-1];return 0;
	for(int i=0;i<a.length();i++){
		if(a[i]==b[n%b.length()-1]){
			cout << i +1;return 0;
		}
	}
	//cout << b[n-1];
}
