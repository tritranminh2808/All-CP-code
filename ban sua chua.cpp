#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >>n ;
    vector <int> a(n),b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    int cur=0;
    vector <int> sol;
    int sa=0,sb=0;
    priority_queue<pair <int ,int > > pq;
    for(int i=0;i<n;i++){
        sa+=a[i];
        sb+=b[i];
        pq.push({b[i],i});
        if(sa<sb){
            sb-=pq.top().first;
            pq.pop();
        }
    }
    while(!pq.empty()){
        sol.push_back(pq.top().second+1);
        pq.pop();
    }
    sort(sol.begin(),sol.end());
    cout << sol.size() << "\n";
    for(auto i:sol) cout << i << " ";
}
