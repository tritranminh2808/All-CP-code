#include <bits/stdc++.h>
using namespace std;
struct pl{
	int l,r,k,id;
};
int a[30005],n,q;
unordered_map<int,int> newv;
vector <int> b;
void nen(){
	for(int i=0;i<n;i++) b.push_back(a[i]);
	sort(b.begin(),b.end());
	b.erase(unique(b.begin(),b.end()),b.end());
	for(int i=0;i<b.size();i++) newv[b[i]]=i+1;
	for(int i=0;i<n;i++) a[i]=newv[a[i]];
}	
int st[180][30005];
int res[200005];
void update (int ss,int i, int v){
    for(;i<=b.size();i+=i&-i) st[ss][i]+=v;
}
int find(int ss,int i){
    int s=0;
    for(;i>0;i-=i&-i) s+=st[ss][i];
    return s;
}
bool cmp(pl a, pl b){
    return a.l<b.l;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	nen();
//	for(int i=0;i<n;i++) cout << a[i] << " ";
	cin >> q;
    vector <pl> truyvan;
	for(int i=0;i<q;i++){
		int l,r,k;
		cin >> l >> r >> k;
		l--;
		r--;
		int idx=lower_bound(b.begin(), b.end(), k + 1) - b.begin()+1;
		k=idx;
		truyvan.push_back({l,r,k,i});
    }
    sort(truyvan.begin(),truyvan.end(),cmp);
    int lst=1;
    for(int i=0;i<q;i++){
        for(int x=lst;x<=)
    }
}

