#include <bits/stdc++.h>
#define int ll
using ll=unsigned long long;
using namespace std;
vector <int> po;
//int po[20]={0,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000,100000000000,1000000000000,10000000000000,100000000000000,1000000000000000,1000000000000000000,10000000000000000000,100000000000000000000};
int sochuso(int a){
	int cnt=0;
	while(a!=0) {
		cnt++;
		a/=10;
	}
	return cnt;
}
void build(){
	po.push_back(0);
	po.push_back(10);
	for(int i=2;i<=18;i++){
		po.push_back(po[po.size()-1]*10);
	}
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	build();
	int q;cin>> q;
	while(q--){
		int a;
		cin >> a;
		if(a<10){
			cout << a << "\n";
			continue;
		}
		vector <int> A;
		int b=a;
		while(b!=0) {
			A.push_back(b%10);
			b/=10;
		}
		reverse(A.begin(),A.end());
		int scs=sochuso(a);
		int sol=po[scs-1]-1;
		for(int i=1;i<scs;i++){
			if(scs%i==0){
				vector <int> v;
				int cur=0;
				for(int j=0;j<scs;j++){
					if(j%i==0&&j>0){
						v.push_back(cur);
						cur=0;
					}
					cur*=10;
					cur+=A[j];
				}
				v.push_back(cur);
				bool check=0;
				int loz=po[i];
				for(int ii=0;ii<v.size()-1;ii++){
					if(v[ii]<v[ii+1]){
						int x=0;
						for(int k=0;k<scs/i;k++) {
							x*=loz;
							x+=v[ii];
//							cout << x << "\n";
						}
						sol=max(sol,x);
						check=1;
						break;
						
					}
					else if(v[ii]>v[ii+1]){
						int x=0;
						for(int k=0;k<scs/i;k++) {
							x*=loz;
							x+=v[ii]-1;
						}
						sol=max(sol,x);
						check=1;
						break;
					}
				}
				if(!check){
					int x=0;
					for(int k=0;k<scs/i;k++) {
						x*=pow(10,i);
						x+=v[0];
					}
					sol=max(sol,x);
				}
			}
		}
		cout << sol << "\n";
	}
}

