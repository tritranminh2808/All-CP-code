#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005],l[1000005],r[1000005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k; cin>> n>>m>>k;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	priority_queue<int, vector <int> ,greater<int> > pq;
	int sol=0;
	for(int i=1;i<=n;i++){
		if(pq.size()<k&&m>=a[i]/2){
			m-=a[i]/2;
			pq.push(a[i]);
			sol++;
		}
		else{
			if(m<a[i]){
				if(!pq.empty()&&m-pq.top()/2>=a[i]/2){
					m=m-pq.top()/2-a[i]/2;
					pq.pop();
					pq.push(a[i]);
					sol++;
				}
			}
			else {
				m-=a[i];
				sol++;
			}
		}
	}
	cout << sol;
	return 0;
}
