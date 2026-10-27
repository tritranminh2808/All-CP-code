#include <bits/stdc++.h>
using namespace std;
int ST[(const int ) 8e5+5];
void update(int id,int l, int r, int lf, int rt){
	if(lf>r||rt<l) return;
	if(lf<=l&&rt>=r){
		ST[id]+=1;
		return;
	}
	int mid=(l+r)/2;
	update(2*id,l,mid,lf,rt);
	update(2*id+1,mid+1,r,lf,rt);
	ST[id]=ST[id*2]+ST[id*2+1];
}
int find(int id,int l, int r, int u){
	if(l>u||r<u) return 0;
	if(l==r) return ST[id];
	int mid=(l+r)/2;
	return find(2*id,l,mid,u)+find(2*id+1,mid+1,r,u);
}
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector <int> v(n);
		for(int i=0;i<n;++i) cin >> v[i];
		int l=0,r=n-1;
		int dao=0;
		int re=0;
		while(l<=r){
			cout << l << " " << r << endl;
			if(v[r]+dao==v[l]+dao&&v[r]+dao==1) break;
			while(v[r]+dao==0) {
				r--;
				re++;
			}
			while(v[l]+dao==0){
				l++;
				dao++;
				dao%=2;
				re++;
			}
		}
		if(re>=n) cout <<"YES";
		else cout << "NO";
		cout <<"\n";
	}
	return 0;
}
