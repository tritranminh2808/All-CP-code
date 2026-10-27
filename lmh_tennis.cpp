#include <bits/stdc++.h>
using namespace std;
struct pl{
	int val,id;
};
pl a[100005];
bool cmp(pl x, pl y){
	return x.val>y.val;
}
vector <pair <int, int > > sol;
int pre[100005];
int main(){
	int n; cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> a[i].val;
		a[i].id=i;
	}
	priority_queue<pair <long long,int> > pq;
	for(int i=1;i<=n;i++) pq.push({a[i].val,a[i].id});
	while(!pq.empty()){
		pair <long long ,int> p=pq.top();
		pq.pop();
		vector <pair <long long ,int> > tmp;
		for(int i=0;i<p.first;i++){
			pair <int, int> p2=pq.top();
			pq.pop();
			sol.push_back({p.second,p2.second});
			p2.first--;
			if(p2.first==0) continue;
			tmp.push_back(p2);
		}
		for(auto i:tmp) pq.push(i);
	}
	for(auto i:sol) cout << i.first <<  " " << i.second << "\n";
	return 0;
}
