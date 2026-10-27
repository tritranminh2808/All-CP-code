#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int gtri; int lazy;
};
struct pl{
	int w,d,v;
};
node st [400005];
int a[400005],n,b,m;
void build(int id, int l, int r){
	if(l==r){
		st[id].gtri=a[l];return;
	}
	int mid=(r+l)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id].gtri=max(st[id*2].gtri,st[id*2+1].gtri);
}
void push(int crr){
	st[crr*2].gtri+=st[crr].lazy;
	st[crr*2+1].gtri+=st[crr].lazy;
	st[crr*2].lazy+=st[crr].lazy;
	st[crr*2+1].lazy+=st[crr].lazy;
	st[crr].lazy=0;
}
void update(int crr, int l, int r, int lf, int rt, int val){
	if(l>rt||r<lf) return ;
	if(l>=lf&&r<=rt){
		st[crr].gtri+=val;
		st[crr].lazy+=val;
		return ;
	}
	push(crr);
	int mid=(l+r)/2;
	update(crr*2,l,mid,lf,rt,val);
	update(crr*2+1,mid+1,r,lf,rt,val);
	st[crr].gtri=max(st[crr*2].gtri,st[crr*2+1].gtri);
}
int get(int crr, int l, int r, int lf, int rt){
	if(lf>r||rt<l) return -1e18;
	if(lf<=l&&r<=rt) return st[crr].gtri;
	push(crr);
	int mid=(l+r)/2;
	return max(get(crr*2,l,mid,lf,rt),get(crr*2+1,mid+1,r,lf,rt));
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
}

