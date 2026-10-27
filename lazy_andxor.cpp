#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int mask[31];
	int lazy_or, lazy_and;
};
struct pl{
	int w,d,v;
};
node st [400005];
int a[400005],n,b,m;
void build(int id, int l, int r){
    st[id].lazy_and=(1<<21)-1;
	if(l==r){
		for (int i=0;i<21;i++) st[id].mask[i]=(a[l]>>i)&1;
        return;
	}
	int mid=(r+l)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	for(int i=0;i<21;i++) st[id].mask[i]=st[id*2].mask[i]+st[id*2+1].mask[i];
}
void push_and(int id, int m){
    for(int i=0;i<21;i++) if(!(m>>i&1)) st[id].mask[i]=0;
    st[id].lazy_and&=m;
    st[id].lazy_or&=m;
}
void push_or(int id, int l, int r,int m){
    for(int i=0;i<21;i++) if(m>>i&1) st[id].mask[i]=r-l+1-st[id].mask[i];
    st[id].lazy_or^=m;
}
void push(int id, int l ,int r){
    int maxx=(1<<21)-1;
    push_and(id*2,st[id].lazy_and);
    push_and(id*2+1,st[id].lazy_and);
    st[id].lazy_and=maxx;
    int mid=(l+r)/2;
    push_or(id*2,l,mid,st[id].lazy_or);
    push_or(id*2+1,mid+1,r,st[id].lazy_or);
    st[id].lazy_or=0;
    
}
void update_xor(int crr, int l, int r, int lf, int rt, int val){
	if(l>rt||r<lf) return ;
	if(l>=lf&&r<=rt){
		push_or(crr,l,r,val);
		return ;
	}
	push(crr,l,r);
	int mid=(l+r)/2;
	update_xor(crr*2,l,mid,lf,rt,val);
	update_xor(crr*2+1,mid+1,r,lf,rt,val);
	for(int i=0;i<21;i++) st[crr].mask[i]=st[crr*2].mask[i]+st[crr*2+1].mask[i];
}
void update_and(int crr, int l, int r, int lf, int rt, int val){
	if(l>rt||r<lf) return ;
	if(l>=lf&&r<=rt){
		push_and(crr,val);
		return ;
	}
	push(crr,l,r);
	int mid=(l+r)/2;
	update_and(crr*2,l,mid,lf,rt,val);
	update_and(crr*2+1,mid+1,r,lf,rt,val);
	for(int i=0;i<21;i++) st[crr].mask[i]=st[crr*2].mask[i]+st[crr*2+1].mask[i];
}
int get(int crr, int l, int r, int lf, int rt){
	if(lf>r||rt<l) return 0;
	if(lf<=l&&r<=rt) {
        int sol=0;
        for(int i=0;i<21;i++) sol+=st[crr].mask[i]<<i;
        return sol;
    }
	push(crr,l,r);
	int mid=(l+r)/2;
	return get(crr*2,l,mid,lf,rt)+get(crr*2+1,mid+1,r,lf,rt);
}
void cok_chay(){
    int q; cin >> q;
    while(q--){
        int cc;
        cin >> cc;
        if(cc==1){
            int l,r; cin >> l>> r;
            int sol=0;
            for(int i=l;i<=r;i++) sol+=a[i];
            cout << sol << "\n";
        }
        else if(cc==2){
            int l,r,x; cin >> l >> r >> x;
            for(int i=l;i<=r;i++) a[i]&=x;
        }
        else{
            int l,r,x; cin >> l >> r >> x;
            for(int i=l;i<=r;i++) a[i]^=x;
        }
    }
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
    
    for(int i=1;i<=n;i++) cin >> a[i];
    if(n<=2000){
        cok_chay();
        return 0;
    }
    build(1,1,n);
    int q; cin >> q;
    while(q--){
        int cc;
        cin >> cc;
        if(cc==1){
            int l,r; cin >> l>> r;
            // for(int i=l;i<=r;i++) cout << get(1,1,n,i,i) << " ";
            cout << get(1,1,n,l,r) << "\n";
        }
        else if(cc==2){
            int l,r,x; cin >> l >> r >> x;
            update_and(1,1,n,l,r,x);
        }
        else{
            int l,r,x; cin >> l >> r >> x;
            update_xor(1,1,n,l,r,x);
        }
    }
}

