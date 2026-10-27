#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;
int main(){
	int n;cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)a.push_back(a[i]);
	int mx=0,st=0,len=1,bs=0;
	for(int i=1;i<a.size();i++){
		if(a[i]>=a[i-1])len++;
		else{
			if(len>mx){
				mx=len;bs=i-len;
			}len=1;
		}
	}
	if(len>mx){
		mx=len;bs=a.size()-len;
	}
	int p=(bs%n)+1;
	int q=((bs+mx-1)%n)+1;
	cout<<p<<" "<<q<<"\n";
	return 0;
}

