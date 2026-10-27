#include <bits/stdc++.h>
#define int long long
using namespace std;
int chuyendoi(string a){
	int d=0;
	for(int i=0;i<a.length();i++) {
		d*=10;
		d+=(a[i]-'0');
	}
	return d;
}
signed main(){
	freopen("pq.inp","r",stdin);
	freopen("pq.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	priority_queue<int> pq;
	int n; cin >> n ; 
	while(n--){
		string str; cin >> str;
		if(str=="-"){
			if(!pq.empty()){
				int maxx=pq.top();
				while(!pq.empty()&&pq.top()==maxx) pq.pop();
			}
		}
		else{
			string s;
			for(int i=1;i<str.length();i++) s+=str[i];
			int a=chuyendoi(s);
			pq.push(a);
		}	
	}
	set <int, greater <int> > st;
	while(!pq.empty()){
		st.insert(pq.top());
		pq.pop();
	}
	cout << st.size() << "\n";
	for(auto i: st) cout << i << " ";
}

