#include <bits/stdc++.h>
using namespace std;
bool cmp(pair <int, int > a, pair <int, int > b){
	if(a.first==b.first) return a.second> b.second;
	return a.first < b.first;
}
int main(){
	int n,k,A,B; cin >> n >> k >> A >> B;
	vector <pair <int, int > > v(n);
	for(int i=0;i<n;++i) cin >> v[i].first >> v[i].second;
	sort(v.begin(),v.end(),cmp);
	priority_queue<int, vector <int> , greater <int> > pq;
	int ind=0;
	int sol=0;
	for(int i=A;i<=B;i++){
//		cout << i << " " << pq.size() <<" " << sol << " " << ind <<  endl;	
		while(pq.size()<k){
			if(ind>=n) {
				cout <<-1;
				return 0;
			}
			if(v[ind].first<=i&&v[ind].second>i){
				sol++;
				pq.push(v[ind].second);
			}
			ind++;
		}
		if(!pq.empty()&&pq.top()==B) break;
		i=pq.top();
		while(!pq.empty()&&pq.top()==i) pq.pop();
		i--;
	}
	cout << sol;
	return 0;
}
