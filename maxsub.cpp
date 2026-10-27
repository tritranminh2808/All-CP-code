#include<bits/stdc++.h>
using namespace std;
using ll=long long;

struct Fm{
	int n;
	vector<int>t;
	Fm(int n):n(n),t(n+1,-1){}
	void u(int i,int v){
		for(int x=i;x<=n;x+=x&-x)
			t[x]=max(t[x],v);
	}
	int q(int i){
		int r=-1;
		for(int x=i;x>0;x-=x&-x)
			r=max(r,t[x]);
		return r;
	}
};

struct Fn{
	int n;
	vector<int>t;
	Fn(int n):n(n),t(n+1,1e9){}
	void u(int i,int v){
		for(int x=i;x<=n;x+=x&-x)
			t[x]=min(t[x],v);
	}
	int q(int i){
		int r=1e9;
		for(int x=i;x>0;x-=x&-x)
			r=min(r,t[x]);
		return r;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;
	vector<ll>a(n+1),p(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]=p[i-1]+a[i];
	}

	vector<ll>v=p;
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	int m=v.size();
	vector<int>rk(n+1);
	for(int i=0;i<=n;i++)
		rk[i]=lower_bound(v.begin(),v.end(),p[i])-v.begin()+1;

	vector<int>last(m+1,-1),fir(m+1,1e9);
	for(int i=0;i<=n;i++){
		int k=rk[i];
		last[k]=max(last[k],i);
		fir[k]=min(fir[k],i);
	}

	Fm f1(m);
	Fn f2(m);
	for(int k=1;k<=m;k++){
		f1.u(m-k+1,last[k]);
		f2.u(k,fir[k]);
	}

	vector<int>R(n+1),L(n+1);
	for(int i=0;i<n;i++){
		int j=f1.q(m-rk[i]+1);
		R[i]=j>i?j:-1;
	}
	for(int j=1;j<=n;j++){
		int t=f2.q(rk[j]);
		L[j]=t<j?t:-1;
	}

	ll B=0;
	for(int i=0;i<n;i++)
		if(R[i]!=-1&&L[R[i]]==i)
			B++;

	ll S=0;
	vector<int>bit(m+1);
	auto upd=[&](int i){
		for(int x=i;x<=m;x+=x&-x)
			bit[x]++;
	};
	auto qry=[&](int i){
		int s=0;
		for(int x=i;x>0;x-=x&-x)
			s+=bit[x];
		return s;
	};
	upd(rk[0]);
	for(int i=1;i<=n;i++){
		S+=qry(rk[i]);
		upd(rk[i]);
	}

	cout<<S-B;
	return 0;
}

