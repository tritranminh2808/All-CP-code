#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[2505];
int sol=0;
bool vst[100005];
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int c1=3,c2=2,c3=2;
//	int maxx=15;
	set<int> st;
	st.insert(6);
	st.insert(10);
	st.insert(15);
	while(st.size()<n){
		int minn=min({c1*6,c2*10,c3*15});
		if(c1*6==minn) c1++;
		else if(c2*10==minn)c2++;
		else if(c3*15==minn)c3++;
		st.insert(minn);
	}
	
	// for(int i=1;i<=n;i++) st.insert(a[i]);
	for(auto i:st) cout << i << " ";
	// cout << st.size();
	// for(int i=1;i<=n;i++) cout << a[i] <<  " " ;
}
