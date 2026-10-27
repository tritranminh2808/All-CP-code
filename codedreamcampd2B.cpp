#include <bits/stdc++.h>
#define int long long
using namespace std;
int n; 
pair <int, int > a[200005];
bool cmp(pair <int,int > x, pair <int ,int> y){
	if(x.first==y.first) return x.second>y.second;
	return x.first<y.first;
}
int sol=0,cnt=0;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i].first;
	for(int i=1;i<=n;i++) cin >> a[i].second;
	sort(a+1,a+n+1,cmp);
	priority_queue<int ,vector <int> , greater<int> > pq;
	for(int i=1;i<=n;i++){
//		cout << sol << "\n";
		if(pq.empty()){
			pq.push(a[i].second);
			sol+=a[i].second;
			cnt++;
			continue;
		}
		if(a[i].second>pq.top()&&cnt>=a[i].first){
			sol-=pq.top();
			sol+=a[i].second;
			pq.pop();
			pq.push(a[i].second);
//			cnt++;
		}
		else if(cnt<a[i].first){
			pq.push(a[i].second);
			sol+=a[i].second;
			cnt++;
		}
	}
	cout << sol;
	return 0;
}
