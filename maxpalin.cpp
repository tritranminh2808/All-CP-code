#include <bits/stdc++.h>
using namespace std;
int s[100005], sol[100005];
bool check[100005];
int main(){
	int n,k; cin >> n >> k;
	string a; cin >> a;
	for(int i=1;i<=n;i++) {
		s[i]=a[i-1]-'0';
		sol[i]=s[i];
	}
	for(int i=1;i<=n/2;i++){
		if(s[i]!=s[n-i+1]){
			if(k>0){
				s[i]=max(s[i],s[n-i+1]);
				s[n-i+1]=max(s[i],s[n-i+1]);
				check[i]=1;
				check[n-i+1]=1;
				k--;
			}
			else {
				cout <<-1;
				return 0;
			}
		}
		sol[i]=s[i];
		sol[n-i+1]=s[n-i+1];
	}
	int ind=1;
	for(int i=1;i<=n/2;i++){
		if(sol[i]!=9){
			if(check[i]&&k>=1){
				sol[i]=9;
				sol[n-i+1]=9;
				k--;
			}
			else if(k>=2){
				sol[i]=9;
				sol[n-i+1]=9;
				k-=2;
			}
		}
	}
//	cout << k;
	if(k>0&&n%2==1) sol[n/2+1]=9;
	for(int i=1;i<=n;i++) cout << sol[i];
}
