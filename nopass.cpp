#include<bits/stdc++.h>
using namespace std;
constexpr int MAXN= 1e6 + 1;
int a[MAXN], b[MAXN], c[MAXN],n;
int main(){
	cin>>n;for(int i=0;i<n;i++){
		cin >> a[i];
		b[a[i]]=i;
	}
	for(int i=0;i<n;i++) cin >> c[i];
	int sol=0;
	for(int i=0;i<n;i++) {
		int ind=b[c[i]];
		for(int j=i+1;j<n;j++){
			if(ind>b[c[j]]) {
				sol++;break;
			}
		}
	}
	cout << sol;
	return 0;
}
