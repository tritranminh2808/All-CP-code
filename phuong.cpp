#include <bits/stdc++.h>
using namespace std;
int st[17][5000005];
int a[5000005];
int n;
void build(){
	for(int i=1;i<=n;++i) st[0][i]=a[i];
	for(int i=1;i<17;i++){
		for(int j=1;j<=n;j++) st[i][j]=__gcd(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	}
}
int find(int l,int r){
	int sech=__lg(r-l+1);
	return __gcd(st[sech][l],st[sech][r-(1<<sech)+1]);
}
unordered_map<int,vector <int> > mp;
bool check(int g, int l, int r){
	int lf=0,rt=mp[g].size()-1;
	while(lf<=rt){
		int mid=(lf+rt)/2;
		if(mp[g][mid]>=l&&mp[g][mid]<=r) return true;
		else if(mp[g][mid]<l) lf=mid+1;
		else if(mp[g][mid]>r) rt=mid-1;
	}
	return false;
}
int main(){
	cin >> n;
	
	for(int i=1;i<=n;i++){
		 cin >> a[i];
		 mp[a[i]].push_back(i);
	}
	build();
	int l=1,r=n;
	int sol=0;
//	if(check(6,2,5)) cout << 1111;
	while(l<=r){
		int mid=(l+r)/2;
		bool ch=0;
		for(int i=1;i<=n-mid+1;i++){
			int g=find(i,i+mid-1);
			if(check(g,i,i+mid-1)) {
				ch=1;
				break;
			}
		}
		if(ch==1) {
			l=mid+1;
			sol=mid;
		}
		else r=mid-1;
	}
//	cout << sol-1;
	vector <int> res;
	for(int i=1;i<=n-sol+1;i++){
		if(check(find(i,i+sol-1),i,i+sol-1)) res.push_back(i);
	}
	cout << res.size() << " " << sol-1<< "\n";
	for(auto i : res) cout<< i << " ";
	return 0;
}
