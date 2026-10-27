#include <bits/stdc++.h>
using namespace std;
bool cmp(pair <int,int> a, pair <int, int > b){
	if(a.second==b.second) return a.first <b.first;
	return a.second <b.second;
}
int main(){
	int s,n; cin >> s >> n;
	vector <pair <int , int > > v(n);
	for(int i=0;i<n;i++) cin >> v[i].first >> v[i].second;
	sort(v.begin(),v.end(),cmp);
	priority_queue<int, vector <int> , greater <int> > pq;
	int res=0;
	for(int i=0;i<n;i++){
		if(!pq.empty()&&v[i].first>=pq.top()){
			pq.pop();
			pq.push(v[i].second);
			res++;
		}
		else if(pq.size()<s) {
			pq.push(v[i].second);
			res++;
		}
	}
	cout << res;
	return 0;
}

