#include <bits/stdc++.h>
using namespace std;
int sol=0;
int main(){
	int n; cin >> n;
	for(int i=0;i<=n;i++){
		for(int j=i;j<=n;j++) sol+=i+j;
	}
	cout << sol;
}
