#include <bits/stdc++.h>
using namespace std;
int sech[100005];
int main(){
	for(int i=1;i<=100000;i++){
		sech[i]=sech[i-1];
		int s=0;
		for(int j=1;j<=sqrt(i);j++){
			if(i%j==0) {
				s+=j;
				s+=i/j;
			} 
		}
		int k=sqrt(i);
		if(k*k==i) s-=k;
		s-=i;
		if(s>i) sech[i]++;
	}
	int l,r; cin >>l>> r;
	cout << sech[r]-sech[l-1];
	return 0;
}
