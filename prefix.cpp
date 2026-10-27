#include <bits/stdc++.h>
using namespace std;
int a[100005],kmp[100005];
char b[100005];
int main(){
	int n; cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	b[0]='a';
	for(int i=1;i<n;i++){
		if(a[i]>0) b[i]=b[a[i]-1];
		else b[i]=char(b[a[i-1]]+1);
	}
	kmp[0]=0;
	for(int i=1;i<n;i++){
		int j=kmp[i-1];
		while(j>0&&b[i]!=b[j]) j=kmp[j-1];
		if(b[i]==b[j]) ++j;
		kmp[i]=j;
	} 
	for(int i=0;i<n;i++){
		if(kmp[i]!=a[i]) {
			cout << -1;
			return 0;
		}
	}
	for(int i=0;i<n;i++) cout << b[i];
	return 0;
}
