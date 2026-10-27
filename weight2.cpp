#include <bits/stdc++.h>
using namespace std;
const int p=1e5+1;
int l[p],r[p],l2[p],r2[p],a[p];
long long sol=0;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int m;cin >> m;
	for(int i=1;i<=m;i++)cin >> a[i];
	stack<int> st;
	for(int i=1;i<=m;i++){
		while(!st.empty()&&a[st.top()]>=a[i]) st.pop();
		if(st.empty())l[i]=0;
		else l[i]=st.top();
		 st.push(i);
	}
	stack<int> st1;
	for(int i=m;i>=1;i--){
		while(!st1.empty()&&a[st1.top()]>a[i]) st1.pop();
		if(st1.empty())r[i]=m+1;
		else r[i]=st1.top();
		st1.push(i);
	}
	for(int i=1;i<=m;i++){
		sol-=(long long)(i-l[i])*(r[i]-i)*a[i];
		//cout << l[i] <<" " << r[i] << endl;
		//cout << l[i] << " " << r[i] << endl;
	}
	//cout << sol;
	for(int i=1;i<=m;i++) a[i]=-a[i];
	stack<int> st2;
	for(int i=1;i<=m;i++){
		while(!st2.empty()&&a[st2.top()]>=a[i]) st2.pop();
		if(st2.empty())l2[i]=0;
		else l2[i]=st2.top();
		 st2.push(i);
	}
	stack<int> st3;
	for(int i=m;i>=1;i--){
		while(!st3.empty()&&a[st3.top()]>a[i]) st3.pop();
		if(st3.empty())r2[i]=m+1;
		else r2[i]=st3.top();
		st3.push(i);
	}
	for(int i=1;i<=m;i++){
		sol-=(long long)(i-l2[i])*(r2[i]-i)*a[i];
	}
	cout << sol;
	return 0;
}
