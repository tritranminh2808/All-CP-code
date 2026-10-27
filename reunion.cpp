#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    int n,a,b; cin >> n >> a >> b;
    vector <int> L,R, sl;
    for(int i=0;i<n;i++){
		char c;
		int x;
		cin >> c>>x;
		if(c=='L') L.push_back(x);
		else R.push_back(x);
		sl.push_back(x);
	}
	sort(L.begin(),L.end());
	sort(R.begin(),R.end());
	sort(sl.begin(),sl.end());
	int maxcnt=0, res=0;
	if(a<=100005&&b<=1000005){
		for(int k=a;k<=b;k++){
			if(k<a||k>b) continue;
			int cnt=0;
			auto it=lower_bound(L.begin(),L.end(),k) - L.begin()+1;
			cnt+=L.size()- it+1;
			auto it2=upper_bound(R.begin(),R.end(),k) -R.begin();
			cnt+=it2;
	//		cout << k << " " << cnt << "\n";
			if(cnt>maxcnt){
				maxcnt=cnt;
				res=k;
			}
		}
		cout << res;
		return 0;
	}
	for(auto k : sl){
		if(k<a||k>b) continue;
		int cnt=0;
		auto it=lower_bound(L.begin(),L.end(),k) - L.begin()+1;
		cnt+=L.size()- it+1;
		auto it2=upper_bound(R.begin(),R.end(),k) -R.begin();
		cnt+=it2;
//		cout << k << " " << cnt << "\n";
		if(cnt>maxcnt){
			maxcnt=cnt;
			res=k;
		}
	}
	cout << res;
    return 0;
}

