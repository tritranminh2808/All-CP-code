#include <bits/stdc++.h>
using namespace std;
int main(){
//	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int x,a,b,y,n;
	while(cin >> x){
		cin >> a >> y >> b >> n;
		if(a>b){
			swap(x,y);
			swap(a,b);
		}
//		cout << x << a << y << b<< n ;
		priority_queue<int,vector <int> , greater<int> > pq;
		for(int i=1;i<=min(n,x);i++) if(i<=n) pq.push(a);
		for(int i=n;i<=x;i++){
			int p=pq.top();
			pq.pop();
			p+=a;
			pq.push(p);
		}
		while(y--){
			int p=pq.top();
			pq.pop();
			p+=b;
			pq.push(p);
		}
		while(!pq.empty()){
			cout << pq.top() << " ";
			pq.pop();
		}
//		cout  << pq.top() << "\n";
	}
}
