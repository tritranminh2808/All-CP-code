#include<bits/stdc++.h>
using namespace std;
long long a[1000000],n,i,j;
int main(){
	freopen("CAU20.INP","r",stdin);
	freopen("CAU20.OUT","w",stdout);
	cin>>n;
	for(i=0;i<n;i++){
		cout<<a[i];
	}
	for(i=0;i<n-1;i++){
		j=i+1;
		if(a[i]>a[j]) {
			cout<<"FALSE";return 0;
		}
	}
	cout<<"TRUE";
}
