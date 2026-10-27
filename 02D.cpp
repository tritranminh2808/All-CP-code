#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int p=1e6+5;
//int st[21][1000005];
long long a[p];
int l[p],r[p];
int cnt=0;
bool cmp(pair <int, int > a, pair <int, int > b){
	if(a.first==b.first) return a.second >b.second;
	return a.first <b.first;
}
signed main(){
	int n,k; cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	stack <int> st;
	for(int i=1;i<=n;i++){
		while(!st.empty()&&a[st.top()]<=a[i]) st.pop();
		if(!st.empty()) l[i]=st.top();
		else l[i]=0;
		st.push(i);
	}
	while(!st.empty()) st.pop();
	for(int i=n;i>=1;i--){
		while(!st.empty()&&a[st.top()]<=a[i]) st.pop();
		if(!st.empty()) r[i]=st.top();
		else r[i]=n+1;
		st.push(i);
	}
	vector <pair <int, int > > tm;
	for(int i=1;i<=n;i++){
		int lf=max(i-k+1,l[i]),rt = min(i+k-1,r[i]);
		lf=max(lf,(int)1);
		rt=min(rt,n);
		if(r[i]-l[i]-1>=k)  tm.push_back({lf,rt});
	}
	cout << tm.size() << " ";
	if(k==1){
		cout << n; return 0;
	}
	sort(tm.begin(),tm.end(),cmp);
	
	int sol=1;
	int cr=tm[0].second,ind=1;
	vector <pair <int , int > > tx;
	tx.push_back({tm[0].first,tm[0].second});
	for(int i=1;i<tm.size();i++){
		if(tm[i].first>tx[tx.size()-1].first) tx.push_back({tm[i].first , tm[i].second});
	}
	for(auto i : tx) cout << i.first << " " << i.second << "\n";
	priority_queue<int> pq;
	while(cr!=n){
//		cout << cr << endl;
		if(tx[ind].first<=cr) {
			pq.push(tx[ind].second);
			ind++;
		}
		else{
			cr=pq.top();
			sol++;
		}
	}
	cout << sol;
//	for(auto i : tm) cout << i.first << " " << i.second << "\n";
	return 0;
}

