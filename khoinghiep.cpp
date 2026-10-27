#include <bits/stdc++.h>
using namespace std;
bool sech[100005];
int res=0;
vector <int> ht[100004];
bool cmp(pair <int,int > a, pair <int, int > b){
	if(a.first==b.first) return a.second > b.second;
	return a.first < b.first;
}
int main(){
	int n; cin >> n;
	vector <pair <int, int > > v;
	for(int i =0; i<n;i++){
		int l,r; cin >> l >> r;
		v.push_back({l,r});
	}
	sort(v.begin(),v.end(),cmp);
	int res=0;
	priority_queue< int , vector <int> , greater<int> > pq; 
	int memaybeo=0;
	for(int i=n-1;i>=0;i--){
		int cc=i;
		pq.push(v[i].second);
		if(cc+memaybeo>=v[i].first) continue;
		int x=0;
		while(!pq.empty()&&cc+memaybeo<v[i].first){
			res+=pq.top();
			pq.pop();
			memaybeo++;
		}
	}
	cout << res;
	return 0;
}

