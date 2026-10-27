#include <bits/stdc++.h>
using namespace std;
const int p=1e7+5;
long long sol=-1111,sol2=-1111,l[p],r[p],l2[p],r2[p];
int a[p];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    freopen("rect.inp","r",stdin);
    freopen("rect.out","w",stdout);
	int n,m;cin >> n>>m;
	
	for(int i=0;i<m;i++)cin >> a[i];
	stack<int> st;
	for(int i=0;i<m;i++){
		while(!st.empty()&&a[st.top()]>=a[i]) st.pop();
		if(st.empty())l[i]=-1;
		else l[i]=st.top();
		 st.push(i);
	}
	stack<int> st1;
	for(int i=m-1;i>=0;i--){
		while(!st1.empty()&&a[st1.top()]>=a[i]) st1.pop();
		if(st1.empty())r[i]=m;
		else r[i]=st1.top();
		st1.push(i);
	}
	for(int i=0;i<m;i++){
		sol=max(sol,a[i]*(r[i]-l[i]-1));
	}
	for(int i=0;i<m;i++) a[i]=n-a[i];
	stack<int>st2;stack<int>st3;
	for(int i=0;i<m;i++){
		while(!st2.empty()&&a[st2.top()]>=a[i]) st2.pop();
		if(st2.empty())l2[i]=-1;
		else l2[i]=st2.top();
		 st2.push(i);
	}
	
	for(int i=m-1;i>=0;i--){
		while(!st3.empty()&&a[st3.top()]>=a[i]) st3.pop();
		if(st3.empty())r2[i]=m;
		else r2[i]=st3.top();
		st3.push(i);
	}
	for(int i=0;i<m;i++){
		sol2=max(sol2,a[i]*(r2[i]-l2[i]-1));
	}
	cout << max(sol,sol2);
	return 0;
}
