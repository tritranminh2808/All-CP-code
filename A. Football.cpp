#include <bits/stdc++.h>
using namespace std;
int main(){
	string a; cin >> a;
	int n=a.length();
	for(int i=0;i<n-6;++i){
		if(a[i]==a[i+1]&&a[i+1]==a[i+2]&&a[i+2]==a[i+3]&&a[i+3]==a[i+4]&&a[i+4]==a[i+5]&&a[i+5]==a[i+6]){
			cout << "YES";return 0;
		}
	}
	cout << "NO";
	return 0;
	
}
