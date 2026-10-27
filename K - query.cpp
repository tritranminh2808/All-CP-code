#include <bits/stdc++.h>
using namespace std;
int sqr=0;
struct pl{
	int l,r,k,id;
};
pl f[200005];
int a[30005],n,q;
int cnt[180][30005];
int res[200005];
unordered_map<int,int> newv;
vector <int> b;
void nen(){
	for(int i=0;i<n;i++) b.push_back(a[i]);
	sort(b.begin(),b.end());
	b.erase(unique(b.begin(),b.end()),b.end());
	for(int i=0;i<b.size();i++) newv[b[i]]=i;
	for(int i=0;i<n;i++) a[i]=newv[a[i]];
}	
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	sqr=sqrt(n);
	for(int i=0;i<n;i++) cin >> a[i];
	nen();
//	for(int i=0;i<n;i++) cout << a[i] << " ";
	cin >> q;
	
	for(int i=0;i<n;i++){
		cnt[i/sqr][a[i]]++;
	}
	for(int i=0;i<=sqr;i++){
		for(int j=0;j<=n;j++){
			if(j>0) cnt[i][j]+=cnt[i][j-1];
//			cout << i << " " << j << " " << cnt[i][j] << "\n";
		}
	}
	for(int i=0;i<q;i++){
		int l,r,k;
		cin >> l >> r >> k;
		l--;
		r--;
		int idx=lower_bound(b.begin(), b.end(), k + 1) - b.begin();
		k=idx;
			
		int sol=0;
		if(l/sqr==r/sqr){
			for(int i=l;i<=r;i++) if(a[i]>=k) sol++;
			cout << sol << "\n";
			continue;
		}
	
		for(int i=l;i<min((l/sqr+1)*sqr,r+1);i++) if(a[i]>=k) sol++;
//		cout << sol << " ";
		int xx=r/sqr;
//		cout << xx;
		for(int i=max(xx*sqr,l);i<=r;i++) if(a[i]>=k) sol++;
//		cout << sol << "\n";
		for(int i=l/sqr+1;i<xx;i++) sol+=cnt[i][b.size()-1]-cnt[i][k-1];
		cout << sol << "\n";
	}
}

