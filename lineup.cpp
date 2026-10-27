#include <bits/stdc++.h>
using namespace std;
int sol[100005];
int main(){
//	freopen("lineup.inp","r",stdin);
//	freopen("lineup.out","w",stdout);
	vector <int> a;
	int n; cin >> n;
	for(int i=0;i<n;i++){
		int k; cin >> k;
		a.push_back(k);
	}
	stack <int> st;
	for(int i=0;i<n;i++){
		if(st.empty()){
			st.push(i);
			sol[i]=0;
			continue;
		}
		while(!st.empty()&&a[i]>=a[st.top()]) st.pop();
		sol[i]=st.empty()? 0 : (st.top()+1);
		st.push(i);
	}
	for(int i=0;i<n;i++) cout << sol[i] << " ";
}
