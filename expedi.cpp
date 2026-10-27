#include <bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(pair <int, int > a, pair <int ,int >  b){
    return a.first>b.first;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >>n ;
    int P=0,L=0;
    vector <pair <int, int > > a(n+1);
    for(int i=1;i<=n;i++) cin >> a[i].first >> a[i].second;
    cin >> P >> L;
    int sol=0;
    sort(a.begin()+1,a.end(),cmp);
    priority_queue<pair <int, int > > pq;
    for(int i=1;i<=n;i++){
        int kc=P-a[i].first;
        // cout << P << " " << L << endl;
        if(kc>L) {
            while(!pq.empty()&&L<kc){
                L+=pq.top().first;
                // P=pq.top().second;
                pq.pop();
                sol++;
            }
            if(L<kc){
                cout << -1;
                return 0;
            }
        }
        L-=kc;
        P=a[i].first;
        pq.push({a[i].second,a[i].first});
    }
    if(L<a[n].first){
        while(!pq.empty()&&L<a[n].first){
            L+=pq.top().first;
            pq.pop();
            sol++;
         }
        if(L<a[n].first){
            cout << -1;
            return 0;
        }
    }
    cout << sol; 
}
