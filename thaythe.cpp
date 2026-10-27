#include <bits/stdc++.h>
//#define int long long
using namespace std;
int n,p,a,b,r;
int d[1000005];
void cook(){
	queue<int> q;
//	d[n]=0;
	q.push(n);
	while(!q.empty()){
		int c=q.front();
		q.pop();
		if(c==r) {
			cout << d[c];
			return ;
		}
		if(d[(a+c)%p]==0) {
			d[(a+c)%p]=(c==n? 0: d[c])+1;
			q.emplace((c+a)%p);	
		}
		if(d[(b+c)%p]==0) {
			d[(b+c)%p]=(c==n? 0: d[c])+1;	
			q.emplace((c+b)%p);
		}
		if(d[(a+b+c)%p]==0) {
			d[(a+b+c)%p]=(c==n? 0: d[c])+1;
			q.emplace((c+a+b)%p);	
		}
	}
	cout << -1;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> p >> a >> b >> r;
	cook();
	return 0;
}
