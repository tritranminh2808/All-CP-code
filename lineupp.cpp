#include <bits/stdc++.h>
using namespace std;
long long a[200005];
long long sol=0;
int main(){
	int n,k; cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	priority_queue<int> pq;
	for(int i=1;i<=n;i++) pq.push(a[i]);
	while (k--){
		int x=pq.top();
		sol+=x;
		x--;
		pq.pop();
		pq.push(x);
	}
	cout << sol;
	return 0;
}
