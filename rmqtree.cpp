#include <bits/stdc++.h>
using namespace std;
int st[18][100005];
int a[100005];
int n;
int res[100005];
void build(){
	for(int i=1;i<=n;i++) st[0][i]=i;
	for(int i=1;i<=17;i++){
		for(int j=1;j<=n;j++) {
			if(a[st[i-1][j]]<a[st[i-1][j+(1<<(i-1))]]) st[i][j]=st[i-1][j+(1<<(i-1))];
			else st[i][j]=st[i-1][j]; 
		}
	}
}
int query (int l, int r){
	int x=__lg(r-l+1);
	if(a[st[x][l]]>a[st[x][r-(1<<x)+1]]) return st[x][l];
	return st[x][r-(1<<x)+1];

}
//int sau=0;
void cook(int sau,int l, int r){
	if(l==r) {
		res[l]=sau;
		return ;
	}
	if(l<r)
	{
		int mid=query(l,r);
		res[mid]=sau;
		cook(sau+1,l,mid-1);
		cook(sau+1,mid+1,r);
	}
}
int main(){
	freopen("rmqtree.inp","r",stdin);
	freopen("rmqtree.out","w",stdout);
	 cin >> n;
	 for(int i=1;i<=n;i++) cin >> a[i];
	 build();
	cook(0,1,n);
	for(int i=1;i<=n;i++) cout << res[i] << " ";
	return 0;
}
