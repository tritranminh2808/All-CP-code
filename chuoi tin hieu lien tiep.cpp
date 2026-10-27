#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
int a[100005];

vector <int> b;
struct pl{
	int lf,rt,maxx;
};
pl st[4000005];
unordered_map<int, int> newv;
void nen(){
	for(int i=1;i<=n;i++) b.push_back(a[i]);
	sort(b.begin(),b.end());
	b.erase(unique(b.begin(),b.end()),b.end());
	for(int i=0;i<b.size();i++) newv[b[i]]=i+1;
	for(int i=1;i<=n;i++) a[i]=newv[a[i]];
//	for(int i=1;i<=n;i++) cout << a[i] << " ";
}
pl ghep(pl a,pl b, int lena, int lenb){
	pl c;
	if(a.lf==lena) c.lf=lena+b.lf;
	else c.lf=a.lf;
	if(b.rt==lenb) c.rt=lenb+a.rt;
	else c.rt=b.rt;
	c.maxx=max({a.maxx,b.maxx,a.rt+b.lf});
	return c;
}
void build(int id,int l,int r){
	if(l==r){
		st[id]={0,0,0};
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
}
void update(int id,int l ,int r, int u, int v){
	if(u<l||u>r) return;
	if(l==r){
		st[id]={v,v,v};
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,u,v);
	update(id*2+1,mid+1,r,u,v);
	st[id]=ghep(st[id*2],st[id*2+1],mid-l+1,r-mid);
}
pl find(int id, int l,int r, int trai, int phai){
	if(trai>r||phai<l) return {0,0,0};
	if(trai<=l&&phai>=r) return st[id];
	int mid=(l+r)/2;
	pl k1=find(id*2,l,mid,trai,phai),k2=find(id*2+1,mid+1,r,trai,phai);
	int len1=min(mid,phai)-max(l,trai)+1,len2=min(r,phai)-max(mid+1,trai)+1;
    return ghep(k1,k2,len1,len2);
}
int sech[1000005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	if(n<=1000&&q<=1000){
		multiset <int> s;
		for(int i=0;i<n;i++) {
			int x; cin >> x;
			s.insert(x);
		}
		while(q--){
			char c ; cin >> c;
			if(c=='+'){
				int x; cin >> x;
				s.insert(x);
			}
			else if(c=='-'){
				int x; cin >> x;
				auto it=s.find(x);
				if(it!=s.end()) s.erase(it);
//				for(auto i:s) cout << i << " ";
			}
			else{
				int u,k;
	            cin >> u >> k;
	            vector<int> v;
	            for(int x:s){
	                if(x<u) continue;
	                if(x>k) break;
	                v.push_back(x);
	            }
	            int sol=0;
	            if(!v.empty()){
	                int cur=1;
	                sol=1;
	                for(int i=1;i<v.size();i++){
	                    if(v[i]==v[i-1]+1) cur++;
	                	else if(v[i]==v[i-1]) continue;
						else if(v[i]-v[i-1]>1) cur=1;
	                    sol=max(sol,cur);
	                }
	            }
	            cout << sol << "\n";
			}
		}
		return 0;
	}
	build(1,1,1000000);
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		sech[a[i]]++;
		if(sech[a[i]]==1)update(1,1,1000000,a[i],1);
	}
	
	while(q--){
		char c; cin >> c;
		if(c=='+'){
			int x; cin >> x;
			sech[x]++;
			if(sech[x]==1) update(1,1,1000000,x,1);
		}
		else if(c=='-'){
			int x; cin >> x;
			sech[x]--;
			if(sech[x]==0) update(1,1,1000000,x,0);
		}
		else{
			int u,v; cin >> u >> v;
			cout << find(1,1,1000000,u,v).maxx << "\n";
		}
	}
//	nen();
	return 0;
}
